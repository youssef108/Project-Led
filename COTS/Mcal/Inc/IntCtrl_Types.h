/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
Reset=1,NMI=2,Hard_Fault=3,Memory_Management=4,Bus_Fault,Usage_Fault,SVCall=11,Debug_Moniter,GPIO_PORTA=16,GPIO_PORTB,GPIO_PORTC,GPIO_PORTD,GPIO_PORTE,
UART0,
UART1,
SSI0,
I2C0,
PWM0_Fault, 
PWM0_Generator0,PWM0_Generator1,
PWM0_Generator2,
QEI0,
ADC0_Sequence0,
ADC0_Sequence1,
ADC0_Sequence2,ADC0_Sequence3,
Watchdog_Timers_0_1,
Timer_0A,
Timer_0B,
Timer_1A,
Timer_1B,
Timer_2A,
Timer_2B,
Analog_Comparator0,Analog_Comparator_1,System_Control=44,Flash_memory_EEPROM_Control,GPIO_PORTF,UART2=49,
SSI1,
Timer_3A,
Timer_3B,I2C1,QEI1,CAN0,CAN1,Hibernation_Module=59,USB,PWM_Generator_3,μDMA_Software,μDMA_Error,ADC1_Sequence_0,ADC1_Sequence_1,ADC1_Sequence_2,
ADC1_Sequence_3,SSI2=73,SSI3,UART3,UART4,UART5,UART6,UART7
}IntCtrl_InterruptType;

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
