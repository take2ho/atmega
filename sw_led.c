#include <mega128a.h>

void main()
{
 unsigned char sw;
 
 DDRC = 0xFF;
 DDRE = 0x0;
 
 PORTC = 0xFF;
 
 while(1)
 {
  sw = PINE & 0b0010000;
  if(sw == 0)
  {
   PORTC = 0xFF;
  }            
  else
  {
   PORTC = 0x0;
  }
 }

}