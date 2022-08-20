/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  DIO driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 PIN_OFFset[8] = {PIN0_OFFSET,PIN1_OFFSET,PIN2_OFFSET,PIN3_OFFSET,PIN4_OFFSET,PIN5_OFFSET,PIN6_OFFSET,PIN7_OFFSET};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_PortType port,DIO_ChannelType pin){
    switch(port){
        case 1: if(GPIO_PORTA_DATA_R & (1<<pin)){
            return High;
        }
        else{
            return Low;
        } break;
        case 2: if(GPIO_PORTB_DATA_R & (1<<pin)){
            return High;
        }
        else{
            return Low;
        } break;
        case 3: if(GPIO_PORTC_DATA_R & (1<<pin)){
            return High;
        }
        else{
            return Low;
        } break;
        case 4: if(GPIO_PORTD_DATA_R & (1<<pin)){
            return High;
        }
        else{
            return Low;
        } break;
        case 5: if(GPIO_PORTE_DATA_R & (1<<pin)){
            return High;
        }
        else{
            return Low;
        } break;
        case 6: if(GPIO_PORTF_DATA_R & (1<<pin)){
            return High;
        }
        else{
            return Low;
        } break;
            }
}

// using bit-banding
void Dio_writeChannel(DIO_PortType port,DIO_ChannelType pin,DIO_LevelType v){
    switch(port){
        case 1:if(v==1) 
        *((volatile uint32*) (0x42000000 + (0x000043FC * 32) + (pin *4))) = 0xFFFFFFFF;  
        else
        *((volatile uint32*) (0x42000000 + (0x000043FC * 32) + (pin *4))) = 0;
        break;
        case 2:if (v==1)
        *((volatile uint32*) (0x42000000 + (0x000053FC * 32) + (pin *4))) = 0xFFFFFFFF;
        else
       *((volatile uint32*) (0x42000000 + (0x000053FC * 32) + (pin *4))) = 0;
        break;
        case 3:if(v==1) 
       *((volatile uint32*) (0x42000000 + (0x000063FC * 32) + (pin *4))) = 0xFFFFFFFF;
        else
        *((volatile uint32*) (0x42000000 + (0x000063FC * 32) + (pin *4))) = 0;
        break;
        case 4:if(v==1)
         *((volatile uint32*) (0x42000000 + (0x000073FC * 32) + (pin *4))) = 0xFFFFFFFF;
         else
         *((volatile uint32*) (0x42000000 + (0x000073FC * 32) + (pin *4))) = 0;
         break;
        case 5: if (v==1)
        *((volatile uint32*) (0x42000000 + (0x000243FC * 32) + (pin *4))) = 0xFFFFFFFF;
        else
        *((volatile uint32*) (0x42000000 + (0x000243FC * 32) + (pin *4))) = 0;
        break;
        case 6: if (v==1)
        *((volatile uint32*) (0x42000000 + (0x000253FC * 32) + (pin *4))) = 0xFFFFFFFF;
        else
        *((volatile uint32*) (0x42000000 + (0x000253FC * 32) + (pin *4))) = 0;
        break;    
    }
}
DIO_PortLevelType Dio_readPort(DIO_PortType port){
    switch (port)
    {
    case 1: return GPIO_PORTA_DATA_R;break;
    case 2: return GPIO_PORTB_DATA_R;break;
    case 3: return GPIO_PORTC_DATA_R;break;
    case 4: return GPIO_PORTD_DATA_R;break;
    case 5: return GPIO_PORTE_DATA_R;break;
    case 6: return GPIO_PORTF_DATA_R;break;
}
}

void Dio_WritePort(DIO_PortType port,DIO_PortLevelType v){
    switch (port)
    {
    case 1: GPIO_PORTA_DATA_R=v;break;
    case 2: GPIO_PORTB_DATA_R=v;break;
    case 3: GPIO_PORTC_DATA_R=v;break;
    case 4: GPIO_PORTD_DATA_R=v;break;
    case 5: GPIO_PORTE_DATA_R=v;break;
    case 6: GPIO_PORTF_DATA_R=v;break;
}
}
void Dio_FlipChannel(DIO_PortType port,DIO_ChannelType pin)
{
   switch(port){
        case 1:if(*((volatile uint32*) (0x42000000 + (0x000043FC * 32) + (pin *4))) == 0xFFFFFFFF) 
        *((volatile uint32*) (0x42000000 + (0x000043FC * 32) + (pin *4))) = 0;  
        else
        *((volatile uint32*) (0x42000000 + (0x000043FC * 32) + (pin *4))) = 0xFFFFFFFF;
        break;
        case 2:if (*((volatile uint32*) (0x42000000 + (0x000053FC * 32) + (pin *4))) ==0xFFFFFFFF)
        *((volatile uint32*) (0x42000000 + (0x000053FC * 32) + (pin *4))) = 0;
        else
        *((volatile uint32*) (0x42000000 + (0x000053FC * 32) + (pin *4))) = 0xFFFFFFFF;
        break;
        case 3:if(*((volatile uint32*) (0x42000000 + (0x000063FC * 32) + (pin *4))) == 0xFFFFFFFF) 
       *((volatile uint32*) (0x42000000 + (0x000063FC * 32) + (pin *4))) = 0;
        else
        *((volatile uint32*) (0x42000000 + (0x000063FC * 32) + (pin *4))) = 0xFFFFFFFF;
        break;
        case 4:if(*((volatile uint32*) (0x42000000 + (0x000073FC * 32) + (pin *4))) ==0xFFFFFFFF)
         *((volatile uint32*) (0x42000000 + (0x000073FC * 32) + (pin *4))) = 0;
         else
         *((volatile uint32*) (0x42000000 + (0x000073FC * 32) + (pin *4))) = 0xFFFFFFFF;
         break;
        case 5: if (*((volatile uint32*) (0x42000000 + (0x000243FC * 32) + (pin *4))) == 0xFFFFFFFF)
        *((volatile uint32*) (0x42000000 + (0x000243FC * 32) + (pin *4))) = 0;
        else
        *((volatile uint32*) (0x42000000 + (0x000243FC * 32) + (pin *4))) = 0xFFFFFFFF;
        break;
        case 6: *((volatile uint32*) (0x42000000 + (0x000253FC * 32) + (pin *4))) ^= 0xFFFFFFFF;
        break;    
    }

}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
