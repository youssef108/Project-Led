#include "IntCtrl.h"
#include "DIO.h"
#include "PORT.h"
#include "GPT.h"
#include "SysTick.h"
uint32 on;
uint32 off;
uint8  current=0;
void toggleLed(void){
	Systick_stop();
	current=DIO_ReadChannel(6,1);
	if(current){
		Dio_writeChannel(6,1,0);
		Systick_Load(off);
	}
	else{
		Dio_writeChannel(6,1,1);
		Systick_Load(on);
	}
	Systick_start();	
}
void setPeriod(float32 onTime,float32 offTime){
	on = (uint32)(onTime*16000000); //seconds to ticks
	off= (uint32)(offTime*16000000);
}
int main(void){
	//Gpio clock init
	GPIO_init();
	//systick init
	Systick_clock(1);
	Systick_setCallback(&toggleLed);
	Systick_intruptEnable();
	//periods init
	setPeriod(1,1);
	Systick_Load(on);
	//port pin init
	pinConfig pincon={1,1,1,1,0,2}; // digital or analog, mode, initial value, direction , internal attach, current
	Port_init(PORTF,1,&pincon);
	//start systick
	Systick_start();
	while(1){

	}
}