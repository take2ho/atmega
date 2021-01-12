#include <mega128a.h>
#include <delay.h>

void main(void)
{
    DDRC = 0xFF;  
    PORTC = 0x55;  
    
while (1)
    {
      PORTC = PORTC ^ 0x01;
      delay_ms(500);

    }
}
