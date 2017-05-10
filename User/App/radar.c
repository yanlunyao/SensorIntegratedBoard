/**
  ******************************************************************************
  * @file    radar.c 
  * @author  ZKRT
  * @version V1.0
  * @date    9-May-2017
  * @brief   雷达避障传感器数据解析
	*					 + (1) init
	*                       
  ******************************************************************************
  * @attention
  *
  * ...
  *
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/
#include "radar.h"

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
  * @brief  传感器返回的数据包解析
  * @param  
  * @note   
  * @retval 解析成功返回 1，失败返回 0
  */
uint8_t radar_parse(uint8_t *packet, uint16_t packet_len, uint16_t *distance)
{
	radarData info;
	uint16_t start_seq = (packet[1] << 8)|packet[0];
	uint16_t end_seq = (packet[13] << 8)|packet[12];
	uint16_t messageid_seq = (packet[3] << 8)|packet[2];
	
	if(packet_len !=14)
	{
		return 0;
	}	
	if(start_seq != 0xAAAA)
	{
		return 0;
	}
	if(messageid_seq != 0x70C)
	{
		return 0;
	}	
	if(end_seq != 0x5555)
	{
		return 0;
	}
	info.id = packet[4];
	info.rcs = packet[5]*0.5-50;
	info.range = (packet[6]*0x100+packet[7])*0.01;
//	info.rollcount = 0;
//	info.snr = packet[11]-127;
	return 1;	
}
/**
*@
*/
