#include <mega128a.h>
#include <delay.h>

unsigned char led = 0x01;


int cnt = 0;

void main(void)
{
    
     DDRC = 0xFF;  
     

    PORTC = led;        

    
    TIMSK = 0b01000000;
    TCCR2 = 0x04;
    TCNT2 = 6;
    SREG = 0x80;
    
while (1)
    {  

    
    }
     
     
}
interrupt [TIM2_OVF] void timer2(void)
{


TCNT2 = 0x6;
 cnt++;    
 if(cnt == 100)
 {
       led = led<<1;
       if(led == 0b00000000)
       { led = 0x01;}         
       PORTC = led;
       cnt = 0;    
 }

 
 
 
}

