#ifndef __CAN_H
#define __CAN_H
#include "sys.h"

#define CAN_BUFFER_SIZE      250   //һ��Э���ռ��50���ֽڣ�������5������
#define DEVICE_SELF_TYPE     1

uint8_t CAN_Mode_Init(void);//CAN��ʼ��
uint8_t CAN1_rx_check(void);
uint8_t CAN1_rx_byte(void);
uint8_t Can_Send_Msg(uint8_t* msg,uint8_t len);						//��������
uint8_t CAN1_send_message_fun(uint8_t *message, uint8_t len);//����ָ��
#endif