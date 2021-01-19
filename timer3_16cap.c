#include <mega128a.h>
#include <delay.h>


int disp;
void time_out();
flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};


void main(void)
{

    DDRB = 0xFF;
    DDRF = 0xFF; 
    DDRE = 0x0F;           

    ETIMSK = 0b00100000;   //입력캡쳐 인터럽트
    TCCR3A = 0x0;          //일반모드
    TCCR3B = 0x05;         //1024분주
    
    TCCR3C = 0x0;          //하강캡쳐
    TCNT3H = 0;            //TCNT 초기값 0
    TCNT3L = 0;
    SREG = 0x80;
    

   
    
    
while (1)
    { 
     time_out();  
     
       
     
     
    
    

    
      }          
                 
      
}

void time_out()
{
    int h1,h2,h3,h4;
    
    h1 = disp & 0x000F;
    h2 = (disp >> 4) & 0x000F;   
    h3 = (disp >> 8) & 0x000F;       
    h4 = (disp >> 12) & 0x000F;
     
  PORTF = 0b0001;    //seg1(pf4=0)
  PORTB = ~(seg_pat[h1]);
  delay_ms(5);    
        
  PORTF = 0b0010;
  PORTB = ~(seg_pat[h2]);   
  
  delay_ms(5); 
        
  PORTF = 0b0100;
  PORTB = ~(seg_pat[h3]);    
  PORTB = PORTB | 10000000;
  delay_ms(5); 
        
  PORTF = 0b1000;
  PORTB = ~(seg_pat[h4]);
  delay_ms(5); 
}


interrupt [TIM3_CAPT] void capt3(void)
{
  disp = ICR3L + (ICR3H << 8);
}