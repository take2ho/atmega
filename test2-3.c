#include <mega128.h>
#include <delay.h>

void main(void)
{
    DDRC = 0xFF;  
    PORTC = 0xFF;   
   
    while (1)
    {  
  
        PORTC = 0xFF;
        delay_ms(1000);
        PORTC = 0xAA;
        delay_ms(1000); 
       
    }
 
}