
/*
Viet chuong trinh bam ct1 truoc, ct2 sau thi dem tu 0 ; neu ct2 truoc ct1 thi dem lui 
tu gia tri do ; neu so dem < 0 thi so dem = 0; khi so dem >0 thi den sang
so dem =0 thi den tat. hien thi so ra man hinh 
*/
#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h> //chuyen tu char, int sang string
#include <stdio.h>

#define CT1 PIND.3
#define CT2 PIND.5
#define LED PORTE.5
#define sang 0
#define toi 1

int dem = 0;
unsigned char buffer[20];

void main(void)
{
DDRD = 0x00;
PORTD = 0x28;        //vi dung co 2 cong tâc thoi
DDRE = 0x20; //bit thu 5 la loi ra
LED = toi; 

while (1)
    {
        if(CT1 == 0){ 
            while(1){
               if(CT2 == 0){  
                delay_ms(250);
                dem ++; 
                 break;    
               } 
                
            }
           
        }               
        if(CT2 == 0){ 
            while(1){
               if(CT1 == 0){  
                delay_ms(250);
                dem --; 
                 break;    
               } 
            }
        }  
        
        if(dem <= 0)
        {
             dem = 0;
             LED = toi;
        }
        else
        {      
            LED = sang;
        }  
        lcd_init(16);
        lcd_gotoxy(0,0);     
        sprintf(buffer, "%d",dem);
         
        lcd_putsf("so nguoi: ");         
        lcd_gotoxy(10,0);
        
        lcd_puts(buffer);
    }
}