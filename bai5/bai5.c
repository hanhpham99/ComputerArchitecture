

#include <io.h>
#include <alcd.h>
#include <delay.h>

//1.viet chuong trinh hien thi dong chu "hello-world" lên màn hình
/*void main(void)
{
lcd_init(16);//8
lcd_clear();
lcd_gotoxy(0,1);
lcd_putsf("hello_world");
while (1)
    {
    // bam ct1 hien helloworld, ct2 thi xoa

    }
}
*/
/*2. bam ct1 hien helloworld, ct2 thi xoa
#define CT1 PIND.3
#define CT2 PIND.5

#define bam 0
#define nha 1
void main(void)
{
lcd_init(16);//8
lcd_clear();

DDRD = 0x00;
PORTD = 0x28;
while (1)
    {
        if(CT1 == bam){
         delay_ms(250);      
            lcd_gotoxy(0,1);
            lcd_putsf("hello_world");
        }               
        if (CT2 == bam)
        {              
         delay_ms(250);
            lcd_clear();
        }
    }
}
*/

/*bam ct1 thi helloworld chay tu trai sang phai, ct2 chay tu phai sang trai, ct3 chay ra giua

#define CT1 PIND.3
#define CT2 PIND.5
#define CT3 PIND.2
#define bam 0
#define nha 1

int mode = 0;

void main(void)
{

DDRD = 0x00;
PORTD = 0x3C;

lcd_init(16);//8
    delay_ms(500);
    lcd_gotoxy(0,0);
    lcd_puts("hello_world");

while (1)
    {
        if(CT1 == 0 || mode == 1){
         delay_ms(250); 
         mode = 1;
         _lcd_write_data(0x1C);     //0001 1100
        }               
        if(CT2 == 0 || mode == 2){
         delay_ms(250); 
         mode = 2;
         _lcd_write_data(0x18);    //0001 1000 
        } 
        if(CT3 == 0 || mode == 3){
         delay_ms(250); 
         mode = 0;
        lcd_gotoxy(0,0);
        lcd_puts("hello_world");
        } 
    }
}
*/

//bai8 ban dau servo o goc 0, moi lan bam ct1 gia tri cua goc tang len 1.8
//neu goc = 90 se quay ve vi tri ban dau, moi lan bam ct2 gia tri goc giam di 1.8, 
//neu goc = -90 se quay ve ban dau, hien thi so do goc len lcd

#define CT1 PIND.3
#define CT2 PIND.5
#define CT3 PIND.2
#define bam 0
#define nha 1

int mode = 0;

void main(void)
{

DDRD = 0x00;
PORTD = 0x3C;

lcd_init(16);//8
    delay_ms(500);
    lcd_gotoxy(0,0);
    lcd_puts("hello_world");

while (1)
    {
        if(CT1 == 0 || mode == 1){
         delay_ms(250); 
         mode = 1;
         _lcd_write_byte(0x1C);     //0001 1100
        }               
        if(CT2 == 0 || mode == 2){
         delay_ms(250); 
         mode = 2;
         _lcd_write_byte(0x18);    //0001 1000 
        } 
        if(CT3 == 0 || mode == 3){
         delay_ms(250); 
         mode = 0;
        lcd_gotoxy(0,0);
        lcd_puts("hello_world");
        } 
    }
}