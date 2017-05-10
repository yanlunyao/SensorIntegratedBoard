#ifndef __SYS_H
#define __SYS_H	 

/* Includes ------------------------------------------------------------------*/
#include "hw_config.h"
#include "port.h"
#include "ostmr.h"
#include "osqtmr.h"

/* Exported macro --------------------------------------------------------*/		


							
///* Exported constants --------------------------------------------------------*/							
////IO口操作宏定义
//#define BITBAND(addr, bitnum)         ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
//#define MEM_ADDR(addr)                *((volatile unsigned long  *)(addr)) 
//#define BIT_ADDR(addr, bitnum)        MEM_ADDR(BITBAND(addr, bitnum)) 
////IO口地址映射
//#define GPIOA_ODR_Addr    (GPIOA_BASE+20) //0x40020014
//#define GPIOB_ODR_Addr    (GPIOB_BASE+20) //0x40020414 
//#define GPIOC_ODR_Addr    (GPIOC_BASE+20) //0x40020814 
//#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40020C14 
//#define GPIOE_ODR_Addr    (GPIOE_BASE+20) //0x40021014 
//#define GPIOF_ODR_Addr    (GPIOF_BASE+20) //0x40021414    

//#define GPIOA_IDR_Addr    (GPIOA_BASE+16) //0x40020010 
//#define GPIOB_IDR_Addr    (GPIOB_BASE+16) //0x40020410 
//#define GPIOC_IDR_Addr    (GPIOC_BASE+16) //0x40020810 
//#define GPIOD_IDR_Addr    (GPIOD_BASE+16) //0x40020C10 
//#define GPIOE_IDR_Addr    (GPIOE_BASE+16) //0x40021010 
//#define GPIOF_IDR_Addr    (GPIOF_BASE+16) //0x40021410 
////IO口操作,只对单一的IO口!
////确保n的值小于16!
//#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
//#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

//#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
//#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

//#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
//#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

//#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
//#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

//#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
//#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

//#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
//#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

///* definition of return value */
//#define	RETURN_FAILURE                  0
//#define RETURN_SUCCESS_RES              1
//#define RETURN_SUCCESS_NONE             2

////! This is the default status printing mechanism
//#define ZKRT_LOG(title, fmt, ...)                                  				\
//  if ((title))                                                            \
//  {                                                                       \
//    int len = (sprintf(zkrt_log_buf, "%s %s,line %d: " fmt,    						\
//        (title) ? (title) : "NONE", __func__, __LINE__, ##__VA_ARGS__));  \
//    if ((len != -1) && (len < sizeof(zkrt_log_buf)))                                      	\
//      printf("%s", zkrt_log_buf);                                         \
//    else                                                                  \
//      printf("ERROR: log printer inner fault\n");           							\
//  }
//#define LOG_PRINTF_UCHAR	//开启打印16进制数
//#define LOG_NOTICE_IDATA  //重要提示，在产品代码考虑打印的log数据		
////#define LOG_NOTICE_DATA   //普通提示	 //zkrt_need_mask
//#define LOG_ERROR_DATA
////#define LOG_DEBUG_DATA //zkrt_need_mask
////#define LOG_WARNING_DATA //zkrt_need_mask	
//#ifdef LOG_DEBUG_DATA
//#define LOG_DEBUG "DEBUG"
//#else
//#define LOG_DEBUG 0
//#endif

//#ifdef LOG_ERROR_DATA
//#define LOG_ERROR "ERROR"
//#else
//#define LOG_ERROR 0
//#endif

//#ifdef LOG_WARNING_DATA
//#define LOG_WARNING "WARNING"
//#else
//#define LOG_WARNING 0
//#endif

//#ifdef LOG_NOTICE_DATA
//#define LOG_NOTICE "NOTICE"
//#else
//#define LOG_NOTICE 0
//#endif

//#ifdef LOG_NOTICE_IDATA
//#define LOG_INOTICE "IMPORT_NOTICE"
//#else
//#define LOG_INOTICE 0
//#endif

//extern char zkrt_log_buf[200];

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Delay(__IO uint32_t nTime);

#endif
