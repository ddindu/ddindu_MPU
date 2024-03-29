#include <mega128.h>  //atmega128을 이용하기 위함
#include <delay.h>  //딜레이 함수를 이용하기 위함

#define sec 1000  //매크로 선언      

void main(void)
{
    DDRC = 0xff;  // 포트를 출력으로 설정
    
    while (1)
    {
        PORTC = 0xff;  //포트C 로 0xff 출력
        delay_ms(sec);  // 1000만큼 딜레이
        PORTC = 0xff^0x01;  //0xff를 0x01과 XOR함
        delay_ms(sec);  // 1000만큼 딜레이
    }
}