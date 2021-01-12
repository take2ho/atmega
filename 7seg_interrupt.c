#include <mega128a.h>
#include <delay.h>

flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char one =0, ten=0, hundred =0, thousand =0;
unsigned char pos = 0;


void seg_out();

void main(void)
{
    
    
    DDRB = 0xFF;
    DDRF = 0xFF;            
   
    EIMSK = 0b00110000;  //인터럽트 4,5번 인에이블
    EICRB = 0b00001010;  //4,5 하강엣지
    SREG = 0x80;         //전역 인터럽트 인에이
    
    
while (1)
    { 
     seg_out();    
    

    
      }          
                 
      
}
void seg_out()
{
 PORTF = 0b0001;
 PORTB = ~(seg_pat[one]);
 delay_ms(5);    
 
 PORTF = 0b0010;
 PORTB = ~(seg_pat[ten]);
 delay_ms(5);       
 
 PORTF = 0b0100;
 PORTB = ~(seg_pat[hundred]);
 delay_ms(5);    
 
 PORTF = 0b1000;
 PORTB = ~(seg_pat[thousand]);
 delay_ms(5);
}

interrupt [EXT_INT4] void sw_key1(void)
{
   if(pos==0)
 {
  one=one+1;
  if(one ==10)
  {
   one = 0;
  }    
  }
     
 else if(pos==1)
 {
  ten=ten+1;
  if(ten ==10)
  {
   ten = 0;
  }   
  }
  
  if(pos==2)
 {
  hundred=hundred+1;
  if(hundred ==10)
  {
   hundred = 0;
  }            
  }    
  
  if(pos==3)
 {
  thousand=thousand+1;
  if(thousand ==10)
  {
   thousand = 0;
  }            
  }
}

interrupt [EXT_INT5] void sw_key2(void)
{
 pos = pos+1;
 if(pos ==4)
 {
  pos = 0;
 }
} 
 

     
                  