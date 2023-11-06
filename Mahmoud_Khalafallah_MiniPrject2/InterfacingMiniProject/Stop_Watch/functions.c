/*
 * functions.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Mahmoud Khalafallah
 */

#include "functions.h"

void INT0_Init() {

	CLEAR_BIT(DDRD, PD2); //pin 2 port D set as input
	SET_BIT(PORTD, PD2); //Enable input pull up for port D pin 2
	SET_BIT(MCUCR, ISC01); //Set the interrupt to trigger on falling edge
	SET_BIT(GICR, INT0); //Enable External Interrupt 0
	SET_BIT(SREG, 7); //Enable global interrupt
}

void INT1_Init() {

	CLEAR_BIT(DDRD, PD3); //pin 3 port D set as input
	//Set the interrupt to trigger on rising edge
	SET_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);
	SET_BIT(GICR, INT1); //Enable External Interrupt 2
	SET_BIT(SREG, 7); //Enable global interrupt
}

void INT2_Init() {

	CLEAR_BIT(DDRB, PB2); //pin 3 port D set as input
	SET_BIT(PORTB, PB2); //Enable input pull up for port D pin 2
	CLEAR_BIT(MCUCSR, ISC2); //Set the interrupt to trigger on falling edge
	SET_BIT(GICR, INT2); //Enable External Interrupt 2
	SET_BIT(SREG, 7); //Enable global interrupt
}

void Timer1_COMP_Init() {

	//TCCR1A = 1 << COM1A1; //clear on compare match "non iverting mode"
	TCCR1B = 1 << WGM12 | 1 << CS11 | 1 << CS10; //CTC Mode and Select clk/64 prescaler
	SET_BIT(TIMSK, OCIE1A); //Enable output compare A match
	OCR1A = 15625; //Set the compare value to make an interrupt each second
	SET_BIT(SREG, 7);
}

void SEVSEG_Init() {
	DDRC = 0x0F; //Set first 4 bits of port C to output
	DDRA = 0x3F; //Set first 6 bits of port A to output
}

void Display_Number(char num, char SEVSEGNum) {

	switch (SEVSEGNum) {
	case 1:
		PORTA = 0x01;
		break;
	case 2:
		PORTA = 0x02;
		break;

	case 3:
		PORTA = 0x04;
		break;

	case 4:
		PORTA = 0x08;
		break;

	case 5:
		PORTA = 0x10;
		break;

	case 6:
		PORTA = 0x20;
	}
	PORTC = num;
}
void Pause_Timer() {
	//Disable Timer by disabling the clock
	CLEAR_BIT(TCCR1B, CS11);
	CLEAR_BIT(TCCR1B, CS10);

}
void Resume_Timer() {
	TCNT1 = 0;
	//Enable Timer by enabling the clock
	SET_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
}

