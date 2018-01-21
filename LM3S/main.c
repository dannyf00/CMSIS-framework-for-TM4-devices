#include "gpio.h"									//use gpio
#include "delay.h"									//use software delays
#include "coretick.h"
#include "systick.h"								//use systick
//#include "uart0isr.h"								//use uart0/vcp
#include "timer0.h"
#include "timer1.h"
#include "timer2.h"

//hardware configuration
#define LED_PORT			GPIOB
#define LED					(1<<2)					//1=R, 2=B, 3=G
//end hardware configuration

//global defines

//global variables

void led_flp(void) {
	static int i=0;
	//if (i++ == 2) {IO_FLP(LED_PORT, LED); i=0;}
	IO_FLP(LED_PORT, LED);
}

int main(void) {
	int32_t i, tmp;

	mcu_init();										//reset the  mcu
	coretick_init();								//initialize coretick
	systick_init();									//initialize systick

	tmr1a_init(100, 10000);
	tmr1a_act(led_flp);
	tmr1b_init(100, 10010);
	tmr1b_act(led_flp);
	IO_OUT(LED_PORT, LED);							//led as output

	ei();											//enable interrupts
	while(1) {
		//flip led
		//tmp = TIMER5->TBR;
		//IO_FLP(LED_PORT, LED);						//to be benchmarked
		//tmp = TIMER5->TBR - tmp;
		//tmp = ticks();								//time stamp
		//delay_ms(100);								//waste some time
		//tmp = ticks() - tmp;						//calculate time elapsed
	}

	return 0;
}


