#include <mega128a.h>
#include <delay.h>

flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char seg_on[4] = {0b0001, 0b0010, 0b0100, 0b1000};




int cnt = 0;

void main(void)
{
    
    DDRC = 0xFF;     
    DDRF = 0xFF;
    
    TIMSK = 0b01000000;
    TCCR2 = 0x04;
    TCNT2 = 6;
    SREG = 0x80;
    
while (1)
    {  
    
    
    
    }
     
     
}
interrupt [TIM2_OVF] void timer2(void)
{
 int one=0, ten=0, hundred=0, thousand = 0;
 TCNT2 = 0x6;
 cnt++;
 if(cnt == 500)
 {         
    one++;     
 
  if(one ==10)
  { 
   ten = ten+1;
   one = 0;
  }    
  if(ten ==10)
  {  
   hundred += 1;
   ten = 0;
  }    
  if(hundred ==10)
  {     
   thousand+=1;
   hundred = 0;
  }    
  if(thousand ==10)
  {
   thousand = 0;
  }               
    
    
 
 


      
 
 
  
     
 
 PORTF = ~(seg_on[(cnt%4)]);   
 switch(cnt%4)
 {
  case 0:
    PORTB = ~(seg_pat[one]);
    break;   
  case 1:
    PORTB = ~(seg_pat[ten]);
    break;   
  case 2:
    PORTB = ~(seg_pat[hundred]);
    break; 
  case 3:
    PORTB = ~(seg_pat[thousand]);
    break; 
    
 }         
      cnt = 0;
 
  }     
 
   
 
 
 
}

