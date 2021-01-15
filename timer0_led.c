#include <mega128a.h>
#include <delay.h>

unsigned char led = 0x01;
unsigned int cnt = 0;
unsigned int one = 0, two = 0;

void main(void)
{
    
    DDRC = 0xFF;  
     

    PORTC = led;   
                     
    
    TIMSK = 0x01;  //TOIE0 =1(overflow interrupt enable
    TCCR0 = 0x07;  //normal mode, ck/64
    TCNT0 = 0x0;  //timer/counter0 first set      1/16us*1024*(256)     16.384us마다 인터럽트 발
    SREG = 0x80;   //interrupt enable    
   
    
while (1)
    {  
    }
     
     
}

interrupt [TIM0_OVF] void timer0(void)
{
 TCNT0 = 0x0;
 cnt++;
 if(cnt == 1)
 {
       led = led<<1;
       if(led == 0b00000000)
       { led = 0x01;}         
       PORTC = led;
       cnt = 0;    
 }
}      
