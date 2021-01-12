#include <mega128.h>
#include <stdio.h>
#include <delay.h>

#include <stdlib.h>
flash unsigned char seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int i;

void main()
{
 DDRB = 0xFF;
 DDRF = 0xFF;          
 PORTF = 0b0001;  
  PORTB = ~(seg_pat[0]);

      while(1)
      {
       for(i=0;i<10;i++)
       {
        delay_ms(1000);
        PORTB = ~(seg_pat[i]);
       }
      };


}