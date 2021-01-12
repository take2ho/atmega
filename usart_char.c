#include <mega128.h> 
#include <stdio.h>
#include <delay.h>

#include <stdlib.h>

char rx_flag =1;
int rd, dd=0;

unsigned char RX0_CH()
{
 while(!(UCSR0A&(1<<RXC0)));
 rx_flag=1;     
 rd = UDR0; 
 dd = 0;
 
 if(rd>='0' && rd<='9')
 {
  dd = rd - '0'; 
  }
 else if(rd>='a' && rd <= 'f') 
 {
 dd = rd - 'a' + 10;
 }
 else if(rd >='A' && rd<='F')
 {
  dd = rd - 'A' + 10;
  }                   
 return dd;
}

void main()
{
 unsigned char rd,dd = 0;    
 unsigned char rx_buf;
 DDRB = 0xFF;     
 DDRF = 0x0F;        
 
   
 PORTF = 0b0001;
 PORTB = ~(seg_pat[dd]);
 
 UCSR0A = 0x0;
 UCSR0B=(1<<RXEN0) | (1<<TXEN0);
 UCSR0C = 0b0110;
 UBRR0H = 0;
 UBRR0L = 103;    
 
 
 

 while(1){ 
 
 /*
 rd = UDR0;
 
 if(rd>='0' && rd<='9')
 {
  dd = rd - '0'; 
  }
 else if(rd>='a' && rd <= 'f') 
 {
 dd = rd - 'a' + 10;
 }
 else if(rd >='A' && rd<='F')
 {
  dd = rd - 'A' + 10;
  }                        
  */
  rx_buf = RX0_CH();    
   if(rx_flag)
   {   
   
     PORTB = ~(seg_pat[rx_buf]);
     rx_flag=0;
  

  
    
 
    }
 
 };    
 
 
 


}

