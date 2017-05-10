/**
  ******************************************************************************
  * @file    appdistance.c 
  * @author  ZKRT
  * @version V1.0
  * @date    9-May-2017
  * @brief   避障传感器采集处理
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
#include "sys.h"
#include "osusart.h"
#include "appdistance.h"
#include "radar.h"
#include "ToFSensorOP.h"
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t distance_utbuf[USART_RX_DATA_SIZE];  //传感器串口接收处理缓存，4个探测器共用一个处理缓存，4个探测器各自有一个串口底层接收缓存
uint16_t dutbuf_len; //the actual received length of distance_utbuf
uint16_t distance10_v[4][10]={0}; //4个方向障碍物的连续10个障碍物距离数据，用来作平均过滤
uint8_t distance10_v_index[4]={0}; //distance10_v[4][10]存储的索引，每个方向都是存满10个后进行平均过滤
distance_info_t global_distance; //距离信息（经过过滤处理）
/* Private functions ---------------------------------------------------------*/
uint16_t vlaue_avg_filter(const uint16_t *value, uint16_t num);
void tof_radar_recv_handle(uint8_t *buf, uint16_t *buflen, uint8_t port, uint8_t distance_num);

/**
  * @brief  appdistance_init
  * @param  None
  * @retval None
  */
void appdistance_init(void)
{
	ToF_ContinuousStart();
}
/**
  * @brief  appdistance_prcs int main
  * @param  None
  * @retval None
  */
void appdistance_prcs(void)
{
	//handle radar
	tof_radar_recv_handle(distance_utbuf, &dutbuf_len, RADIO_UCOM, RADAR_NUM);
	//handle tof
	tof_radar_recv_handle(distance_utbuf, &dutbuf_len, TOFLEFT_UCOM, TOFLEFT_NUM);
	tof_radar_recv_handle(distance_utbuf, &dutbuf_len, TOFRIGHT_UCOM, TOFRIGHT_NUM);
	tof_radar_recv_handle(distance_utbuf, &dutbuf_len, TOFBACK_UCOM, TOFBACK_NUM);
}
/**
  * @brief  vlaue_avg_filter 去最高最低求平均值
  * @param  None
  * @retval None
  */
uint16_t vlaue_avg_filter(const uint16_t *value, uint16_t num)
{
	int i;
	uint16_t pj;
	uint16_t max,maxnum,min,minnum,sum=0;
	for(i=0; i<num; i++)
	{
		sum += value[i];
		if(i==0)
		{
			max = value[0];
			min = max;
			maxnum=1;
			minnum=1;
		}	
		else
		{
			if(value[i]>max)
			{		
				max =value[i];
				maxnum=1;
			}
			else if((value[i]==max))
			{
				maxnum++;
			}
			if(value[i]<min)
			{
				min = value[i];
				min=1;
			}
			else if((value[i]==min))
			{
				minnum++;
			}
		}
	}
	pj=(sum-max*maxnum-min*minnum)/num;
	return pj;
}
/**
  * @brief  tof_radar_recv_handle
  * @param  None
  * @retval None
  */
void tof_radar_recv_handle(uint8_t *buf, uint16_t *buflen, uint8_t port, uint8_t distance_num)
{
	char avg_enable=0;
//	if(t_osscomm_ReceiveMessage(buf, buflen, port)==SCOMM_RET_OK)
	{
		if(port == RADIO_UCOM)
		{
			if(radar_parse(buf, *buflen, &distance10_v[distance_num][distance10_v_index[distance_num]]))
				avg_enable = 1;
		}
		else
		{
			if(ToF_parse(buf, *buflen, &distance10_v[distance_num][distance10_v_index[distance_num]]))
				avg_enable = 1;
		}	
		if(avg_enable)
		{
			distance10_v_index[distance_num]++;
			if(distance10_v_index[distance_num] ==10)
			{
				distance10_v_index[distance_num] = 0;
				global_distance.distance_data[distance_num] = vlaue_avg_filter(&distance10_v[distance_num][0], 10);
				printf("distace[%x] = %x\n", distance_num, global_distance.distance_data[distance_num]);
			}
		}
	}
}
/**
*@
*/
