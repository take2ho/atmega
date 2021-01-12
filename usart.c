#include <mega128.h> 

void Putch(char);

void main()
{
 char string[] = "HELLO WORLD";
 char *pStr;
 
 UCSR0A = 0x0;
 UCSR0B = 0b1000;
 UCSR0C = 0b0110;
 UBRR0H = 0;
 UBRR0L = 25; //38.4k
 
 pStr = string;
   while(*pStr != 0) Putch(*pStr++);
 
 while(1){
 };

}

void Putch(char data)
{
 while((UCSR0A & 0x20) == 0x0);
 
 UDR0 = data;
}