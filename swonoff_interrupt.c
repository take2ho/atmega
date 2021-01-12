#include <mega128.h>
#include <stdio.h>
#include <delay.h>

unsigned char led = 0x01;


void main()
{
 
 DDRC = 0xFF;
 PORTC = led;      
   
 EIMSK = 0b00110000;
 EICRB = 0b1010;
 SREG = 0x80;
 
 while(1)
 {  
    
   
    
    
 
 }

}
interrupt [EXT_INT4] void sw1_on(void)
{
 led = led << 1;
 if(led==0x00) led = 0x01;
 PORTC = led;  
}
interrupt [EXT_INT5] void sw2_on(void)
{
 led = led >> 1;
 if(led==0x00) led = 0x80;
 PORTC = led;
}

