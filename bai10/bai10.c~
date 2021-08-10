/*
 * bai10.c
 viet chuong trinh doc du lieu t, h tu cam bien dht11
 */

#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h> //phai co dong nay

#define DHT_ER 0
#define DHT_OK 1

#define DHT_DATA_IN PINB.7
#define DHT_DATA_OUT PORTB.7
#define DHT_DDR_DATA DDRB.7

char data[16];
unsigned char dht_nhiet_do, dht_do_am;
unsigned char DHT_GetTemHumi(unsigned char *tem,unsigned char *humi)
{
    unsigned char buffer[5] = {0,0,0,0,0};
    unsigned char ii,i,checksum;
    
    DHT_DDR_DATA = 1;      //set cong ra
    DHT_DATA_OUT = 0;
    delay_us(40);       
    DHT_DATA_OUT = 1;
    delay_ms(30);
    DHT_DATA_OUT = 1;
    DHT_DDR_DATA = 0;    // set la loi vao 
    delay_us(40);   
    
    if(DHT_DATA_IN) {
        return DHT_ER;
    }                 
    else while(!(DHT_DATA_IN)); //doi data len
    delay_us(40);
    
    if(!(DHT_DATA_IN)){
        return DHT_ER;
    }             
    else while((DHT_DATA_IN));            
    
    //bat dau doc du lieu
    for(i=0; i<5; i++)
    {
        for(ii=0; ii<8; ii++)
        {        
            while((!DHT_DATA_IN)) ;  //doi data len 1
            delay_us(30);
            if(DHT_DATA_IN)
            {
                buffer[i] |= (1<<(7-ii));    //lay 7 bit  
                while((DHT_DATA_IN)) ;//doi data xuong 0
            }
        }
    }                                                   
    //tinh toan checksum
    checksum = buffer[0]+  buffer[1]+  buffer[2] + buffer[3] ;        
    //kiem tra checksum
    if((checksum) != buffer[4]){
        return DHT_ER;
    }             
    //Lay du lieu
    *tem = buffer[2];
    *humi = buffer[0];
    return DHT_OK;
}

void main(void)
{
DDRD = 0x80;    //BL LCD
PORTD = 0x80;
lcd_init(16);
while (1)
    {
        if(DHT_GetTemHumi(&dht_nhiet_do, &dht_do_am))
        {
            lcd_clear();
            lcd_gotoxy(0,0);
            sprintf(data,"DO AM %u",(uint8_t)dht_do_am);
            lcd_puts(data);
            lcd_gotoxy(0,1);
            sprintf(data,"NHIET DO %u",(uint8_t)dht_nhiet_do);   
            lcd_puts(data);
            delay_ms(300); 
        }

    }
}
