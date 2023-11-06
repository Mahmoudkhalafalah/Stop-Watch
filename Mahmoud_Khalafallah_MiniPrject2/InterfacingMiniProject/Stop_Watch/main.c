/*
 * main.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Mahmoud Khalafallah
 */

#include "functions.h"
#include <avr/interrupt.h>
#include <util/delay.h>

char seconds = 0;
char minutes = 0;
char hours = 0;

ISR(TIMER1_COMPA_vect) {
	seconds++;
	if (seconds == 60) {
		seconds = 0;
		minutes++;
		if (minutes == 60) {
			minutes = 0;
			hours++;
			if (hours == 100) {
				seconds = 0;
				minutes = 0;
				hours = 0;
			}
		}
	}
}

//reset
ISR(INT0_vect) {
	seconds = 0;
	minutes = 0;
	hours = 0;
}

//stop
ISR(INT1_vect) {
	Pause_Timer();
}

//resume
ISR(INT2_vect) {
	Resume_Timer();
}
int main(void) {

	/*
	 *initialization
	 *Timer
	 *External interrupts
	 *SevSeg
	 */
	Timer1_COMP_Init();
	INT0_Init();
	INT1_Init();
	INT2_Init();
	SEVSEG_Init();
	while (1) {
		Display_Number(seconds % 10, 6);
		_delay_ms(1);
		Display_Number(seconds / 10, 5);
		_delay_ms(1);
		Display_Number(minutes % 10, 4);
		_delay_ms(1);
		Display_Number(minutes / 10, 3);
		_delay_ms(1);
		Display_Number(hours % 10, 2);
		_delay_ms(1);
		Display_Number(hours / 10, 1);
		_delay_ms(1);
	}
}
