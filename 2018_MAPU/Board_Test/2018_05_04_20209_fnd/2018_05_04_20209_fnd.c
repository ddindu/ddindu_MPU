/*
 * 2018_05_04_20209_fnd.c
 *
 * Created: 2018-05-08 ���� 8:07:45
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

#define Q0 PORTB.0
#define Q1 PORTB.1
#define Q2 PORTB.2
#define Q3 PORTB.3

    unsigned char fnd[10]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xd8, 0x80, 0x98};

void main(void)
{
    int i;
    PORTA=0x00;
    DDRA=0xff;
    PORTB=0x00;
    DDRB=0xff;
        
    while (1)
    { 
        for(i=0;i<=9999;i++){
            PORTA=fnd[i%1000/100];
            Q0=1,Q1=1,Q2=0,Q3=1;
            delay_ms(50);
            
            PORTA=fnd[i%100/10];
            Q0=1,Q1=0,Q2=1,Q3=1;
            delay_ms(50);
            
            PORTA=fnd[i%10/1];
            Q0=0,Q1=1,Q2=1,Q3=1;
            delay_ms(2);
        }
    }
}
