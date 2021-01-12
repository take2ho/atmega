#include <mega128a.h>
#include <delay.h>

unsigned char led = 0x01;
unsigned int cnt = 0;
unsigned int one = 0, two = 0;

void main(void)
{
    
    DDRC = 0xFF;  
     

    PORTC = led;   
                     
     /*
    TIMSK = 0x01;  //TOIE0 =1(overflow interrupt enable
    TCCR0 = 0x04;  //normal mode, ck/64
    TCNT0 = 0x6;  //timer/counter0 first set      1/16us*64*(256-6) = 1ms
    SREG = 0x80;   //interrupt enable    
    */
     TIMSK = 0x04;
    TCCR1A = 0x0;
    TCCR1B = 0x05;
    TCCR1C = 0x0;   
    TCNT1 = 49911;
    SREG = 0x80;
    
while (1)
    {  
    }
     
     
}

/*interrupt [TIM0_OVF] void timer0(void)
{
 TCNT0 = 0x6;
 cnt++;
 if(cnt == 500)
 {
       led = led<<1;
       if(led == 0b10000)
       { led = 0x01;}         
       PORTC = led;
       cnt = 0;    
 }
}      */

interrupt [TIM1_OVF] void timer1(void)
{
 TCNT1 = 49911;
 led = (led<<1);
 if(led == 0xFF)
 {
  led = 0x01;
 }           
 PORTC = led;
}