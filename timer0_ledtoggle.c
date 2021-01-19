#include <mega128a.h>
#include <delay.h>

unsigned char led = 0x00;
unsigned int cnt = 0;

void main(void)
{
    
    DDRC = 0xFF;  
     

    PORTC = led;   
                     
    
    TIMSK = 0x01;  //TOIE0 =1(overflow interrupt enable
    TCCR0 = 0x04;  //normal mode, ck/64
    TCNT0 = 6;  //timer/counter0 first set      1/16us*64*(256-6)     1ms마다 인터럽트 발생
    SREG = 0x80;   //interrupt enable    
   
    
while (1)
    {  
    }
     
     
}

interrupt [TIM0_OVF] void timer0(void)
{
 TCNT0 = 6;
 cnt++;
 if(cnt == 500)
 {
       led = led^0xFF;
             
       PORTC = led;
       cnt = 0;    
 }
}      
