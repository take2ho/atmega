#include <mega128a.h>
#include <delay.h>

flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char msec =0, sec =0;
unsigned char run = 0;


void time_out();
void sw_key1();
void sw_key2();

void main(void)
{
    unsigned char o_sw,n_sw;
    
    DDRB = 0xFF;
    DDRF = 0xFF;            
    DDRE = 0x0;
    
    o_sw = PINE & 0b110000;
   
    
    
while (1)
    { 
     time_out();  
     
       
     
     
     n_sw = PINE & 0b110000;     
     if(o_sw==n_sw)
     {
      continue;
     }         
     if(o_sw==0b110000 && n_sw==0b100000)
     {
      sw_key1();
     }          
     else if(o_sw==0b110000 && n_sw==0b010000)        
     {
      sw_key2();
     }           
     o_sw = n_sw;
    

    
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
