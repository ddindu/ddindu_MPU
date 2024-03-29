/*
 * 201_03_064.c
 *
 * Created: 2018-12-04 오후 5:27:53
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>
#include <io.h>

#asm
    .equ __lcd_port = 0x15
#endasm

#include <lcd.h>
#include <stdio.h>

typedef unsigned char hangul;

hangul font_0[8] = {0x01,0x09,0x15,0x15,0x09,0x01,0x01,0x01};
hangul font_1[8] = {0x1d,0x0b,0x0b,0x1d,0x01,0x0e,0x0a,0x0e};
hangul font_2[8] = {0x09,0x1d,0x09,0x15,0x15,0x09,0x1d,0x09};

void define_char(hangul *pc, hangul char_code){
    //hangul i,a;
    unsigned char i,a;
    a = (char_code <<3 )| 0x40; // CG RAM Address
    for(i=0;i<8;i++)
    lcd_write_byte(a++,*pc++);
}


void main(void)
{
    DDRC = 0xff;
    PORTC = 0xff;
    lcd_init(16);
    lcd_clear();
    define_char(font_0,8); // font_0 을 5로 정의   
    define_char(font_1,9); // font_1 을 6로 정의
    define_char(font_2,10); // font_2 을 7로 정의
    lcd_clear();
    lcd_gotoxy(1,0);
    lcd_putchar(5);
    lcd_putchar(6);
    lcd_putchar(7);
}
