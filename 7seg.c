#include <mega128a.h>
#include <delay.h>

void main(void)
{
    
   // unsigned char m,val;
    DDRB = 0xFF;
    DDRF = 0xFF;
    
    
while (1)
    {   
        PORTF = 0b0001;
        PORTB = 0b0;
        delay_ms(500);    
        
        PORTF = 0b0010;
        PORTB = 0b0;
        delay_ms(500); 
        
        PORTF = 0b0100;
        PORTB = 0b0;
        delay_ms(500); 
        
        PORTF = 0b1000;
        PORTB = 0b0;
        delay_ms(500); 
       
    /*
    val = 0xFE;
    for(m=0;m<7;m++)
    {
     PORTB = val;
     delay_ms(500);
     val = val<<1;   
     val = val & 0b11111110; 
    }
            */   
    
      }            
     
                  
      
     
      
     
}