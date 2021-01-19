#include <mega128.h>
#include <stdio.h>
#include <delay.h>


void main()
{
 
 DDRB = 0xFF;
 
 
 PORTB = 0x00;        
 
 
 while(1)
 {  
    
    PORTB = 0xFF;
    delay_ms(1000);     
    
    PORTB = 0x00;
    delay_ms(1000);
    
    
 
 }

}
