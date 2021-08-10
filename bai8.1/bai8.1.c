
//den nen là backlight NOKIA_BL port D7

#include <io.h>
#include <glcd.h>
#include <font5x7.h>
#include <delay.h>
#include <stdio.h>
#define LED_G PORTD.5
#define LED_BL PORTD.7
#define BT1 PINB.2


#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))
unsigned int gia_tri_adc;
char buffer[10];


// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
};
void main(void)
{
GLCDINIT_t glcd_init_data;
glcd_init_data.font=font5x7;
glcd_init_data.temp_coef=90;
glcd_init_data.bias=4;
glcd_init_data.vlcd=60;
glcd_init(&glcd_init_data);

DDRD = 0x20;
PORTD = 0x00;

//DDRB = 0x00;
//PORTB = 0x00;

ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADFR) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
SFIOR=(0<<ACME);
while (1)
    {
        //glcd_moveto(10,10);
        //glcd_outtext("helloworld");
        //glcd_circle(20,20,10);  
        
        gia_tri_adc = read_adc(0);//n?i vào adc0
        sprintf(buffer,"%d ",gia_tri_adc);
        glcd_outtextxy(10,10,buffer);
        delay_ms(250);    
        if(gia_tri_adc <= 700){
            LED_G = 1;
        }     
        else 
         LED_G = 0;        
             
         delay_ms(250);
          if(BT1 == 1){
            LED_BL = 1;
          }            
          else 
          LED_BL = 0;
         
    }
}


//den nen là backlight NOKIA_BL port D7