//bam bt1 thi servo quay goc 90,bt2 thi servo quay goc 135
/*
#include <io.h>
#include <delay.h>
#include <stdio.h>
#define servo  PORTC.7
#define BT1 PINB.2
#define BT2 PINB.3

int dem;
char vitri;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0=0xB0;//sau moi lan timer tran se cho mot don vi thoi gian bang 0.01s
    dem++;
    if(dem == 2000){
          dem = 0;
    }             
    if(dem <vitri) servo = 1;
    else servo = 0;
}

void main(void)
{
DDRC = 0x80;// DDRC c? 8 bit = b7 b6 ... b0, trong 8 bit nay thi bit 7 la noi ra, th? cho b7=1 => 1 0 0 0 0 0 0 0
DDRB = 0x00;
PORTB = 0x0C;//pull up l?n 1 v? day la n?t bam, truoc khi bam thi bang 1, sau khi bam = 0

ASSR=0<<AS0;
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0xB0;
OCR0=0x00;

TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (0<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);

#asm("sei")
while (1)
    {
        if(BT1 == 0)
        {
            vitri = 150;
        }               
        if(BT2 == 0)
        {
            vitri = 175;
        }
    }
}
*/
/*baitap trong docx*/
#include <io.h>
#include <delay.h>
#include <stdio.h>
#include <glcd.h>
#include <font5x7.h>
#define LED_G PORTD.5
#define servo PORTC.7
#define BT1 PINB.2
#define BT2 PINB.3

char buffer[10];
int dem = 0;
char vitri = 150; //vi tri goc cua servo tu 0-180 do

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
        
    /*TCNT0=0xB0; // sau moi lan timer tran, se cho mot don vi thoi gian = 0.01s
    dem++;
    if (dem == 2000) dem = 0;
    if (dem < vitri) servo = 1;
    else servo = 0;*/  
    
    TCNT0=0xB0;  
    dem++;
    if (dem == 2000) dem = 0;
    if (dem < vitri) servo = 1;
    else servo = 0;
}

void main(void)
{

    GLCDINIT_t glcd_init_data;
    glcd_init_data.font = font5x7;
    glcd_init_data.temp_coef = 90;
    glcd_init_data.bias = 4;
    glcd_init_data.vlcd = 60;
    glcd_init(&glcd_init_data);
    
    DDRD = 0xA0;
    PORTD = 0x00;
    
    DDRC = 0x80;
    DDRB = 0x00;
    PORTB = 0x0C; //0000 1100
    
    ASSR=0<<AS0;
    TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00);
    TCNT0=0xB0;
    OCR0=0x00;
    TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
    ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (0<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);
    #asm("sei")
    
    
    
    while (1)
    {
        /*if (BT1 == 0)
        {
            vitri = 150;
        }
        if (BT2 == 0)
        {
            vitri = 175;
        }*/      
        sprintf(buffer, "%d  ", vitri);
        glcd_outtextxy(10, 10, buffer); 
        
        if (BT1 == 0)
        {    
            delay_ms(250);
            vitri ++;
            if (vitri >= 200) vitri = 150;
            //sprintf(buffer, "%d  ", vitri);
            //glcd_outtextxy(10, 10, buffer);   
        }
        if (BT2 == 0)
        {   
            delay_ms(250);
            vitri --;
            if (vitri <=  100) vitri = 150;
            //sprintf(buffer, "%d  ", vitri);
            //glcd_outtextxy(10, 10, buffer);
        }
    }
}