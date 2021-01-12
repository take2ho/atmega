#include <mega128.h>
#include <stdio.h>
#include <delay.h>


void main()
{
 
 DDRC = 0xFF;
 
 
 PORTC = 0x00;        
 
 
 while(1)
 {  
    
    PORTC = 0x05;
    delay_ms(1000);     
    
    PORTC = 0x02;
    delay_ms(1000);
    
    
 
 }

}
