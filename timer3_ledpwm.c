#include <mega128a.h>
#include <delay.h>


unsigned int cnt = 0x0200;

void main(void)
{
    
    DDRB = 0xFF;   
                     
    EIMSK = 0b110000;
    EICRB = 0b1010;
    
    TCCR1A = 0b1011;
    
    TCCR1B = 0x05;
    TCCR1C = 0x0;
    TCNT1 = 0x0;
    
    OCR1CH = (cnt & 0xFF00) >> 8;
    OCR1CL = cnt & 0x0FF;
    
    SREG = 0x80;   //interrupt enable    
   
    
while (1)
    {  
    }
     
     
}

interrupt [EXT_INT4] void timer0(void)
{
 
 if(cnt> 0x50)
 {
  cnt -= -0x40;
 }            
  OCR1CH = (cnt & 0xFF00) >> 8;
  OCR1CL = cnt & 0x0FF;
 
}      
interrupt [EXT_INT5] void timer1(void)
{
  if(cnt< 0x03B0)
 {
  cnt += -0x40;
 }            
  OCR1CH = (cnt & 0xFF00) >> 8;
  OCR1CL = cnt & 0x0FF;
}      

