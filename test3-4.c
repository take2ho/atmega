#include <mega128.h> 
#include <delay.h>
#include <stdio.h>

unsigned char rx_flag = 1;

unsigned char RX0_ch()
{
 while((UCSR0A & 0x80) == 0x0);
 rx_flag = 1;
 return UDR0;
}
void main()
{
 char rx_buf;
 
 UCSR0A = 0x0;
 UCSR0B = 0b11000;
 UCSR0C = 0b0110;
 UBRR0H = 0;
 UBRR0L = 25; //38.4k       
 
 DDRC = 0xFF;
 PORTC = 0xFF;

 
 while(1){        
 rx_buf=RX0_ch();
 if(rx_flag)
 { 
  
    if(rx_buf == 'o')
    {
        PORTC = 0xFF; 
        printf("o"); 
    }
    else if (rx_buf == 'f')
    {
        PORTC = 0x00;               
        printf("f");
    }    
    rx_flag = 0;   
 }
 }
 };



