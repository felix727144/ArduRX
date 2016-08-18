#include "Mirf.h"
#include "MirfHardwareSpiDriver.h"
typedef uint8_t u8;
//uint8_t tAddr[5]={0x13,0x88,0x46,0x57,0x76};
uint8_t tAddr[5]={0x13,0x88,0x46,0x57,0x76};
static const u8 binding_adr_rf[5]={0x12,0x23,0x23,0x45,0x78}; // fixed binding ids for all planes
static const u8 bind_ch=81;
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("setup begin");
  Mirf.spi = &MirfHardwareSpi;
  Mirf.channel=81;
 // Mirf.payload=4;
  Mirf.init();
  Mirf.setRADDR(tAddr);
  long nul=0;
//   #define CONFIG      0x00
//#define EN_AA       0x01
//#define EN_RXADDR   0x02
//#define SETUP_AW    0x03
//#define SETUP_RETR  0x04
//#define RF_CH       0x05
//#define RF_SETUP    0x06
//#define STATUS      0x07
//#define OBSERVE_TX  0x08
//#define CD          0x09
//#define RX_ADDR_P0  0x0A
//#define RX_ADDR_P1  0x0B
//#define RX_ADDR_P2  0x0C
//#define RX_ADDR_P3  0x0D
//#define RX_ADDR_P4  0x0E
//#define RX_ADDR_P5  0x0F
//#define TX_ADDR     0x10
//#define RX_PW_P0    0x11
//#define RX_PW_P1    0x12
//#define RX_PW_P2    0x13
//#define RX_PW_P3    0x14
//#define RX_PW_P4    0x15
//#define RX_PW_P5    0x16
//#define FIFO_STATUS 0x17

          Mirf.writeRegister(0x00, (u8 *) "\x40\x4B\x01\xE2", 4);
         Mirf.writeRegister(0x01, (u8 *) "\xC0\x4B\x00\x00", 4);
         Mirf.writeRegister(0x02, (u8 *) "\xD0\xFC\x8C\x02", 4);
         Mirf.writeRegister(0x03, (u8 *) "\xF9\x00\x39\x21", 4);
         Mirf.writeRegister(0x04, (u8 *) "\xC1\x96\x9A\x1B", 4);
         Mirf.writeRegister(0x05, (u8 *) "\x24\x06\x7F\xA6", 4);
         Mirf.writeRegister(0x06, (u8 *) &nul, 4);
         Mirf.writeRegister(0x07, (u8 *) &nul, 4);
         Mirf.writeRegister(0x08, (u8 *) &nul, 4);
         Mirf.writeRegister(0x09, (u8 *) &nul, 4);
         Mirf.writeRegister(0x0A, (u8 *) &nul, 4);
         Mirf.writeRegister(0x0B, (u8 *) &nul, 4);
         Mirf.writeRegister(0x0C, (u8 *) "\x00\x12\x73\x00", 4);
         Mirf.writeRegister(0x0D, (u8 *) "\x46\xB4\x80\x00", 4);
         Mirf.writeRegister(0x0E, (u8 *) "\x41\x10\x04\x82\x20\x08\x08\xF2\x7D\xEF\xFF", 11);
         Mirf.writeRegister(0x04, (u8 *) "\xC7\x96\x9A\x1B", 4);
         Mirf.writeRegister(0x04, (u8 *) "\xC1\x96\x9A\x1B", 4);

Mirf.config();
  
  Serial.println("setup end");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t buf[16]={0};
  
  if(Mirf.dataReady()){
    Mirf.getData(buf);
    for(int i=0;i<16;i+=4){
      Serial.print(*(uint32_t *)(buf+i));Serial.print(",");
    }
    Serial.println("");
  }else{
    //Serial.println("loop");  
  }
  
  delay(10);
}
