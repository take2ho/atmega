#include <mega128a.h>
#include <delay.h>

flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char one =0, ten=0, hundred =0, thousand =0;
unsigned char pos = 0;


void seg_out();
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
     seg_out();    
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

void sw_key1()
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


void sw_key2()
{
 pos = pos+1;
 if(pos ==4)
 {
  pos = 0;
 }
}
      
     
                  