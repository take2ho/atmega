#include <mega128a.h>
#include <delay.h>

void main(void)
{
    unsigned char o_sw, n_sw;
    unsigned char led = 0x01;
    DDRC = 0xFF;     
    DDRE = 0x0;
    PORTC = led;   
    o_sw = PINE & 0b10000;
    
while (1)
    {
      n_sw = PINE & 0b10000;               
      if(o_sw ==0 && n_sw !=0)
      {
       led = led<<1;
      
       if(led == 0b10000)
       { led = 0x01;}         
       PORTC = led;
      }            
      o_sw = n_sw;
                  
      
      
     /*  PORTC = 0b0000;
      delay_ms(500);
      PORTC = 0b0001;
      delay_ms(500);   
      PORTC = 0b0010;
      delay_ms(500);        
      PORTC = 0b0100;
      delay_ms(500);
     PORTC = 0b1000;
      delay_ms(500);        */
      }
      
     
}
