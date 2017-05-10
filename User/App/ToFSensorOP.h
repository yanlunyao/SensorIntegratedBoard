#ifndef TOFSENDOR_OP
#define TOFSENDOR_OP


//根据用户平台自定义字长
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;
typedef char S8;
typedef short S16;
typedef long S32;

#define	SENSOR_PACKET_START 		0x0a  //数据报头
#define	SENSOR_DATA_LEN 			15		//数据输出大小
typedef struct RO_DATA
{
	U16	distance;
	U16	precision;
	U16	magnitude;
	U8	magnitude_exp;
	U8	ambient_adc;
}sensorData;


//外部函数声明
//extern void enableEXINT0(void);//开启外部中断触发
//extern void disableEXINT0(void);//关闭外部中断
//extern void uart_write(U8 *writeBuff, U8 len);//串口写,非中断方式
//extern void uart_read(U8 *readBuff, U8 len, U8 timeoutSec);//串口读，非中断方式

//接口声明
//void ToF_continuousStop(void);//停止连续测量
//U8 ToF_SingleshotCapture(sensorData *dbuf);//单步测量
//U8 ToF_Get_DeviceInfo(U8 *data_buff);//获取传感器信息
void ToF_ContinuousStart(void);//开始连续测量
//U8 ToF_Set_DistanceOffset(S16 offset_mm);//设置距离偏移值
//U8 ToF_Set_Filter(S16 val);//设置数据滤波器灵敏度
//U8 ToF_Get_AFETemp(U16 *afe_temp);//获取AFE温度值
U8 ToF_parse(U8 *packet, U16 packet_len, U16 *distance);
#endif
