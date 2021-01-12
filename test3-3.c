#include <mega128.h> 
#include <delay.h>
#include <stdio.h>

int i;
int a = 3;

void main()
{
 UCSR0A = 0x0;
 UCSR0B = 0b1000;
 UCSR0C = 0b0110;
 UBRR0H = 0;
 UBRR0L = 25; //38.4k       
 
 DDRC = 0xFF;
 PORTC = 0xFF;   
 delay_ms(1000);
 PORTC = 0x00;
 for(i=1;i<10;i++)
 {
    printf("%d X %d = %d\n\r",a,i,a*i);
 }

 
 while(1){
 };

}

