/*
 * bai2.c
 *
 * Created: 02/10/2020 14:35:09
 * Author: admin
 */
    
//viet chuong trinh nhap nhay den led theo chu ki 1s
#include <io.h>
//dieu khien LED 
//dieu khien LED PE3, E6, E7
void main(void)
{           
// ba dong duoi day la 3 cach quy uoc E5 la output
//DDRE.5 = 1;   // day la cach tac dong truc tiep vao bit
//DDRE = 0b0010 0000; //day la cach tac dong ca port
DDRE = 0x20; //day la cach tac dong theo kieu hexa. viet theo hexa thi co chu x : 0x20, viet theo nhi phan la 0b1000
//PORTE = 0x00; //tat ca cac bit bang 0 thi bit E5 cung bang 0
PORTE = 0x20; //tat den bang dong lenh khi cho bit E5 bang 1
}
