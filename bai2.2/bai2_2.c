/*
 * bai2_2.c
 *
 * Created: 02/10/2020 15:18:36
 * Author: admin
 */
#include <io.h>
#include <delay.h>
//viet chuong trinh bam ctac 1 thi den sang, tha ra thi tat
/*
    CT1 = D3
    LED = E5
*/
/*
void main(void)
{
DDRE = 0x20;
DDRD = 0x00; // DDRD.3 = 0 , luc nay nut bam phai la input de nhan du lieu tu ngoai vao
PORTD = 0x08; //pull up 

while (1)
    {
        if(PIND.3 == 0)
            {
                PORTE = 0x00;
            }               
        else
            {
                PORTE = 0x20;    
            }
    }
}
*/
/*Viet chuong trinh an nut ct1 la den bat trong vong 3s*/
/* 
void main(void)
{
DDRE = 0x20;
DDRD = 0x00; // DDRD.3 = 0 , luc nay nut bam phai la input de nhan du lieu tu ngoai vao
PORTD = 0x08; //pull up 

while (1)
    {
        if(PIND.3 == 0)
            {
                PORTE = 0x00;
                delay_ms(3000);
            }               
        else
            {
                PORTE = 0x20;    
            }
    }
}
*/
// an lan 1 thi bat, an lan 2 thi tat, an lan 3 thi bat ..

void main(void)
{
DDRE = 0x20;
DDRD = 0x00; // DDRD.3 = 0 , luc nay nut bam phai la input de nhan du lieu tu ngoai vao
PORTD = 0x08; //pull up 

while (1)
    {
        if(PIND.3 == 0)
            {
                delay_ms(250);
                PORTE = ~PORTE;
            }               
       
    }
}

// Bam cong tac 1 thi den sang, bam cong tac 2 thi den tat, bam cong tac 3 thi den nhap nhay theo chu ki 1s