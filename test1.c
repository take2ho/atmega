/*
 * test1.c
 *
 * Created: 2020-12-01 ¿ÀÈÄ 4:20:59
 * Author: PROCESSOR
 */

#include <mega128a.h>
#include <delay.h>

void main(void)
{
    DDRC = 0xFF;
while (1)
    {
      PORTC = 0x55;
      delay_ms(500);
      PORTC = 0xAA;
      delay_ms(500);

    }
}
