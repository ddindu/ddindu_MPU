#include <mega128.h>  //atmega128�� �̿��ϱ� ����
#include <delay.h>  //������ �Լ��� �̿��ϱ� ����

#define sec 1000  //��ũ�� ����      

void main(void)
{
    DDRC = 0xff;  // ��Ʈ�� ������� ����
    
    while (1)
    {
        PORTC = 0xff;  //��ƮC �� 0xff ���
        delay_ms(sec);  // 1000��ŭ ������
        PORTC = 0xff^0x01;  //0xff�� 0x01�� XOR��
        delay_ms(sec);  // 1000��ŭ ������
    }
}