/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void(*callback1)(void)= NULL_PTR;
uint8 prescalar;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void Gpt_init(const GPTConfig* config){
    callback1=config->callback;
    //initialize clock for timers
    SYSCTL_RCGCTIMER_R=0x1F; // initializing clock to timers
    switch(config->timerID){ 
        case 0: TIMER0_CTL_R &= ~(1<<0); // turning off at the beggining
                if(config->GPTTickMaxValue > 65535)  // 16 or 32 bits
                    TIMER0_CFG_R|=0x00000000;
                else
                    TIMER0_CFG_R|=0x00000004;

                TIMER0_TAMR_R|=(1<<4);
                TIMER0_TAMR_R|=((config->ChannelMode)<<0);    // one shot or periodic
                if(config->GPTNotification)
                    TIMER0_IMR_R|=(1<<0);
                prescalar=config->GPTPrescalar;
        break;
        case 1: TIMER1_CTL_R &= ~(1<<0); // turning off at the beggining
                if(config->GPTTickMaxValue > 65535)  // 16 or 32 bits
                    TIMER1_CFG_R|=0x00000000;
                else
                    TIMER1_CFG_R|=0x00000004;

                TIMER1_TAMR_R|=(1<<4);
                TIMER1_TAMR_R|=((config->ChannelMode)<<0);    // one shot or periodic
                if(config->GPTNotification)
                    TIMER1_IMR_R|=(1<<0);
                prescalar=config->GPTPrescalar;
        break;
        case 2: TIMER2_CTL_R &= ~(1<<0); // turning off at the beggining
                if(config->GPTTickMaxValue > 65535)  // 16 or 32 bits
                    TIMER2_CFG_R|=0x00000000;
                else
                    TIMER2_CFG_R|=0x00000004;

                TIMER2_TAMR_R|=(1<<4);
                TIMER2_TAMR_R|=((config->ChannelMode)<<0);    // one shot or periodic
                if(config->GPTNotification)
                    TIMER2_IMR_R|=(1<<0);
                prescalar=config->GPTPrescalar;
        break;
        case 3: TIMER3_CTL_R &= ~(1<<0); // turning off at the beggining
                if(config->GPTTickMaxValue > 65535)  // 16 or 32 bits
                    TIMER3_CFG_R|=0x00000000;
                else
                    TIMER3_CFG_R|=0x00000004;

                TIMER3_TAMR_R|=(1<<4);
                TIMER3_TAMR_R|=((config->ChannelMode)<<0);    // one shot or periodic
                if(config->GPTNotification)
                    TIMER3_IMR_R|=(1<<0);
                prescalar=config->GPTPrescalar;
        break;
        case 4: TIMER4_CTL_R &= ~(1<<0); // turning off at the beggining
                if(config->GPTTickMaxValue > 65535)  // 16 or 32 bits
                    TIMER4_CFG_R|=0x00000000;
                else
                    TIMER4_CFG_R|=0x00000004;

                TIMER4_TAMR_R|=(1<<4);
                TIMER4_TAMR_R|=((config->ChannelMode)<<0);    // one shot or periodic
                if(config->GPTNotification)
                    TIMER4_IMR_R|=(1<<0);
                prescalar=config->GPTPrescalar;
        break;
                
    }
}

void Gpt_DisableNotification(uint8 channel){
    switch(channel){
        case 0: TIMER0_IMR_R &= ~(1<<0);break;
        case 1: TIMER1_IMR_R &= ~(1<<0);break;
        case 2: TIMER2_IMR_R &= ~(1<<0);break;
        case 3: TIMER3_IMR_R &= ~(1<<0);break;
        case 4: TIMER4_IMR_R &= ~(1<<0);break;
    }
}
void Gpt_EnableNotification(uint8 channel){
    switch(channel){
        case 0: TIMER0_IMR_R |= (1<<0);break;
        case 1: TIMER1_IMR_R |= (1<<0);break;
        case 2: TIMER2_IMR_R |= (1<<0);break;
        case 3: TIMER3_IMR_R |= (1<<0);break;
        case 4: TIMER4_IMR_R |= (1<<0);break;
    }
}
uint32 Gpt_ValueType(uint8 channel){
    uint32 value;
    switch(channel){
        case 0: if(value != 1)
                    value = (TIMER0_TAV_R >> (prescalar/2)) & 0x0000FFFF ;
                else
                    value = TIMER0_TAV_R & 0x0000FFFF;
                return value;break;
        case 1: if(value != 1)
                    value =  (TIMER1_TAV_R >> (prescalar/2)) & 0x0000FFFF ;
                else
                    value = TIMER1_TAV_R & 0x0000FFFF;
                return value;break;
        case 2: if(value != 1)
                    value =  (TIMER2_TAV_R >> (prescalar/2)) & 0x0000FFFF ;
                else
                    value = TIMER2_TAV_R & 0x0000FFFF;
                return value;break;
        case 3: if(value != 1)
                    value =  (TIMER3_TAV_R >> (prescalar/2)) & 0x0000FFFF ;
                else
                    value = TIMER3_TAV_R & 0x0000FFFF;
                return value;break;
        case 4: if(value != 1)
                    value =  (TIMER4_TAV_R >> (prescalar/2)) & 0x0000FFFF ;
                else
                    value = TIMER4_TAV_R & 0x0000FFFF;
                return value;break;
        
    }
}
void Gpt_StartTimer(uint8 channel , uint32 value){
    switch (channel)
    {
    case 0 : TIMER0_TAILR_R = value;
             TIMER0_CTL_R |= (1<<0);
        break;
    case 1 : TIMER1_TAILR_R = value;
             TIMER1_CTL_R |= (1<<0);
        break;
    case 2 : TIMER2_TAILR_R = value;
             TIMER2_CTL_R |= (1<<0);
        break;
    case 3 : TIMER3_TAILR_R = value;
             TIMER3_CTL_R |= (1<<0);
        break;
    case 4: TIMER4_TAILR_R = value;
             TIMER4_CTL_R |= (1<<0);
        break;
    
    default:
        break;
    }
}
void Gpt_StopTimer(uint8 channel){
switch (channel)
    {
    case 0 : TIMER0_CTL_R &= ~(1<<0);
        break;
    case 1 : TIMER1_CTL_R &= ~(1<<0);
        break;
    case 2 : TIMER2_CTL_R &= ~(1<<0);
        break;
    case 3 : TIMER3_CTL_R &= ~(1<<0);
        break;
    case 4: TIMER4_CTL_R &= ~(1<<0);
        break;
    
    default:
        break;
    }
}





void TIMER0A_Handler(void){
    TIMER0_MIS_R|=(1<<0);
    callback1();
}
void TIMER1A_Handler(void){
    TIMER1_MIS_R|=(1<<0);
    callback1();
}
void TIMER2A_Handler(void){
    TIMER2_MIS_R|=(1<<0);
    callback1();
}
void TIMER3A_Handler(void){
    TIMER3_MIS_R|=(1<<0);
    callback1();
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
