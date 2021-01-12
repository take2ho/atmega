#include <mega128.h>

void main()
{
 unsigned char sw;
 
 DDRC = 0xFF;
 DDRA = 0x0;
 PORTC = 0xFF;
 
 while(1)
 {
     sw = PINA & 0b0000011;
     if(sw == 1)
     {
        PORTC = 0xFF;
     }            
     else if (sw == 2)
     {
        PORTC = 0x0;
     }
 }

}