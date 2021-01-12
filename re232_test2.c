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
    
     // USART �ʱ�ȭ
    UCSR0A = 0x0;
    UCSR0B = 0b00001000;     // �۽� �ο��̺� TXEN = 1
    UCSR0C = 0b00000110;     // �񵿱� ������ 8��Ʈ ���      
    UBRR0H = 0;                   // X-TAL = 16MHz �϶�, BAUD = 38.4K
    UBRR0L = 103;                  // 25 : 38.4K  103 : 9600



    a = a/2.0;

   

    ftoa(a,7,str);                              // float�� string�� ��ȯ      

 
    printf( "%c[1;32;47m",ESC );        // ����� ����
    
    while(1)
    {
       ++count; 
      
        printf("        Hello World \r\n");



        printf(" %s \r\n" ,str); 

     

         // �޴�ȭ�鿡�� Project => Config => C compiler => (s)printf Features ����  float,witdth,precision ����



        printf(" %f  \r\n", a);    


        if(count > 10)
        {
             delay_ms(1000); 
             printf( "%c[2J", ESC );     // ȭ��Ŭ����       
             count = 0;
        } 

    }
}

