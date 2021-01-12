#include <mega128a.h>
#include <delay.h>
flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char led = 0x01;
unsigned int cnt = 0;
unsigned int one = 0, two = 0;

void main(void)
{
    
    DDRC = 0xFF;  
    DDRB = 0xFF;
    DDRF = 0xFF;    

    PORTC = led;   
                     
     /*
    TIMSK = 0x01;  //TOIE0 =1(overflow interrupt enable
    TCCR0 = 0x04;  //normal mode, ck/64
    TCNT0 = 0x6;  //timer/counter0 first set      1/16us*64*(256-6) = 1ms
    SREG = 0x80;   //interrupt enable    
    */
     TIMSK = 0b01000000;
    TCCR2 = 0x04;
    TCNT2 = 6;
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

interrupt [TIM2_OVF] void timer2(void)
{
 TCNT2 = 0x6;
 cnt++;
 if(cnt == 100)
 {           
        one++;   
        if(one==10)
        {
         one = 0;   
         two++;
        }      
        if(two == 10)
        {
         two = 0;
        }        
        
        
         PORTF = 0b0001;
        PORTB = ~(seg_pat[one]);   
        PORTF = 0b0010;
        PORTB = ~(seg_pat[two]);
      /* led = led<<1;
       if(led == 0b10000)
       { led = 0x01;}         
       PORTC = led;           */
       cnt = 0;    
 }
} 
