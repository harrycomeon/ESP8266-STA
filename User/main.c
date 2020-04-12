#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "esp8266.h"



uint8_t flag;

 int main ( void )
{
	/* 初始化 */
  USART_Config(); 	//初始化串口1                      
	ESP8266_Init ();   //初始化WiFi模块使用的接口和外设（使用串口2）
  ESP8266_StaTcpClient_UnvarnishTest ();//WiFi模块设置
	
	
	//LED驱动配置  GPIOA pin0口
	GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
		

  while ( 1 )
	{ 
switch(flag)
{
	case 'a': GPIO_SetBits(GPIOA,GPIO_Pin_0 );break;//开灯
	
	case 'c': GPIO_ResetBits(GPIOA,GPIO_Pin_0 );break;//关灯
}	
	
	}

}


