#ifndef MBED_UWP_LOG_H
#define MBED_UWP_LOG_H

#include "hal_ramfunc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WIFI_LOG_ERR
//#define WIFI_LOG_WRN
//#define WIFI_LOG_DBG
//#define WIFI_LOG_INF
//#define WIFI_DUMP

#ifdef  WIFI_LOG_ERR
#define LOG_ERR(fmt, ...) do {\
            uwp_temp_printf("%s"fmt"\r\n", __func__, ##__VA_ARGS__);\
	}while(0)
#else
#define LOG_ERR(fmt, ...)
#endif

#ifdef  WIFI_LOG_WRN
#define LOG_WRN(fmt, ...) do {\
		uwp_temp_printf("%s"fmt"\r\n", __func__, ##__VA_ARGS__);\
	}while(0)
#else
#define LOG_WRN(fmt, ...)
#endif

#ifdef  WIFI_LOG_DBG
#define LOG_DBG(fmt, ...) do {\
		uwp_temp_printf(fmt"\r\n", ##__VA_ARGS__);\
	}while(0)
#else
#define LOG_DBG(fmt, ...)
#endif

#ifdef  WIFI_LOG_INF
#define LOG_INF(fmt, ...) do {\
		uwp_temp_printf(fmt"\r\n",##__VA_ARGS__);\
	}while(0)
#else
#define LOG_INF(fmt, ...)
#endif

#ifdef  WIFI_DUMP
#define DUMP_DATA(buff, len) do {\
	        u8_t *data = (u8_t *)buff;\
		    for(int i=1;i<=len;i++){\
				printf("%02x ",data[i-1]);\
				if(i%10 == 0)\
				uwp_temp_printf("\r\n");\
		    	}\
		    printf("\r\n");\
	}while(0)
#else
#define DUMP_DATA(buff, len)
#endif

#define WIFI_ASSERT(expression,fmt,...) do {\
            if(!(expression)){\
            	uwp_temp_printf("fatal err:%s   ",__func__);\
            	uwp_temp_printf(fmt"\r\n",##__VA_ARGS__);\
            }\
       } while(0)

#define printk uwp_temp_printf

#ifdef __cplusplus
}
#endif

#endif

