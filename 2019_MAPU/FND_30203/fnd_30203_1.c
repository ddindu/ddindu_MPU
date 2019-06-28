/*
 * FND1_30203.c
 *
 * Created: 2019-04-01 ���� 2:24:45
 * Author: Administrator
 */

#include <mega128a.h>   //atmega128 ��� 
#include <delay.h>  //������ ��� 

unsigned char fnd[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90,0x88,0xfc,0xc6,0xa1,0x86,0x8e};  //0~F���� 



void output()   //output ����� �����Լ�
{
    int i,j; //����
    
    for(i=0;i<99;i++)
    {                
        for(j=0;j<49;j++){
        
        PORTC = fnd[i%10];  //���� �ڸ� ���
        PORTF = 0xfe;   //FND����
        delay_ms(1);    //�����ð�

        
        PORTC = fnd[i/10];  //���� �ڸ� ���
        PORTF = 0xfd;   //FND����
        delay_ms(1);    //�����ð�      
        
        if(i==98) PORTA = 0xfe; //99���� ������� �� LED 1 �ѱ�
        else PORTA = 0xff;  //����
        }                     
    }
}
 
void main(void)
{

    DDRF = 0xff;    //F��Ʈ ���,�ʱⰪ 
    DDRC = 0xff;    //C��Ʈ ���,�ʱⰪ 
    DDRA = 0xff;    //A��Ʈ ���,�ʱⰪ 
    

    while (1)
        {
            output();   //����� ���� �Լ�
        }
}