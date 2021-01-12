#include <mega128a.h>
#include <delay.h>

flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char msec =0, sec =0;
unsigned char run = 0;


void time_out();


void main(void)
{

    DDRB = 0xFF;
    DDRF = 0xFF;            

    EIMSK = 0b00110000;
    EICRB = 0b1010;
    SREG = 0x80;
    

   
    
    
while (1)
    { 
     time_out();  
     
       
     
     
    
    

    
      }          
                 
      
}

void time_out()
{
    if(run==1)
     {
      msec +=1;
      if(msec==100)
      {
       msec = 0;
       sec +=1;
      }        
      if(sec >59)
      {
       sec = 0;
      }
     }   
     
  PORTF = 0b0001;    //seg1(pf4=0)
  PORTB = ~(seg_pat[msec % 10]);
  delay_ms(5);    
        
  PORTF = 0b0010;
  PORTB = ~(seg_pat[msec / 10]);   
  
  delay_ms(5); 
        
  PORTF = 0b0100;
  PORTB = ~(seg_pat[sec % 10]);    
  PORTB = PORTB | 10000000;
  delay_ms(5); 
        
  PORTF = 0b1000;
  PORTB = ~(seg_pat[sec / 10]);
  delay_ms(5); 
}

void sw_key1()
{
 if(run == 0)
 {
  run = 1;
 }        
 else run=0;
}

void sw_key2()
{
    msec = 0;
    sec = 0;
}

interrupt [EXT_INT4] void sw1_on(void)
{
if(run == 0)
 {
  run = 1;
 }        
 else run=0;
}
interrupt [EXT_INT5] void sw2_on(void)
{
  msec = 0;
  sec = 0;
}


