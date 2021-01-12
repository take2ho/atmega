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
 while(1){        
 rx_buf=RX0_ch();
 if(rx_flag)
 {  
    if(rx_buf>='a' && rx_buf <='z')
    {
        printf("%c", rx_buf-'a'+'A');
    }
    else if(rx_buf>='A' && rx_buf <='Z')
    {
        printf("%c", rx_buf-'A'+'a');
    }                          
    else if(rx_buf>='0' && rx_buf <='9')
    {
        printf("%c", rx_buf);
    }
    rx_flag = 0;   
 }
 }
 };



