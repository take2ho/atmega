#include <mega128a.h>
#include <delay.h>

void main(void)
{
    
    unsigned char led = 0x01;
    DDRC = 0xFF;     
    
    PORTC = led;   
    
    //���ͷ�Ʈ �ʱ�ȭ
    EIMSK = 0b10000;
    EICRB = 0b010;
    SREG = 0x80;
    
while (1)
    {
               
    
      }            
     
                  
      
     
      
     
}

interrupt [EXT_INT4] void sw1_on(void)
{
    led = led<<1;
    if(led == 10000)
    {
     led = 0x01;
    }           
    PORTC = led;
}