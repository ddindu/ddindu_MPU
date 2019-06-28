/*
 * LCD1_30203.c
 *
 * Created: 2019-04-15 ���� 1:47:42
 * Author: Administrator
 */

#include <mega128a.h>   //atmega128�� ����ϱ� ����

#asm
    .equ __lcd_port=0x1b    //lcd �� ��ƮA�� ���
#endasm

#include <lcd.h>    //lcd �Լ�
#include <delay.h>  //delay �Լ�

void main(void)
{
lcd_init(16);   //lcd ����� �ʱ�ȭ�Լ�
while (1)
    {        
        lcd_gotoxy(0,0);    //���ڰ� ���� ��ġ ����
        lcd_putsf("Hi");    //Hi �� ���
        delay_ms(700);    //�����ð�
        lcd_clear();    //lcd Ŭ����
        
        lcd_gotoxy(0,1);    //���ڰ� ���� ��ġ ����
        lcd_putsf("Kang Jin Su");   //Kang Jin Su �� ���
        delay_ms(700);  //�����ð�       
        _lcd_ready();   //lcd ����� ������ ������ ���� �غ�
        _lcd_write_data(0x01);  //LCD IR�� �����͸� write��
        
    }
}