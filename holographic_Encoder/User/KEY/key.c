#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"
#include "usart.h"
#include "WM.h"
#include "GUI.h"
#include "my_win.h"
#include "systemConfig.h"
#include "warning_dialog.h"
#include "drawLine_dialog.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//按键输入 驱动代码		   
//技术论坛:www.openedv.com
//修改日期:2011/11/28 
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) ALIENTEK  2009-2019
//All rights reserved
//********************************************************************************
 extern int rotate_flag;
 int selectEnd = 1;


void KEY_Init(void) //IO初始化
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	//init GPIOA  上拉输入
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//PA.1 .2 .3 .4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//init GPIOA  上拉输入
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		/* EXTI line(PB0) mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3); 
  EXTI_InitStructure.EXTI_Line = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure); 
	
  /* Configure one bit for preemption priority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* 配置P[A|B|C|D|E]0为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
		
}


u8 KEY_Scan(void)
{	 
	static u8 key_up=1;//按键按松开标志	
 
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||KEY3==0))
	{
		delay_ms(15);//去抖动 
		key_up=0;
		if(KEY0==0)
		{
				
			return 1;
		}
		else if(KEY1==0)
		{
	 	 
			return 2;
		}
		else if(KEY2==0)
		{
	 
			return 3;
		}
		else if(KEY3==0)
		{
	 
			return 4;
		}
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&KEY3==1)key_up=1; 	    
 
	return 0;// 无按键按下
}



void E11_init() {
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	//init GPIOA  上拉输入
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_15;//PA.11 .12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		/* EXTI line(PB0) mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11|GPIO_PinSource15); 
  EXTI_InitStructure.EXTI_Line = EXTI_Line11|EXTI_Line15;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure); 
	
  /* Configure one bit for preemption priority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* 配置P[A|B|C|D|E]0为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

void selectLogoCount(int count) {   //32
	int i=43,j=40;
	int row= count/5, rank = count%5;
				for (i=43+row*39;i<75+row*39;i++)
			{
				for (j=8+rank*64;j<40+rank*64;j++) {
					if(count == 9) 
						LCD_L0_XorPixel(j,i-1);
					else
						LCD_L0_XorPixel(j,i);

					
				}
			}
}

void setOrLogoCount(int count,int flag) { 
	int i=43,j=40;
	int row= count/5, rank = count%5;
	int bgColor=0;
	if(count == 9){
		bgColor =	LCD_L0_GetPixelIndex(8+rank*64,43+row*39-1);
	}else{
		bgColor =	LCD_L0_GetPixelIndex(8+rank*64,43+row*39);
	}
			if(flag==1) {
				if(bgColor==0x01){
					return;
				}
			}else {
				if(bgColor==0x00){
					return;
				}
			}
				for (i=43+row*39;i<75+row*39;i++)
			{
				for (j=8+rank*64;j<40+rank*64;j++) {

					if(count == 9) 
						LCD_L0_XorPixel(j,i-1);
					else
						LCD_L0_XorPixel(j,i);

					
				}
			}
}

void rotate(void) {  //logo图标选择
//	static int lastCount=0;
			//旋转编码器
		if(rotate_flag == 1) {
			
			if(KEY_A == 0) {
					delay_us(5);
            if(KEY_B == 1)
            {
							logoCount++;
							if(logoCount==25) {
								logoCount = 0;
							}
							 printf("right\r\n");
            }else {
							if(KEY_B == 0) {
								logoCount--;
								if(logoCount == -1) {
									logoCount = 24;
								}
								printf("left\r\n");
							}

						}
						selectLogoCount(lastCount);
						selectLogoCount(logoCount);
						lastCount = logoCount;
						rotate_flag = 0;
					}
		}
		selectEnd = 1;

}

void send_rotate_message(void) {
	WM_HWIN activeHwin;
			//旋转编码器
		if(rotate_flag == 1) {
				selectEnd = 0;
			if (myMessageType == MY_MESSAGE_ID_LOGO) {
//						WM_SelectWindow(mainForm_hWin);
						WM_SetFocus(mainForm_hWin);
			//		GUI_StoreKeyMsg(MY_MESSAGE_ID_ENCODER0,1);
						GUI_SendKeyMsg(MY_MESSAGE_ID_ENCODER0,1);
			//		WM_SetFocus(mainForm_hWin);
			//		GUI_Clear();
			}else if (myMessageType == MY_MESSAGE_ID_MESSAGE_SETTING) {
							WM_SetFocus(dialog_hWin);
							GUI_SendKeyMsg(MY_MESSAGE_ID_ENCODER0,1);
			}else if (myMessageType == MY_MESSAGE_ID_SYSTEM_SETTING) {
							WM_SetFocus(menu_hWin);
							GUI_SendKeyMsg(MY_MESSAGE_ID_ENCODER0,1);
			}else if (myMessageType == MY_MESSAGE_ID_SYSTEM_TIME) {
							WM_SetFocus(clock_hWin);
							GUI_SendKeyMsg(MY_MESSAGE_ID_ENCODER0,1);
			}else if (myMessageType == MY_MESSAGE_ID_DRAW_LINE) {
								WM_SetFocus(drawLine_hWin);
								GUI_SendKeyMsg(MY_MESSAGE_ID_ENCODER0,1);
			}else if(myMessageType==MY_MESSAGE_ID_CHECK_REPORT) {
							WM_SetFocus(report_hWin);
							GUI_SendKeyMsg(MY_MESSAGE_ID_ENCODER0,1);
				} else {
				printf("逻辑出问题了");
			}
		}
}

//旋转编码器按下确认操作
void send_enter_message(void) {
		if(KEY4 == 0) {
			delay_ms(10);
			if(KEY4== 0) {
				printf("enter\r\n");
				if (myMessageType == MY_MESSAGE_ID_LOGO) {
					if(isOrAllowCheck==1){
						if(isOrCheckLogo[logoCount]==0) {
								isOrShowReport=0;
								isBeginCheck=1;
								isOrCloseEnter=1;

						}else {
								isOrCloseEnter=1;
								isOrShowReport=1;
						}

					}else {
						isOrCloseEnter=1;
						isOrShowReport=1;
					}
				}else if (myMessageType == MY_MESSAGE_ID_MESSAGE_SETTING) {
								WM_SetFocus(dialog_hWin);
								GUI_SendKeyMsg(MY_MESSAGE_ID_ENTER,1);
				}else if (myMessageType == MY_MESSAGE_ID_SYSTEM_SETTING) {
								WM_SetFocus(menu_hWin);
								GUI_SendKeyMsg(MY_MESSAGE_ID_ENTER,1);
				}else if (myMessageType == MY_MESSAGE_ID_SYSTEM_EXPLAIN) {
											isOrCloseEnter=1;
						WM_SetFocus(explain_hWin);
						GUI_SendKeyMsg(MY_MESSAGE_ID_ENTER,1);
				}else if (myMessageType == MY_MESSAGE_ID_SYSTEM_TIME) {
								WM_SetFocus(clock_hWin);
								GUI_SendKeyMsg(MY_MESSAGE_ID_ENTER,1);
				}else if (myMessageType == MY_MESSAGE_ID_WARNING) {
								WM_SetFocus(warning_hWin);
								GUI_SendKeyMsg(MY_MESSAGE_ID_ENTER,1);
				}else if(myMessageType==MY_MESSAGE_ID_DRAW_LINE) {
											isOrCloseEnter=1;
//						WM_SetFocus(drawLine_hWin);
//							GUI_SendKeyMsg(MY_MESSAGE_ID_ENTER,1);
				}else if(myMessageType==MY_MESSAGE_ID_CHECK_REPORT) {
							isOrCloseEnter=1;
							WM_SetFocus(report_hWin);
							GUI_SendKeyMsg(MY_MESSAGE_ID_ENTER,1);
				}
				else {
					printf("逻辑出问题了");
				}
			}
		}
		printf("enter11  \r\n");
		rotateEnter_flag = 0;
}


