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
 UCSR0B = 0b1000;
 UCSR0C = 0b0110;
 UBRR0H = 0;
 UBRR0L = 103;                // 25 : 38.4K  103 : 9600



  //  a = a/2.0;

   

    ftoa(a,7,str);                              // float를 string로 변환      

 
   //  printf( "%c[1;31;47m",ESC );        // 제어문자 전송        
    
  //   printf("Hello World \r\n");  
        printf("%f  \r\n", a);      
        printf("%s  \r\n", str);       
    
    
    while(1)
    {
       ++count; 
      
        
        /*
                         

        printf(" %s \r\n" ,str); 

     

         // 메뉴화면에서 Project => Config => C compiler => (s)printf Features 에서  float,witdth,precision 선택



         


        if(count > 10)
        {
             delay_ms(1000); 
             printf( "%c[2J", ESC );     // 화면클리어       
             count = 0;
        }         */

    }
}
