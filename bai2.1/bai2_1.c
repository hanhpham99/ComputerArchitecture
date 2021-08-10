           
 //viet chuong trinh cho den led nhap nhay voi chu ki 1s   
 //viet chuong trinh dieu khien led sang theo chu ki sang 1 toi 1,  sang 2 toi2, sang mai
 //viet chuong trinh bam ctac 1 thi den sang, tha ra thi tat
#include <io.h>
#include <delay.h> // thu vien dung cac ham lam tre
//#include "Ten_thu_vien.c"
/* viet chuong trinh dieu khien led sang theo chu ki sang 1 toi 1,
void main(void)
{
DDRE = 0x20;
while (1)
    {
         PORTE = 0x20;
         delay_ms(1000);//ham lam tre theo don vi ms, delay lam cho cpu khong hoat dong nen chi co delay theo ms hoac mcs
         PORTE = 0x00;   
          delay_ms(1000);
    }
}
*/
/* viet chuong trinh dieu khien led sang theo chu ki sang 2 toi 2,
void main(void)
{
DDRE = 0x20;
while (1)
    {
         PORTE = 0x20;
         delay_ms(2000);//ham lam tre theo don vi ms, delay lam cho cpu khong hoat dong nen chi co delay theo ms hoac mcs
         PORTE = 0x00;   
          delay_ms(2000);
    }
}
*/
/*viet chuong trinh dieu khien led sang theo sang mai
void main(void)
{
DDRE = 0x20;
while (1)
    {
         PORTE = 0x00;
    }
}
 */
//viet chuong trinh bam ctac 1 thi den sang, tha ra thi tat
