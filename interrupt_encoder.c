#include <mega128.h>
#include <delay.h>
 
 
unsigned char led = 0x01;
   
 
void main(void)
{
   
    DDRC = 0xFF;
    DDRD = 0x00;    // PD0,PD2 입력 설정
   
    EIMSK = 0b00000001;
    EICRA = 0b00000010;
   
    SREG  = 0b10000000;    // 전역 인터럽트 인에이블 비트 셋
   
  ;
    PORTC = led;
   
    while(1);
   
}
 
 
 
 
interrupt [EXT_INT0] void external_int0(void)
{
    if (PIND.1) // B상이 연결된 핀
    {
         led = (led<<1);
        if(led > 0xFF)
            {
              led = 0xFF;
             }   
        PORTC = led;
    }  
 
    else if (PIND.0)
    {
       led = (led>>1);
       
        if(led < 0x01)led = 0x01;
        PORTC = led;
    }  
}