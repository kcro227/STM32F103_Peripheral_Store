#ifndef __USART_H
#define __USART_H

#include "stdio.h"
#include "sys.h"

#define USART_REC_LEN            200    //�����������ֽ��� 200
#define EN_USART1_RX            1        //ʹ�ܣ�1��/��ֹ��0������1����
#define USE_USART_REC_IRQn       0      //ʹ�ܣ�1��/��ֹ��0�� 0ʹ��stdio.h��scanf�������� 1Ϊ����ԭ�ӵĽ���Э��
#define USE_PRINTF 1                //ʹ��printf

extern u8 USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з�
extern u16 USART_RX_STA;                //����״̬���
//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(u32 bound);
//���ڷ�������


void PrintfInit(USART_TypeDef *uarTx);

#if USE_PRINTF

int _isatty(int fd);

int _write(int fd, char *ptr, int len);

int _close(int fd);

int _lseek(int fd, int ptr, int dir);

int _read(int fd, char *ptr, int len);

#endif

void USART_SEND(USART_TypeDef *USARTx, u8 *buf);

#endif


