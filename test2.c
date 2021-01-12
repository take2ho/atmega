#include <mega128.h>

void main(void)
{
    unsigned char sw;
    
    DDRC = 0xFF;  

    DDRA = 0x0;
 

     

    PORTC = 0x00;   
                     
 
    
while (1)
    {  
    sw = PINA & 0b0000001;
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