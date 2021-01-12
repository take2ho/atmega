#include <mega128a.h>

void sw_key1();
void sw_key2();

void main()
{
 unsigned char o_sw,n_sw;
 
 DDRC = 0xFF;
 DDRE = 0x0;
 
 PORTC = 0x00;        
  o_sw = PINE & 0b110000;
 
 while(1)
 {
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

void sw_key1()
{
 PORTC = (0b00001111); 
 }


void sw_key2()
{
 PORTC = (0b11110000);
}