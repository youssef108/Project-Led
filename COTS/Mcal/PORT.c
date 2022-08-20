/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT.c
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
#include "PORT.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void GPIO_init(){
    SYSCTL_RCGCGPIO_R |= 0x7F;
}
void Port_init(DIO_PortType port,DIO_ChannelType pin,pinConfig *pinconfigp){
    // digital or analog
    switch (port)
    {
    case 1:  if( (pinconfigp ->PortPin_D_A) == 1){
        GPIO_PORTA_DEN_R|= (1<<pin);
    }
    else if((pinconfigp ->PortPin_D_A) == 2)
        GPIO_PORTA_AMSEL_R|=(1<<pin);
    break;
    case 2: if( (pinconfigp ->PortPin_D_A) == 1){
        GPIO_PORTB_DEN_R|= (1<<pin);
    }
    else if((pinconfigp ->PortPin_D_A) == 2)
        GPIO_PORTB_AMSEL_R|=(1<<pin);
    break;
    case 3: if( (pinconfigp ->PortPin_D_A) == 1){
        GPIO_PORTC_DEN_R|= (1<<pin);
    }
    else if((pinconfigp ->PortPin_D_A) == 2)
        GPIO_PORTC_AMSEL_R|=(1<<pin);
    break;
    case 4: if( (pinconfigp ->PortPin_D_A) == 1){
        GPIO_PORTD_DEN_R|= (1<<pin);
    }
    else if((pinconfigp ->PortPin_D_A) == 2)
        GPIO_PORTD_AMSEL_R|=(1<<pin);
    break;
    case 5: if( (pinconfigp ->PortPin_D_A) == 1){
        GPIO_PORTE_DEN_R|= (1<<pin);
    }
    else if((pinconfigp ->PortPin_D_A) == 2)
        GPIO_PORTE_AMSEL_R|=(1<<pin);
    break;
    case 6: if( (pinconfigp ->PortPin_D_A) == 1){
        GPIO_PORTF_DEN_R|= (1<<pin);
    }
    else if((pinconfigp ->PortPin_D_A) == 2)
        GPIO_PORTF_AMSEL_R|=(1<<pin);
    break;
    default:
        break;}

    //Mode control
    switch (port)
    {
    case 1:  if( (pinconfigp ->PortPinMode) != 0){
        GPIO_PORTA_AFSEL_R |= (1<<pin);
        GPIO_PORTA_PCTL_R |= ((pinconfigp -> PortPinMode) << (pin*4) );
    }
    break;
    case 2:if( (pinconfigp ->PortPinMode) != 0){
        GPIO_PORTB_AFSEL_R |= (1<<pin);
        GPIO_PORTB_PCTL_R |= ((pinconfigp -> PortPinMode) << (pin*4) );
    }break;
    case 3:if( (pinconfigp ->PortPinMode) != 0){
        GPIO_PORTC_AFSEL_R |= (1<<pin);
        GPIO_PORTC_PCTL_R |= ((pinconfigp -> PortPinMode) << (pin*4) );
    }break;
    case 4:if( (pinconfigp ->PortPinMode) != 0){
        GPIO_PORTD_AFSEL_R |= (1<<pin);
        GPIO_PORTD_PCTL_R |= ((pinconfigp -> PortPinMode) << (pin*4) );
    }break;
    case 5:if( (pinconfigp ->PortPinMode) != 0){
        GPIO_PORTE_AFSEL_R |= (1<<pin);
        GPIO_PORTE_PCTL_R |= ((pinconfigp -> PortPinMode) << (pin*4) );
    }break;
    case 6:if( (pinconfigp ->PortPinMode) != 0){
        GPIO_PORTF_AFSEL_R |= (1<<pin);
        GPIO_PORTF_PCTL_R |= ((pinconfigp -> PortPinMode) << (pin*4) );
    }break;
    default:
        break;
    }


    // direction
    switch (port)
    {
    case 1:  if( (pinconfigp ->PortPinDirection) == 1){
        GPIO_PORTA_DIR_R |= (1<< pin);
    }
    else
       { GPIO_PORTA_DIR_R &= !(1<<pin);}break;
    case 2:if( (pinconfigp ->PortPinDirection) == 1){
        GPIO_PORTB_DIR_R |= (1<< pin);
    }
    else
       { GPIO_PORTB_DIR_R &= !(1<<pin);}break;
    case 3:if( (pinconfigp ->PortPinDirection) == 1){
        GPIO_PORTC_DIR_R |= (1<< pin);
    }
    else
       { GPIO_PORTC_DIR_R &= !(1<<pin);}break;
    case 4:if( (pinconfigp ->PortPinDirection) == 1){
        GPIO_PORTD_DIR_R |= (1<< pin);
    }
    else
       { GPIO_PORTD_DIR_R &= !(1<<pin);}break;
    case 5:if( (pinconfigp ->PortPinDirection) == 1){
        GPIO_PORTE_DIR_R |= (1<< pin);
    }
    else
       { GPIO_PORTE_DIR_R &= !(1<<pin);}break;
    case 6:if( (pinconfigp ->PortPinDirection) == 1){
        GPIO_PORTF_DIR_R |= (1<< pin);
    }
    else
       { GPIO_PORTF_DIR_R &= !(1<<pin);}break;
    default:
        break;
    }
    //internal attach control
    switch (port)
    {
    case 1:  if( (pinconfigp ->PortPinInternalAttach) == 1){
        GPIO_PORTA_PUR_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 2)
       { GPIO_PORTA_PDR_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 3)
       GPIO_PORTA_ODR_R|=(1<<pin);   
       break;
    case 2:if( (pinconfigp ->PortPinInternalAttach) == 1){
        GPIO_PORTB_PUR_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 2)
       { GPIO_PORTB_PDR_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 3)
       GPIO_PORTB_ODR_R|=(1<<pin);   
       break;
    case 3:if( (pinconfigp ->PortPinInternalAttach) == 1){
        GPIO_PORTC_PUR_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 2)
       { GPIO_PORTC_PDR_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 3)
       GPIO_PORTC_ODR_R|=(1<<pin);   
       break;
    case 4:if( (pinconfigp ->PortPinInternalAttach) == 1){
        GPIO_PORTD_PUR_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 2)
       { GPIO_PORTD_PDR_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 3)
       GPIO_PORTD_ODR_R|=(1<<pin);   
       break;
    case 5:if( (pinconfigp ->PortPinInternalAttach) == 1){
        GPIO_PORTE_PUR_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 2)
       { GPIO_PORTE_PDR_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 3)
       GPIO_PORTE_ODR_R|=(1<<pin);   
       break;
    case 6:if( (pinconfigp ->PortPinInternalAttach) == 1){
        GPIO_PORTF_PUR_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 2)
       { GPIO_PORTF_PDR_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 3)
       GPIO_PORTF_ODR_R|=(1<<pin);   
       break;
    default:
        break;
    }
    //current control
      switch (port)
    {
    case 1:  if( (pinconfigp ->PortPinOutputCurrent) == 2){
        GPIO_PORTA_DR2R_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 4)
       { GPIO_PORTA_DR4R_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 8)
       GPIO_PORTA_DR8R_R|=(1<<pin);   
       break;

    case 2:if( (pinconfigp ->PortPinOutputCurrent) == 2){
        GPIO_PORTB_DR2R_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 4)
       { GPIO_PORTB_DR4R_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 8)
       GPIO_PORTB_DR8R_R|=(1<<pin);   
       break;

    case 3:if( (pinconfigp ->PortPinOutputCurrent) == 2){
        GPIO_PORTC_DR2R_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 4)
       { GPIO_PORTC_DR4R_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 8)
       GPIO_PORTC_DR8R_R|=(1<<pin);   
       break;

    case 4:if( (pinconfigp ->PortPinOutputCurrent) == 2){
        GPIO_PORTD_DR2R_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 4)
       { GPIO_PORTD_DR4R_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 8)
       GPIO_PORTD_DR8R_R|=(1<<pin);   
       break;

    case 5:if( (pinconfigp ->PortPinOutputCurrent) == 2){
        GPIO_PORTE_DR2R_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 4)
       { GPIO_PORTE_DR4R_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 8)
       GPIO_PORTE_DR8R_R|=(1<<pin);   
       break;
    case 6:if( (pinconfigp ->PortPinOutputCurrent) == 2){
        GPIO_PORTF_DR2R_R|=(1<<pin);
    }
    else if((pinconfigp ->PortPinInternalAttach) == 4)
       { GPIO_PORTF_DR4R_R|=(1<<pin);}
    else if((pinconfigp ->PortPinInternalAttach) == 8)
       GPIO_PORTF_DR8R_R|=(1<<pin);   
       break;
    default:
        break;
    }

    Dio_writeChannel(port,pin,pinconfigp -> PortPinLevelValue);

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
 *  END OF FILE: PORT.c
 *********************************************************************************************************************/
