#include <mega128.h>
#include <delay.h>

void main(void)
{
    unsigned char led = 0xFF;
    DDRC = 0xFF;  
    PORTC = led;   
 
    while (1)
    {  
  
        led = led << 1;     //1111 1010
        led = led | 0x01;  // 1111 1100   0000 0001 == 1111 1101
        if(led == 0xFF) led = 0xFE;
        PORTC = led;      
        delay_ms(500);

    }
      

}