#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
#include"EXTI2_inter.h"
#include"EXTI2_Config.h"
#include"EXTI2_reg.h"
#define nul    0


volatile void ((*_pf)(void))= nul;
ErrorStatus EXTI2_enumInit(void)
{
	ErrorStatus error=ES_NOK;
 #if 	SENSE_MODE2  == FALLING
        CLR_BIT(MCUCSR,6);

 #elif 	SENSE_MODE2  ==  RISING
        SET_BIT(MCUCSR,6);
#endif
 error=ES_OK;
 return error;
}
ErrorStatus EXTI2_enumEnable (void)
{
	ErrorStatus error=ES_NOK;
	SET_BIT(GICR,5);
	return error;
}
ErrorStatus EXTI2_enumDisable (void)
{
	ErrorStatus error=ES_NOK;
	CLR_BIT(GICR,5);
	return error;
}
void EXTI2_enumSetCallBack (void(*x)(void))
{
	_pf=x;
}

void __vector_3()__attribute__((signal,used));
void __vector_3()
{
	_pf();
}
