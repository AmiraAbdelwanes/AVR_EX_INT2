#include<util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
/***********************DIO*******************/
#include"DIO_register.h"
#include"DIO_interface.h"
/*********************EXT_INT_2*******************/
#include"EXTI2_Reg.h"
#include"EXTI2_Config.h"
#include"EXTI2_Inter.h"

void EXT_ISRINT_2 (void);



void main ()
{
	DIO_enumSetPinDirection( DIO_U8_PORT_B ,DIO_U8_PIN2,DIO_U8_INPUT );//INT2_Signl
	DIO_enumSetPinValue    ( DIO_U8_PORT_B ,DIO_U8_PIN2,DIO_U8_HIGH  );

	DIO_enumSetPinDirection( DIO_U8_PORT_B ,DIO_U8_PIN5,DIO_U8_OUTPUT);//INT1_LED Indicator

	DIO_enumSetPinDirection( DIO_U8_PORT_A ,DIO_U8_PIN7,DIO_U8_OUTPUT);//Main_LED Indicator

	EXTI2_enumInit();

	//PIE enable
	EXTI2_enumEnable ();
	EXTI2_enumSetCallBack(EXT_ISRINT_2);
	//ENABLE GIF
	SET_BIT(SREG,7);



	while (1)
	{
		DIO_enumSetPinValue( DIO_U8_PORT_A ,DIO_U8_PIN7,DIO_U8_HIGH  );
		_delay_ms(1000);
		DIO_enumSetPinValue( DIO_U8_PORT_A ,DIO_U8_PIN7,DIO_U8_LOW   );
		_delay_ms(1000);
	}


}


void EXT_ISRINT_2 (void) // pass num of interrupt from vector table to isr
	{
		DIO_enumSetPinValue( DIO_U8_PORT_B,DIO_U8_PIN5,DIO_U8_HIGH   );
		_delay_ms(1000);
		DIO_enumSetPinValue( DIO_U8_PORT_B,DIO_U8_PIN5,DIO_U8_LOW    );
		_delay_ms(1000);
	}


