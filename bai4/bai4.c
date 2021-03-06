/*
 * bai4.c
 *
    CT1 - LED sang
    CT2 - LED toi
    CT3 -LED nhap nhay chu ki 1s
 */

#include <io.h>
#include <delay.h>

#define CT1 PIND.3
#define CT2 PIND.5
#define CT3 PIND.2
#define led PORTE.5
#define sang 0
#define toi 1
#define bam 0
#define nha 1
unsigned char x = 0;
//int dem;
char dem;
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0xB2;
if(x == 1)
{
    dem++;  //moi so dem se tang 1ms
    if(dem == 100)
    { 
        led = sang;
    }  
    if(dem == 200)
    { 
        led = toi;
        dem = 0;
    }
}
// Place your code here

}
void main(void)
{
DDRE = 0x20; //bit thu 5 la loi ra
DDRD = 0x00;
PORTE = 0x20;
PORTD = 0x2C;   // PORTD.2 = 1; PORTD.3 = 1; PORTD.5 = 1; PORTD = 0b0010 1100          c?c so bang 1 la cac bit pull up (bit 2 3 5)
                //pull up = noi bus len VCC = (logic 1) 5V doi voi noi vao la nut bam, 
                //thong thuong nguoi ta thiet ke mach de khi bam bus se noi xuong GND (logic = 0) tuong ung 0V
ASSR=0<<AS0;
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0xB2;
OCR0=0x00;
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (0<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);

#asm("sei")
while (1)
    {
        if(CT1 == bam){ 
            delay_ms(250);
            led = sang;
            x = 0;
        }               
        if (CT2 == bam)
        {   
            delay_ms(250);
            led =  toi; 
            x = 0;  
        }
        if(CT3 == bam)
        {          
            delay_ms(250);
            x = 1;
        }

    }
}
