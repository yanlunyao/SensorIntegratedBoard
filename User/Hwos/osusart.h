/**
  ******************************************************************************
  * @file    
  * @author  
  * @version 
  * @date    
  * @brief  
  ******************************************************************************
  * @copy
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __OSUSART_H
#define __OSUSART_H

#include "hw_usart.h"

#define USART1_COM		0
#define USART2_COM		1
#define USART3_COM		2
#define USART4_COM		3

#define RADIO_UCOM				USART1_COM
#define TOFLEFT_UCOM		  USART2_COM
#define TOFRIGHT_UCOM		  USART3_COM
#define TOFBACK_UCOM		  USART4_COM

scommReturn_t  t_osscomm_ReceiveMessage(uint8_t  *rxData, uint16_t *rxLen, USART_TypeDef* COM);  //upper layer usart receive function  
scommReturn_t  t_osscomm_sendMessage(uint8_t  *txData, uint16_t txLen, USART_TypeDef* COM); //upper layer usart send function  
void os_usart_init(void);

#endif 
