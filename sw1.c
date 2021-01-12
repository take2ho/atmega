#include <mega128a.h>
#include <delay.h>

void main(void)
{
    unsigned char sw;
    DDRC = 0xFF;     
    DDRE = 0x0;
    PORTC = 0x0;  
    
while (1)
    {
      sw = PINE & 0b110000;      
        
      switch(sw)
      {
        case 0b10000: PORTC = 0xFF; break;
        case 0b100000: PORTC = 0x00; break;

        break;
      
      }
      
      /*
      if(sw == 0b10000)    
      {
      PORTC = 0xFF;
      }           
      else if(sw == 0b100000)
      {
        PORTC = 0x00;
      }            
     
     /* else if(sw == 0b1000000)  
      {
          PORTC = 0x55;
      }              */

    }
}
