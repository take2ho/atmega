#include <mega128.h>
#include <stdio.h>
#include <delay.h>

#include <stdlib.h>


#define  ESC 27

void main(void)
{  
    int count = 0;

    float a= 12.34567;

    char str[10];
    
     // USART 초기화
    UCSR0A = 0x0;
    UCSR0B = 0b00001000;     // 송신 인에이블 TXEN = 1
    UCSR0C = 0b00000110;     // 비동기 데이터 8비트 모드      
    UBRR0H = 0;                   // X-TAL = 16MHz 일때, BAUD = 38.4K
    UBRR0L = 103;                  // 25 : 38.4K  103 : 9600



    a = a/2.0;

   

    ftoa(a,7,str);                              // float를 string로 변환      

 
    printf( "%c[1;32;47m",ESC );        // 제어문자 전송
    
    while(1)
    {
       ++count; 
      
        printf("        Hello World \r\n");



        printf(" %s \r\n" ,str); 

     

         // 메뉴화면에서 Project => Config => C compiler => (s)printf Features 에서  float,witdth,precision 선택



        printf(" %f  \r\n", a);    


        if(count > 10)
        {
             delay_ms(1000); 
             printf( "%c[2J", ESC );     // 화면클리어       
             count = 0;
        } 

    }
}

