/*
 * 201_03_059.c
 *
 * Created: 2018-11-01 ���� 12:27:02
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

#asm
.equ __lcd_port = 0x1B
#endasm

#include <lcd.h>
#include <stdio.h>

char floor1[] = "1floor";char floor2[] = "2floor";
char floor3[] = "3floor";char floor4[] = "4floor";
char *data=0; char floor5[] = ".*. Hello! .*.";         

int j,k;


void main(void)
{
    data = floor1;
    EICRB = 0xaa;
    EIMSK = 0xf0;
    SREG |= 0x80;
    
    lcd_init(25);
    lcd_clear();
    
while (1)
    {
    lcd_clear();
    delay_ms(100);
    lcd_gotoxy(0,0);
    lcd_puts(data);
    
    for(j=0;j<10;j++){
        delay_ms(350);
        _lcd_ready();
        _lcd_write_data(0x1c);
    }                         
    lcd_clear();
    delay_ms(100);
    lcd_gotoxy(10,1);
    
    lcd_puts(data);
    for(k=10;k>=0;k--){
        delay_ms(350);
        _lcd_ready();
        _lcd_write_data(0x18);
    }
    }
}
interrupt [EXT_INT4] void ext4 (void)
{
    data = floor1;
    lcd_clear();
    delay_ms(100);
    if(j==8){
        lcd_gotoxy(k,1);
    }   else{
            lcd_gotoxy(j,0);
    }                       
    lcd_puts(data);
}
interrupt [EXT_INT5] void ext5 (void)
{
    data = floor2;
    lcd_clear();
    delay_ms(100);
    if(j==8){
        lcd_gotoxy(k,1);
    }   else{
            lcd_gotoxy(j,0);
    }                       
    lcd_puts(data);
}
interrupt [EXT_INT6] void ext6 (void)
{
    data = floor3;
    lcd_clear();
    delay_ms(100);
    if(j==8){
        lcd_gotoxy(k,1);
    }   else{
            lcd_gotoxy(j,0);
    }                       
    lcd_puts(data);
}
interrupt [EXT_INT7] void ext7 (void)
{
    data = floor4;
    lcd_clear();
    delay_ms(100);
    if(j==8){
        lcd_gotoxy(k,1);
    }   else{
            lcd_gotoxy(j,0);
    }                       
    lcd_puts(data);
}



