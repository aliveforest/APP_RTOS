/*
 * RTOS_Task.c
 *
 *  Created on: 2023年9月8日
 *      Author: dengtongbei
 */
#include "RTOS_Task.h"
/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "event_groups.h"

/* SDKincludes. */
#include "Cpu.h"
#include "HardwareLib.h"

extern TickType_t delay_10;
extern QueueHandle_t LPUART_RX_que;        /* LPUART数据接收句柄 */
QueueHandle_t semaphore_handle;
void init_fcn(void); /* 外设初始化函数 */

uint8_t *buf = NULL;
size_t free_size = 0;
/* 事件标志组 */
EventGroupHandle_t  eventgroup_handle;
#define EVENTBIT_0  (1 << 0)
#define EVENTBIT_1  (1 << 1)
/* 软件定时器 */
TimerHandle_t timer1_handle = 0;    /* 单次定时器 */
TimerHandle_t timer2_handle = 0;    /* 周期定时器 */
void timer1_callback( TimerHandle_t pxTimer );
void timer2_callback( TimerHandle_t pxTimer );
/***********************************************************************/
/* RTOS入口函数 */
void rtos_start(void){
	init_fcn(); /* 外设初始化函数 */
    eventgroup_handle = xEventGroupCreate();
    if(eventgroup_handle != NULL) {
    	LPUART1_printf("Event Group Created OK!!\r\n");
    }
	timer1_handle = xTimerCreate( "timer1", /* 单次定时器 */
									500,
									pdFALSE,
									(void *)1,
									timer1_callback );
	timer2_handle = xTimerCreate( "timer2", /* 周期定时器 */
									2000,
									pdTRUE,
									(void *)2,
									timer2_callback );
	xTaskCreate( (TaskFunction_t        ) start_task,
                 (const char *          ) "start_task",
                 (configSTACK_DEPTH_TYPE) START_TASK_STACK_SIZE,
                 (void *                ) NULL,
				 (UBaseType_t           ) START_TASK_PRIO,
                 (TaskHandle_t *        ) &start_task_handler );

    vTaskStartScheduler();  /* 启动任务和计时器。*/
}
/***********************************************************************/
/* 外设初始化函数 */
void init_fcn(void){

    CLOCK_DRV_Init(&clockMan1_InitConfig0);             /* Initialize clock     */
    PMC->REGSC |= 0x03;    /*设置 CLKBIASDIS（时钟偏置禁用位）和 BIASEN（偏置启用位），以便在 VLPR/S 模式下进一步降低功耗*/
	systick_later_init();                               /* Initialize later fcn */
	LPUART1_init();                        				/* Initialize LPUART1   */
	RGB_LED_KEY_init();                                 /* Initialize LED KEY   */
	FLASH_DRV_Init(&Flash1_InitConfig0, &flashConfig);  /* Initialize flash     */
	LPIT0_init();
	LPTMR_init();
	SPI_OLED_Init();
    Power_Man_Init();
}
/***********************************************************************/
/* 开始任务创建 */
void start_task(void){
    taskENTER_CRITICAL();               /* 进入临界区 */
    xTaskCreate( (TaskFunction_t        ) key_task,
                 (const char *          ) "key_task",
                 (configSTACK_DEPTH_TYPE) KEY_TASK_STACK_SIZE,
                 (void *                ) NULL,
                 (UBaseType_t           ) KEY_TASK_PRIO,
                 (TaskHandle_t *        ) &key_task_handler );
    xTaskCreate( (TaskFunction_t        ) show_task,
                 (const char *          ) "show_task",
                 (configSTACK_DEPTH_TYPE) SHOW_TASK_STACK_SIZE,
                 (void *                ) NULL,
                 (UBaseType_t           ) SHOW_TASK_PRIO,
                 (TaskHandle_t *        ) &show_task_handler );
//	xTaskCreate( (TaskFunction_t        ) cpu_task,
//				 (const char *          ) "cpu_task",
//				 (configSTACK_DEPTH_TYPE) CPU_TASK_STACK_SIZE,
//				 (void *                ) NULL,
//				 (UBaseType_t           ) CPU_TASK_PRIO,
//				 (TaskHandle_t *        ) &cpu_task_handler );

    vTaskDelete(NULL);
    taskEXIT_CRITICAL();                /* 退出临界区 */
}
/***********************************************************************/

/* key */
void key_task(void){

    for (;;){
//    	LPUART1_printf("key_task\r\n");
        if(SW2_key()){
			LPUART1_printf("KEY2 press!\r\n");
			LPUART1_printf("Task Notify Binary Semaphore Release!\r\n");
			xTaskNotifyGive(show_task_handler);
			xEventGroupSetBits( eventgroup_handle, EVENTBIT_0); /* 将事件标志组的bit0位置1 */
			LPUART1_printf("TimerStart!\r\n");
			xTimerStart(timer1_handle,portMAX_DELAY);
			xTimerStart(timer2_handle,portMAX_DELAY);

//			LPUART1_printf("DISABLE_INTERRUPTS!\r\n");
//			taskDISABLE_INTERRUPTS();/*关闭中断*/
//			LPUART1_printf("Wait 2s !\r\n");
//			later_ms(2000);
//			taskENABLE_INTERRUPTS();/*开启中断*/
//			LPUART1_printf("ENABLE_INTERRUPTS!\r\n");
		}
		else if(SW3_key()){
			LPUART1_printf("KEY3 press!\r\n");
			xEventGroupSetBits( eventgroup_handle, EVENTBIT_1); /* 将事件标志组的bit1位置1 */
			LPUART1_printf("TimerStop!\r\n");
			xTimerStop(timer1_handle,portMAX_DELAY);
			xTimerStop(timer2_handle,portMAX_DELAY);
//			later_ms(500);
		}

        vTaskDelay(200);
    }
}
/* show information */
void show_task(void){
	uint8_t y=0;
	size_t size_left;
    uint8_t rev;
    uint32_t TaskNotify=0;
    EventBits_t event_bit = 0;
    for (;;){
        LPUART1_printf("------APP------\r\n");
        TaskNotify = ulTaskNotifyTake(pdTRUE , delay_10);
		if(TaskNotify>0) {
			LPUART1_printf("Receive task notify ok, binary semaphore take!\r\n");
			LPUART1_printf("TaskNotify: %d\r\n", TaskNotify);
		}
//        Power_Switch(); /* 进入电源模式切换 */
    	LPUART1_printf("TOTAL_HEAP:%d\r\n", configTOTAL_HEAP_SIZE);
        size_left = xPortGetFreeHeapSize();
        LPUART1_printf("Free Heap: %d bytes\r\n", size_left);
        size_left = xPortGetMinimumEverFreeHeapSize();
        LPUART1_printf("MinimumEverFreeHeapSize: %d bytes\r\n", size_left);
        event_bit = xEventGroupWaitBits( eventgroup_handle,         /* 事件标志组句柄 */
                                           EVENTBIT_0 | EVENTBIT_1,   /* 等待事件标志组的bit0和bit1位 */
                                           pdTRUE,                    /* 成功等待到事件标志位后，清除事件标志组中的bit0和bit1位 */
                                           pdTRUE,                    /* 等待事件标志组的bit0和bit1位都置1,就成立 */
										   delay_10);			  /* 死等 */
        LPUART1_printf("Value of the wait-to event bit is: %#x\r\n",event_bit);
        SPI_OLED_ShowString(10, y++, "SPI_OLED_task",16,1);
        if(y>=50) {y=0; SPI_OLED_Clear();}
		if(xSemaphoreTake(RX_Cnt_Semph, delay_10)==pdTRUE) {
			for(;;){
				xQueueReceive(LPUART_RX_que, &rev, delay_10);
				LPUART1_printf("%c", rev);
				if(rev=='\n') { LPUART1_printf("\r\n"); break; }
			}
		}
        vTaskDelay(300);
    }
}
/* CPU 负载率计算 task */
void cpu_task(void){
    uint8_t CPU_RunInfo[400];		//保存任务运行时间信息
    for (;;) {
        memset(CPU_RunInfo,0,400);				//信息缓冲区清零
        vTaskList((char *)&CPU_RunInfo);  //获取任务运行时间信息
        LPUART1_printf("-----------------------------------------------------\r\n");
        LPUART1_printf("TaskName	     Status    Prio  StackLeft TaskNum\r\n");
        LPUART1_printf("%s", CPU_RunInfo);
        LPUART1_printf("-----------------------------------------------------\r\n");
        memset(CPU_RunInfo,0,400);				//信息缓冲区清零
        vTaskGetRunTimeStats((char *)&CPU_RunInfo);
        LPUART1_printf("TaskName	      RunCount     CPU Utilization \r\n");
        LPUART1_printf("%s", CPU_RunInfo);
        LPUART1_printf("-----------------------------------------------------\r\n\n");
        later_ms(500);
        vTaskDelay(1000);   /* 延时 */
    }
}
/* timer1的超时回调函数 */
void timer1_callback( TimerHandle_t pxTimer ){
    static uint32_t timer = 0;
    LPUART1_printf("Run times of timer1: %d\r\n",++timer);
}

/* timer2的超时回调函数 */
void timer2_callback( TimerHandle_t pxTimer ){
    static uint32_t timer = 0;
    LPUART1_printf("Run times of timer2: %d\r\n",++timer);
}
/* 进入低功耗前所需要执行的操作 */
void Pre_Sleep_Processing(void) {
	PCC-> PCCn[PCC_PORTD_INDEX] &= ~PCC_PCCn_CGC_MASK;/* Close clock for PORTD */
	PCC-> PCCn[PCC_PORTC_INDEX] &= ~PCC_PCCn_CGC_MASK;/* Close clock for PORTC */
	PCC-> PCCn[PCC_PORTA_INDEX] &= ~PCC_PCCn_CGC_MASK;/* Close clock for PORTA */
	PCC->PCCn[PCC_LPUART1_INDEX]&= ~PCC_PCCn_CGC_MASK;/* Enable clock for LPUART1 */
	PCC->PCCn[PCC_LPTMR0_INDEX] &= ~PCC_PCCn_CGC_MASK; /* 关闭LPTMR0时钟	*/
	PCC->PCCn[PCC_LPIT_INDEX]   &= ~PCC_PCCn_CGC_MASK;  /* 关闭时钟至 LPIT0 寄存器*/

}
/* 退出低功耗后所需要执行的操作 */
void Post_Sleep_Processing(void) {
	PCC-> PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;/* Enable clock for PORTD */
	PCC-> PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK;/* Enable clock for PORTC */
	PCC-> PCCn[PCC_PORTA_INDEX] |= PCC_PCCn_CGC_MASK;/* Enable clock for PORTA */
	PCC->PCCn[PCC_LPUART1_INDEX]|= PCC_PCCn_CGC_MASK;/* Enable clock for LPUART1 */
	PCC->PCCn[PCC_LPTMR0_INDEX] |= PCC_PCCn_CGC_MASK; /* 使能LPTMR0时钟	*/
	PCC->PCCn[PCC_LPIT_INDEX]   |= PCC_PCCn_CGC_MASK;  /* 使能时钟至 LPIT0 寄存器*/
}




