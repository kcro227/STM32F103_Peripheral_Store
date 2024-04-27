#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "string.h"
#include "led.h"

void main(void)
{

    uart_init(115200); //��ʼ������
    PrintfInit(USART1); //�ض���printf��USART1

    delay_init();//��ʼ���ӳٺ���
    LED_Init();//��ʼ��LED��PA8
    while(1){
        LED_Blink(500);//LED��500msΪ�����˸
        
    }
}
