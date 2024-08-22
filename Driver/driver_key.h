#ifndef __KEY_H
#define __KEY_H	 
#include "bsp.h"
#include "FreeRTOS_board.h"
/**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
#define KEY1 PAin(8)
#define KEY2 PCin(9)
#define KEY3 PDin(12)








void KEY_Init(void);          //按键初始化
u8 click_N_Double (u8 time);  //单击按键扫描和双击按键扫描
u8 click(void);               //单击按键扫描
u8 Long_Press(void);           //长按扫描  
#endif  
