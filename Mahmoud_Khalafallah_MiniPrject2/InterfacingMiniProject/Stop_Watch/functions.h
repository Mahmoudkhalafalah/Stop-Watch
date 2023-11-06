/*
 * functions.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mahmoud Khalafallah
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <avr/io.h>

#define SET_BIT(Reg,bit) Reg |= (1<<bit)
#define CLEAR_BIT(Reg,bit) Reg &= ~(1<<bit)


void INT0_Init();
void INT1_Init();
void INT2_Init();
void Timer1_COMP_Init();
void Pause_Timer();
void Resume_Timer();
void SEVSEG_Init();
void Display_Number(char num , char SEVSEGNum);

#endif /* FUNCTIONS_H_ */
