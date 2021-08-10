// CodeVisionAVR V2.0 C Compiler
// (C) 2000-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega163

#ifndef _MEGA163_INCLUDED_
#define _MEGA163_INCLUDED_

#pragma used+
sfrb TWBR=0;
sfrb TWSR=1;
sfrb TWAR=2;
sfrb TWDR=3;
sfrb ADCL=4;
sfrb ADCH=5;
sfrw ADCW=4;      // 16 bit access
sfrb ADCSR=6;
sfrb ADMUX=7;
sfrb ACSR=8;
sfrb UBRR=9;
sfrb UCSRB=0xa;
sfrb UCSRA=0xb;
sfrb UDR=0xc;
sfrb SPCR=0xd;
sfrb SPSR=0xe;
sfrb SPDR=0xf;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb PINC=0x13;
sfrb DDRC=0x14;
sfrb PORTC=0x15;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb PINA=0x19;
sfrb DDRA=0x1a;
sfrb PORTA=0x1b;
sfrb EECR=0x1c;
sfrb EEDR=0x1d;
sfrb EEARL=0x1e;
sfrb EEARH=0x1f;
sfrw EEAR=0x1e;   // 16 bit access
sfrb UBRRHI=0x20;
sfrb WDTCR=0x21;
sfrb ASSR=0x22;
sfrb OCR2=0x23;
sfrb TCNT2=0x24;
sfrb TCCR2=0x25;
sfrb ICR1L=0x26;
sfrb ICR1H=0x27;
sfrb OCR1BL=0x28;
sfrb OCR1BH=0x29;
sfrw OCR1B=0x28;  // 16 bit access
sfrb OCR1AL=0x2a;
sfrb OCR1AH=0x2b;
sfrw OCR1A=0x2a;  // 16 bit access
sfrb TCNT1L=0x2c;
sfrb TCNT1H=0x2d;
sfrw TCNT1=0x2c;  // 16 bit access
sfrb TCCR1B=0x2e;
sfrb TCCR1A=0x2f;
sfrb SFIOR=0x30;
sfrb OSCCAL=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb TWCR=0x36;
sfrb SPMCR=0x37;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GIMSK=0x3b;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define EXT_INT0 2
#define EXT_INT1 3
#define TIM2_COMP 4
#define TIM2_OVF 5
#define TIM1_CAPT 6
#define TIM1_COMPA 7
#define TIM1_COMPB 8
#define TIM1_OVF 9
#define TIM0_OVF 10
#define SPI_STC 11
#define UART_RXC 12
#define UART_DRE 13
#define UART_TXC 14
#define ADC_INT 15
#define EE_RDY 16
#define ANA_COMP 17
#define TWI 18

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x40
	.EQU __sm_mask=0x30
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <mega163_bits.h>
#endif

#endif

