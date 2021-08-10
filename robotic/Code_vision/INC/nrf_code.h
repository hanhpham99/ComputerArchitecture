#define _BV(x) (1<<(x))
#define RX_DR       6
#define TX_DS       5
#define MAX_RT      4
#define STATUS      0x07

typedef struct
{
    int flag;
    float a;
    float b;
    float c;
    float d;
}data;

data data_receive;

bool tx_ok;
unsigned char status;
unsigned char result;


void config();


//-----------------------------TX Mode -----------------------------------------------//
unsigned char SPI_RW_TX(unsigned char Buff);                                       //Function used for text moving
void RF_Init_TX();                                                                 //Function allow to Initialize RF device
unsigned char RF_Write_TX(unsigned char Reg_Add, unsigned char Value);                      //Function to write a value to a register address
void RF_Write_Address_TX(unsigned char Address);                                   //Function to write TX address for pipe 1 2 
void RF_Write_Address_2_TX(unsigned char Address);                                 //Function to write TX address for pipe 3 4 
void RX_Mode_Active_TX();                                                          //Function to put nRF in RX mode
void TX_Mode_Active_TX();                                                          //Function to put nRF in TX mode
void RF_Config_TX();                                                               //Function to config the nRF
bool RF_TX_Send_TX(data send);                                                     //Function to send data Value to RX Address
bool RF_TX_Send_2_TX(data send);                                                   //Function to send data Value to RX address


//---------------------------------RX Mode----------------------------------------------//
unsigned char SPI_RW_RX(unsigned char Buff);                                       //Function used for text moving
unsigned char SPI_Read_RX(void);
void RF_Init_RX();                                                                 //Function allow to Initialize RF device
void RF_Write_RX(unsigned char Reg_Add, unsigned char Value);                      //Function to write a value to a register address
void RF_Command_RX(unsigned char command);                                         //Function to write a command
void RF_Write_Address_RX(unsigned char Address1, unsigned char Address2, unsigned char Address3, unsigned char Address4);         //Function to write TX and RX address
void RX_Mode_RX();                                                          //Function to put nRF in RX mode
void RF_Config_RX();                                                               //Function to config the nRF
void RF_Read_RX();                                                     //Function to read the data from RX FIFO
void RF_Write2_RX(unsigned char Reg_Add, unsigned char Value);
void RF_Write3_RX(unsigned char Reg_Add, unsigned char Value);




void config()
{
delay_us(10);
RF_Write_TX(0x00,0b00011111);     //CONFIG 0x00
delay_ms(2);
RF_Write_TX(0x07,0b01111110);
RF_Write_TX(0x1D, 0b00000100);
RF_Write_TX(0x05,0b00000010);     //RF_CH 0x05        Choose frequency channel
}



unsigned char SPI_RW_TX(unsigned char Buff){
    unsigned char bit_ctr;
       for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
       {
        MOSI = (Buff & 0x80);         // output 'uchar', MSB to MOSI    
        delay_us(5);
        Buff = (Buff << 1);           // shift next bit into MSB..
        SCK = 1;                      // Set SCK high..          
        delay_us(5);
        Buff |= MISO;                 // capture current MISO bit
        SCK = 0;                      // ..then set SCK low again
       }
    return(Buff);                     // return read uchar
}

void RF_Init_TX()                                                    //Function allow to Initialize RF device
{ 
    CE=1;
    delay_us(700);
    CE=0;
    CSN=1;
}

unsigned char RF_Write_TX(unsigned char Reg_Add, unsigned char Value)         //Function to write a value to a register address
{

    CSN=0;
    result = SPI_RW_TX(0b00100000|Reg_Add);
    SPI_RW_TX(Value);
    CSN=1;
    delay_us(10);
	return result;
}

void RF_Write_Address_TX(unsigned char Address)                      //Function to write TX and RX address
{
    CSN=0;
    RF_Write_TX(0x03,0b00000011);
    CSN=1;
    delay_us(10);
    CSN=0;
    SPI_RW_TX(0b00100000|0x0A);     
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
    CSN=1;
    delay_us(10);
    CSN=0;
    SPI_RW_TX(0b00100000|0x10);   
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
    SPI_RW_TX(Address);
  
    CSN=1;
    delay_us(10);
}

void RF_Write_Address_TX_2(unsigned char Address)                      //Function to write TX and RX address
{
    CSN=0;
    RF_Write_TX(0x03,0b00000011);
    CSN=1;
    delay_us(10);
    CSN=0;
    SPI_RW_TX(0b00100000|0x0A);     
    SPI_RW_TX(Address);
    SPI_RW_TX(0x02);
    SPI_RW_TX(0x02);
    SPI_RW_TX(0x02);
    SPI_RW_TX(0x02);
    CSN=1;
    delay_us(10);
    CSN=0;
    SPI_RW_TX(0b00100000|0x10);   
    SPI_RW_TX(Address);
    SPI_RW_TX(0x02);
    SPI_RW_TX(0x02);
    SPI_RW_TX(0x02);
    SPI_RW_TX(0x02);
  
    CSN=1;
    delay_us(10);
}

void RF_Mode_TX()                                             //Function to put nRF in TX mode
{
    CE=0;
    RF_Write_TX(0x00,0b00011110);     //CONFIG 0x00
}

void RF_Config_TX()                                                  //Function to config the nRF
{

RF_Write_TX(0x1C,0b00000001); 
RF_Write_Address_TX(P_Add);
RF_Write_TX(0x02,0b00000001);     //EX_RXADDR 0x02    enable data pipe 0;
RF_Write_TX(0x01,0b00000001);     //EN_AA 0x01        enable auto-acknowledgment
}

void RF_Config_TX_2()                                                  //Function to config the nRF
{

RF_Write_TX(0x1C,0b00000001); 
RF_Write_Address_TX_2(P_Add);
RF_Write_TX(0x02,0b00000001);     //EX_RXADDR 0x02    enable data pipe 0;
RF_Write_TX(0x01,0b00000001);     //EN_AA 0x01        enable auto-acknowledgment
}

void RF_Command_TX(unsigned char command)                            //Function to write a command
{
    CSN=0;
    SPI_RW_TX(command);
    CSN=1;
    delay_us(10);
}

bool RF_Send_TX(data send)     //Function to send data Value to a specify RX Address
{

  RF_Write_Address_TX(P_Add);
  CSN=1;
  delay_us(10);
  CSN=0;
  SPI_RW_TX(0b11100001);
  CSN=1;
  delay_us(10);
  CSN=0;
  SPI_RW_TX(0b10100000);
  SPI_RW_TX(send.flag); 
  SPI_RW_TX(send.a);
  SPI_RW_TX(send.b);
  SPI_RW_TX(send.c);
  SPI_RW_TX(send.d);
  CSN=1;
  CE=1;
  delay_us(500);
  CE=0;
  RF_Write_TX(0x07,0b01111110);
  RF_Write_Address_TX(P_Add);
  RF_Command_TX(0b11100001);  
  
  status = RF_Write_TX(0x07,0b00111000); //0b00111000
  tx_ok = status & 0b00010000;
  return tx_ok;
}

bool RF_Send_TX_2(data send)     //Function to send data Value to a specify RX Address
{

  RF_Write_Address_TX_2(P_Add);
  CSN=1;
  delay_us(10);
  CSN=0;
  SPI_RW_TX(0b11100001);
  CSN=1;
  delay_us(10);
  CSN=0;
  SPI_RW_TX(0b10100000);
  SPI_RW_TX(send.flag); 
  SPI_RW_TX(send.a);
  SPI_RW_TX(send.b);
  SPI_RW_TX(send.c);
  SPI_RW_TX(send.d);
  CSN=1;
  CE=1;
  delay_us(500);
  CE=0;
  RF_Write_TX(0x07,0b01111110);
  RF_Write_Address_TX_2(P_Add);
  RF_Command_TX(0b11100001);  
  
  status = RF_Write_TX(0x07,0b00111000); //0b00111000
  tx_ok = status & 0b00010000;
  return tx_ok;
}



//--------------------------------------------RX function------------------------------------//
unsigned char SPI_RW_RX(unsigned char Buff)
{
    unsigned char bit_ctr;
       for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
       {
        MOSI = (Buff & 0x80);         // output 'uchar', MSB to MOSI    
        delay_us(5);
        Buff = (Buff << 1);           // shift next bit into MSB..
        SCK = 1;                      // Set SCK high..          
        delay_us(5);
        Buff |= MISO;                 // capture current MISO bit
        SCK = 0;                      // ..then set SCK low again
       }
    return(Buff);                     // return read uchar
}

unsigned char SPI_Read_RX(void)
{   unsigned char Buff=0;
    unsigned char bit_ctr;
       for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
       {
        delay_us(5);
        Buff = (Buff << 1);           // shift next bit into MSB..
        SCK = 1;                      // Set SCK high..          
        delay_us(5);
        Buff |= MISO;                 // capture current MISO bit
        SCK = 0;                      // ..then set SCK low again
       }
    return(Buff);                     // return read uchar
}

void RF_Init_RX()                                                    //Function allow to Initialize RF device
{ 
    CE=1;
    delay_us(700);
    CE=0;
    CSN=1;
}

void RF_Write_RX(unsigned char Reg_Add, unsigned char Value)         //Function to write a value to a register address
{
    CSN=0;
    SPI_RW_RX(0b00100000|Reg_Add);
    SPI_RW_RX(Value);
    CSN=1;
    delay_us(10);
}

void RF_Write2_RX(unsigned char Reg_Add, unsigned char Value)         //Function to write a value to a register address
{
    CSN=0;
    SPI_RW_RX(0b00100000|Reg_Add);
    SPI_RW_RX(Value);
    SPI_RW_RX(Value);
    SPI_RW_RX(Value);
    SPI_RW_RX(Value);
    SPI_RW_RX(Value);
    CSN=1;
    delay_us(10);
}

void RF_Write3_RX(unsigned char Reg_Add, unsigned char Value)         //Function to write a value to a register address
{
    CSN=0;
    SPI_RW_RX(0b00100000|Reg_Add); 
    SPI_RW_RX(Code_tay_cam2);
    SPI_RW_RX(Code_tay_cam2);
    SPI_RW_RX(Code_tay_cam2);
    SPI_RW_RX(Code_tay_cam2);  
    SPI_RW_RX(Value);

  
    CSN=1;
    delay_us(10);
}

void RF_Command_RX(unsigned char command)                            //Function to write a command
{
    CSN=0;
    SPI_RW_RX(command);
    CSN=1;
    delay_us(10);
}

void RF_Write_Address_RX(unsigned char Address1, unsigned char Address2, unsigned char Address3, unsigned char Address4)                      //Function to write TX and RX address
{
    CSN=0;
    RF_Write_RX(0x03,0b00000011);
    CSN=1;
    delay_us(10);
    CSN=0;    
    RF_Write2_RX(0x0A, Address1);
    RF_Write2_RX(0x10, Address1);
    
    RF_Write3_RX(0x0B, Address2);
    RF_Write3_RX(0x10, Address2);
    
    RF_Write3_RX(0x0C, Address3);
    RF_Write3_RX(0x10, Address3);
    
    RF_Write3_RX(0x0D, Address4);
    RF_Write3_RX(0x10, Address4);
    
}

void RF_Write_Address_RX_2(unsigned char Address1){
    CSN=0;
    RF_Write_RX(0x03,0b00000011);
    CSN=1;
    delay_us(10);
    CSN=0;       
    
    RF_Write2_RX(0x0A, Address1);
    RF_Write2_RX(0x10, Address1);  
}

void RF_Mode_RX()                                             //Function to put nRF in RX mode
{
    RF_Write_RX(0x00,0b00011111);     //CONFIG 0x00
    CE=1;
}

void RF_Config_RX()                                                  //Function to config the nRF
{
RF_Write_RX(0x1C,0b00001111);     
RF_Write_Address_RX(Code_tay_cam1, Code_tay_cam2, Code_tay_cam3, Code_tay_cam4);
RF_Write_RX(0x02,0b00001111);     //EX_RXADDR 0x02    enable data pipe 0;
RF_Write_RX(0x01,0b00001111);     //EN_AA 0x01        enable auto-acknowledgment
}

void RF_Config_RX_2(){
    RF_Write_RX(0x1C,0b00001111);
    RF_Write_Address_RX_2(Code_tay_cam1);
    RF_Write_RX(0x02,0b00000001);     //EX_RXADDR 0x02    enable data pipe 0;
    RF_Write_RX(0x01,0b00000001);     //EN_AA 0x01        enable auto-acknowledgment
}

void RF_Read_RX()                                         //Function to read the data from RX FIFO
{
   CE=0;
   CSN=1;
   delay_us(10);
   CSN=0;
   SPI_RW_RX(0b01100001);
   delay_us(10);
   data_receive.flag = SPI_Read_RX(); 
   data_receive.a = SPI_Read_RX();
   data_receive.b = SPI_Read_RX();
   data_receive.c = SPI_Read_RX();
   data_receive.d = SPI_Read_RX();
   CSN=1; 
   CE=1;
   RF_Write_RX(0x07,0b01111110);  // Clear flag
   RF_Command_RX(0b11100010);     //Flush RX
}
