/*
 * 201_03_060.c
 *
 * Created: 2018-11-01 ���� 1:34:15
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>
#define FUNCSET 0x28 //Function set
#define ENTMODE 0x60
#define ALLCLR 0x01
#define DISPON 0x0c
#define LINE1 0x80
#define LINE2 0xc0
void lcd_init(void);
void lcd_string(char flash *);
void busy(void);
void command(unsigned char);
void data(unsigned char);
void gotoxy(unsigned char,unsigned char);


void main(void)
{
    lcd_init();
    command(LINE1);
    lcd_string("Hello!! World");
    command(LINE2);
    lcd_string("Atmel ATmega128");
    
while (1);
    }
    void lcd_init(void){
        DDRC = 0xff;
        PORTC &= 0xfb;
        
        delay_ms(15);
        command(0x20);
        delay_us(100);
        command(0x20);
        command(FUNCSET);
        command(DISPON);
        command(ALLCLR);
        command(ENTMODE);
        
    }   
    void lcd_string(char flash *pStr){
        while(*pStr) data(*pStr++);
    }                              
    void command(unsigned char byte){
        busy();
        PORTC = (byte & 0xf0);
        PORTC &= 0xfe;
        PORTC &= 0xfd;
        delay_us(1);
        PORTC |= 0x04;
        delay_us(1);
        PORTC &= 0xfb;
        
        PORTC = ((byte<<4)& 0xf0);
        PORTC &= 0xfe;
        PORTC &= 0xfd;
        delay_us(1);
        
        PORTC |= 0x04;
        delay_us(1);
        PORTC &= 0xfb;
    }                 
    void data(unsigned char byte){
        busy();    
        PORTC = (byte & 0xf0);
        PORTC |= 0x01;
        PORTC &= 0xfd;
        delay_us(1);
        PORTC |= 0x04;
        delay_us(1);
        PORTC &= 0xfb;
        
        PORTC = ((byte<<4)&0xf0);
        PORTC |= 0x01;
        PORTC &= 0xfd;
        delay_us(1);
        PORTC |= 0x04;
        delay_us(1);
        PORTC &= 0xfb;
    }                 
    void busy(void){
        delay_ms(2);
    }               
    void gotoxy(unsigned char x_os, unsigned char y_os){
        unsigned char pos_pos;
        pos_pos = (0x80|x_os)|(0x40 * y_os);
        command(pos_pos);
    }



