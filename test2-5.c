#include <mega128.h>
#include <delay.h>

void main()
{
 unsigned char sw; 
 int i;
 
 DDRC = 0xFF;
 DDRA = 0x0;
 PORTC = 0xFF;
 
 while(1)
 {
    sw = PINA & 0b0000011;
     if(sw == 0)
     {
        for(i=0;i<5;i++)
        {
          PORTC = 0x00;
          delay_ms(300);
          PORTC = 0xFF; 
          delay_ms(300);
        }
     } 
  }              
  

}