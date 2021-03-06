#ifndef __SYSTEMCONFIG_H__
#define __SYSTEMCONFIG_H__
#include "WM.h"

#define START_TIME RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);TIM_Cmd(TIM2, ENABLE)
#define STOP_TIME  TIM_Cmd(TIM2, DISABLE);RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE)

#define CLI()      __set_PRIMASK(1)  
#define SEI()      __set_PRIMASK(0)  

extern WM_HWIN root_hWin;
extern WM_HWIN mainForm_hWin;
extern WM_HWIN dialog_hWin;
extern WM_HWIN time_hWin;
extern WM_HWIN draw_hWin;
extern WM_HWIN menu_hWin;
extern WM_HWIN explain_hWin;
extern WM_HWIN clock_hWin;
extern WM_HWIN warning_hWin;
extern WM_HWIN drawLine_hWin;
extern WM_HWIN report_hWin;
extern  int myMessageType;
extern int isOrSetMessage;
extern int rotate_flag;
extern int rotateEnter_flag;
extern char *saveData[5];
extern int isOrRefreshMessage;
extern int isOrShowExplain;
extern int isOrShowSetTime;
extern char *timeData[6];
extern int isOrSetClock;
extern  int isOneCheck;
extern  int isRestartCheck;
extern int isOrSetPoint;
extern int isBeginCheck;
extern int isOrShowReport;
extern int logoCount;
extern  int isOrPrintReport;
extern  int isOrAllowCheck;
extern int isOrExitDrawLine;
extern int lastCount;
extern  char isOrCheckLogo[25];
extern  int isOrRefreshrTime;
extern  int isOrCloseEnter;
extern  int workMode;
#endif