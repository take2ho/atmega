
#include <delay.h>
#include <mega128a.h>        
	    // 과거 현재     과거 현재 
#define QS0 0x00   // 00  00 S0 -> S0 무변화 
#define QS1 0x01   // 00  01 S0 -> S1 +증가  check
#define QS3 0x03   // 00  11 S0 -> S2 ? 
#define QS2 0x02   // 00  10 S0 -> S3 -감소  check

#define QS4 0x04   // 01  00 S1 -> S0 -감소 
#define QS5 0x05   // 01  01 S1 -> S1 무변화
#define QS7 0x07   // 01  11 S1 -> S2 +증가
#define QS6 0x06   // 01  10 S1 -> S3 ?

#define QSC 0x0C   // 11  00 S2 -> S0 ?
#define QSD 0x0D   // 11  01 S2 -> S1 -감소 
#define QSF 0x0F   // 11  11 S2 -> S2 무변화 
#define QSE 0x0E   // 11  10 S2 -> S3 +증가 

#define QS8 0x08   // 10  00 S3 -> S0 +증가
#define QS9 0x09   // 10  01 S3 -> S1 ?
#define QSB 0x0B   // 10  11 S3 -> S2 -감소 
#define QSA 0x0A   // 10  10 S3 -> S3 무변화 
 
void main(void)
{
  unsigned char t, cq, pq;
  unsigned counter = 1;
  DDRC = 0xFF;
  DDRA = 0x00;    
  while(1)
  {
    cq = PINA & 0x03;  
    
    t = (pq << 2) | cq;
    pq = cq; 
    
	switch(t)
    {    
      case QS1: counter++; break;  
      case QS2: counter--; break;  
      case QS4: counter--; break;  
      case QS7: counter++; break;  
      case QSD: counter--; break;
      case QSE: counter++; break; 
      case QS8: counter++; break;
      case QSB: counter--; break; 
    }
    
    if(counter >0xFF) counter = 0xFF;
	PORTC = counter;
   } 
}
 
 
 