#include <mega128a.h>   //atmega128 �������
#include <delay.h>  //������ ���


unsigned char fnd[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90};  //0~9����  
unsigned char fnd_ch[4] = {0xfe,0xfd,0xfb,0xf7};    //fnd ���� ����
unsigned char n1 = 0, n10 = 0, n100 = 0, n1000 = 0;     //�ڸ��� ���� ����
unsigned char status = 0;   //fnd ���ú����� ���� ����

#define SW1 PINB.0  //sw1 �� PINB1 �� �̿�
#define SW2 PINB.1  //sw2 �� PINB2 �� �̿�

void outpost()
{
    PORTC=fnd[n1%10];      //1�� �ڸ��� ���
    PORTF=fnd_ch[0];    //FND1 
    delay_ms(1);    //�����ð�++++
           
    PORTC=fnd[n10%10];     //10�� �ڸ��� ���
    PORTF=fnd_ch[1];    //FND2 
    delay_ms(1);    //�����ð�
    
    PORTC=fnd[n100%10];    //100�� �ڸ��� ���
    PORTF=fnd_ch[2];    //FND3 
    delay_ms(1);    //�����ð�
        
    PORTC=fnd[n1000%10];    //1000�� �ڸ��� ���
    PORTF=fnd_ch[3];    //FND4
    delay_ms(1);    //�����ð�
    
    PORTF = 0xff;   //��ư�� ������ fnd�� �� ����   

}                                

void main(void)
{
    DDRC = 0xff;    //��Ʈ C ��¼���  
    DDRD = 0x00;    //��Ʈ D ��¼���
    DDRF = 0xff;    //��Ʈ F ��¼���
    
    while (1)                       
    {       
        outpost();  //����� ���� �Լ�
          
        if(SW1==0){    //SW1������               
            delay_ms(50);   //�����ð�
            
            while(SW1!=1);  //SW1�� ���� ���� ���� ���ϰ�, ���� ����
            
            switch (status%4+1)    //���� �ڸ��� �������� ����
            {
                case 1: n1 = n1+1; break;   //1�ΰ�� 1�� �ڸ����� +1 
                case 2: n10 = n10+1; break;   //2�ΰ�� 10�� �ڸ����� +1
                case 3: n100 = n100+1; break;   //3�ΰ�� 100�� �ڸ����� +1
                case 4: n1000 = n1000+1; break;   //4�ΰ�� 1000�� �ڸ����� +1
                    
                default: break;                     
            }                 
        }                       
        if(SW2==0){   //SW2�� ������            
            delay_ms(50);   //�����ð�
            
            while(SW2!=1);     //SW2�� ���� ���� ������ ���ϰ�, ���� ����
            status = status + 1;    //�ڸ��� ��ġ +1       
        }            
    }
}