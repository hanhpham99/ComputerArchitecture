/*
 * bai1.c
 *
 * Created: 25/09/2020 14:36:59
 * Author: admin
 */                                            
 
/*Viet chuong trinh dieu khien bat den LED noi vao PE5*/
/*
Muon dieu khien den LEBD thi du lieu phai di tu MCU ra PE5
Neu ket noi LED voi MCU theo dang catot thi LED sang khi xuat logic loi ra = 0 (GND = 0V)
Neu ket noi LEB voi MCU theo dang anot thi LED sang khi xuat logic loi ra = 1 (VCC = 5V)
Mach dien thuc hang duoc noi dang K
*/

/*Trong AVR co ba thanh ghi tac dong vao PORT
    1. DDR = Data DiRection = thanh ghi huong du lieu
        DDR = 0 ; MCU nhan du lieu tu ngoai vao (input)                
        DDR = 1 ; MCU dua du lieu ra ngoai (output)   
    2. PORT  = thanh ghi du lieu
        PORT = 1 +OUTPUT ghi du lieu ra logic 1 (noi voi VCC = 5V)
        PORT = 1 + INPUT du lieu duoc PULL UP len VCC = 5V (treo nguon)
        PORT = 0 + OUTPUT ghi du lieu ra logic = 0 (noi voi GND = 5V)
    3. PIN = thanh ghi doc du lieu loi vao
*/                                        
/*
Muon PORT E bit 5 dieu khien duoc LED thi PORT E bit 5 phai la loi ra
    DDRE.5 = 1; thanh ghi DDR tac dong vao PORT E bit 5 logic = 1
Do noi den LED theo dang katot nen ta phai ghi logic loi ra bang 0
    PORTE.5 = 0; thanh ghi PORT tac dong vao PORT E bit 5 logic = 0
*/           
#include <io.h>

void main(void)
{ 
/*DDRE.5 = 1;    //gan E5 = output
while (1)
    {
    // Please write your application code here
        PORTE.5 = 0; //sau moi chu ki cua chip thi lai chay lai => ton tai nguyen
    }               
*/
DDRE.5 = 1;   // day la cach tac dong truc tiep vao bit
DDRE = 0b0010 0000; //day la cach tac dong ca port
PORTE.5 = 0;    //bat den 1 lan nhung k tat
while (1)
    {
    }
}
