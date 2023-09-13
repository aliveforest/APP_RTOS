/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : FreeRTOS.h
**     Project     : APP_RTOS
**     Processor   : S32K144_100
**     Component   : FreeRTOS
**     Version     : Component SDK_S32K1xx_15, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K1xx_15
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-09-13, 17:11, # CodeGen: 13
**     Contents    :
**         xCoRoutineCreate               - BaseType_t xCoRoutineCreate( crCOROUTINE_CODE pxCoRoutineCode, UBaseType_t...
**         crDELAY                        - #define crDELAY( xHandle, xTicksToDelay );
**         crQUEUE_SEND                   - #define crQUEUE_SEND( xHandle, pxQueue, pvItemToQueue, xTicksToWait, pxResult );
**         crQUEUE_RECEIVE                - #define crQUEUE_RECEIVE( xHandle, pxQueue, pvBuffer, xTicksToWait, pxResult );
**         crQUEUE_SEND_FROM_ISR          - #define crQUEUE_SEND_FROM_ISR( pxQueue, pvItemToQueue,...
**         crQUEUE_RECEIVE_FROM_ISR       - #define crQUEUE_RECEIVE_FROM_ISR( pxQueue, pvBuffer, pxCoRoutineWoken );
**         vCoRoutineSchedule             - void vCoRoutineSchedule(void);
**         xEventGroupCreate              - EventGroupHandle_t xEventGroupCreate( void );
**         xEventGroupClearBits           - EventBits_t xEventGroupClearBits(EventGroupHandle_t xEventGroup,const...
**         xEventGroupClearBitsFromISR    - BaseType_t xEventGroupClearBitsFromISR(EventGroupHandle_t xEventGroup, const...
**         vEventGroupDelete              - void vEventGroupDelete(EventGroupHandle_t xEventGroup);
**         xEventGroupGetBits             - EventBits_t xEventGroupGetBits(EventGroupHandle_t xEventGroup);
**         xEventGroupGetBitsFromISR      - EventBits_t xEventGroupGetBitsFromISR(EventGroupHandle_t xEventGroup);
**         xEventGroupSetBits             - EventBits_t xEventGroupSetBits(EventGroupHandle_t xEventGroup, const...
**         xEventGroupSetBitsFromISR      - BaseType_t xEventGroupSetBitsFromISR(EventGroupHandle_t xEventGroup, const...
**         xEventGroupSync                - EventBits_t xEventGroupSync(EventGroupHandle_t xEventGroup, const EventBits_t...
**         xEventGroupWaitBits            - EventBits_t xEventGroupWaitBits(EventGroupHandle_t xEventGroup,const...
**         vQueueAddToRegistry            - void vQueueAddToRegistry(QueueHandle_t xQueue,const char * pcName);
**         xQueueAddToSet                 - BaseType_t xQueueAddToSet(QueueSetMemberHandle_t...
**         xQueueCreate                   - QueueHandle_t xQueueCreate(UBaseType_t uxQueueLength, UBaseType_t uxItemSize);
**         xQueueCreateSet                - QueueSetHandle_t xQueueCreateSet(const UBaseType_t uxEventQueueLength);
**         vQueueDelete                   - void vQueueDelete(QueueHandle_t xQueue);
**         xQueueIsQueueEmptyFromISR      - BaseType_t xQueueIsQueueEmptyFromISR(const QueueHandle_t xQueue);
**         xQueueIsQueueFullFromISR       - BaseType_t xQueueIsQueueFullFromISR(const QueueHandle_t xQueue);
**         uxQueueMessagesWaiting         - UBaseType_t uxQueueMessagesWaiting(const QueueHandle_t xQueue);
**         uxQueueMessagesWaitingFromISR  - UBaseType_t uxQueueMessagesWaitingFromISR( const QueueHandle_t xQueue );
**         xQueueOverwriteFromISR         - BaseType_t xQueueOverwriteFromISR(QueueHandle_t xQueue, const void *...
**         xQueuePeek                     - BaseType_t xQueuePeek(QueueHandle_t xQueue,void *pvBuffer, TickType_t...
**         xQueuePeekFromISR              - BaseType_t xQueuePeekFromISR(QueueHandle_t xQueue,void *pvBuffer);
**         xQueueReceive                  - BaseType_t xQueueReceive(QueueHandle_t xQueue,void *pvBuffer,TickType_t...
**         xQueueReceiveFromISR           - BaseType_t xQueueReceiveFromISR(QueueHandle_t xQueue,void *const...
**         xQueueRemoveFromSet            - BaseType_t xQueueRemoveFromSet(QueueSetMemberHandle_t...
**         xQueueReset                    - #define xQueueReset( xQueue );
**         xQueueSelectFromSet            - QueueSetMemberHandle_t xQueueSelectFromSet(QueueSetHandle_t xQueueSet,const...
**         xQueueSelectFromSetFromISR     - QueueSetMemberHandle_t xQueueSelectFromSetFromISR(QueueSetHandle_t xQueueSet);
**         xQueueSend                     - BaseType_t xQueueSend(QueueHandle_t xQueue, const void * pvItemToQueue,...
**         xQueueSendToFront              - #define xQueueSendToFront( xQueue, pvItemToQueue, xTicksToWait );
**         xQueueSendToBack               - BaseType_t xQueueSendToBack(QueueHandle_t xQueue, const void * pvItemToQueue,...
**         xQueueSendFromISR              - BaseType_t xQueueSendFromISR(QueueHandle_t xQueue, const void *...
**         xQueueSendToBackFromISR        - BaseType_t xQueueSendToBackFromISR(QueueHandle_t xQueue, const void *...
**         xQueueSendToFrontFromISR       - BaseType_t xQueueSendToFrontFromISR(QueueHandle_t xQueue, const void *...
**         uxQueueSpacesAvailable         - UBaseType_t uxQueueSpacesAvailable(const QueueHandle_t xQueue);
**         vSemaphoreCreateBinary         - #define vSemaphoreCreateBinary( xSemaphore );
**         xSemaphoreCreateBinary         - #define xSemaphoreCreateBinary();
**         xSemaphoreCreateCounting       - #define xSemaphoreCreateCounting( uxMaxCount, uxInitialCount );
**         xSemaphoreCreateMutex          - #define xSemaphoreCreateMutex();
**         xSemaphoreCreateRecursiveMutex - #define xSemaphoreCreateRecursiveMutex();
**         vSemaphoreDelete               - #define vSemaphoreDelete( xSemaphore );
**         xSemaphoreGetMutexHolder       - #define xSemaphoreGetMutexHolder( xSemaphore );
**         xSemaphoreGive                 - #define xSemaphoreGive( xSemaphore );
**         xSemaphoreGiveFromISR          - #define xSemaphoreGiveFromISR( xSemaphore, pxHigherPriorityTaskWoken );
**         xSemaphoreGiveRecursive        - #define xSemaphoreGiveRecursive( xMutex );
**         xSemaphoreTake                 - #define xSemaphoreTake( xSemaphore, xBlockTime );
**         xSemaphoreTakeFromISR          - #define xSemaphoreTakeFromISR( xSemaphore, pxHigherPriorityTaskWoken );
**         xSemaphoreTakeRecursive        - #define xSemaphoreTakeRecursive( xMutex, xBlockTime );
**         xTimerChangePeriod             - #define xTimerChangePeriod( xTimer, xNewPeriod, xTicksToWait );
**         xTimerChangePeriodFromISR      - #define xTimerChangePeriodFromISR( xTimer, xNewPeriod,...
**         xTimerCreate                   - TimerHandle_t xTimerCreate(const char *const pcTimerName,const TickType_t...
**         xTimerDelete                   - #define xTimerDelete( xTimer, xTicksToWait );
**         xTimerGetTimerDaemonTaskHandle - TaskHandle_t xTimerGetTimerDaemonTaskHandle(void);
**         pvTimerGetTimerID              - void* pvTimerGetTimerID(TimerHandle_t xTimer);
**         pcTimerGetName                 - const char * pcTimerGetName( TimerHandle_t xTimer );
**         xTimerIsTimerActive            - BaseType_t xTimerIsTimerActive(TimerHandle_t xTimer);
**         xTimerPendFunctionCall         - BaseType_t xTimerPendFunctionCall(PendedFunction_t xFunctionToPend,void *...
**         xTimerPendFunctionCallFromISR  - BaseType_t xTimerPendFunctionCallFromISR(PendedFunction_t...
**         xTimerReset                    - #define xTimerReset( xTimer, xTicksToWait );
**         xTimerResetFromISR             - #define xTimerResetFromISR( xTimer, pxHigherPriorityTaskWoken );
**         xTimerStart                    - #define xTimerStart( xTimer, xTicksToWait );
**         xTimerStartFromISR             - #define xTimerStartFromISR( xTimer, pxHigherPriorityTaskWoken );
**         xTimerStop                     - #define xTimerStop( xTimer, xTicksToWait );
**         xTimerStopFromISR              - #define xTimerStopFromISR( xTimer, pxHigherPriorityTaskWoken );
**         vTaskAllocateMPURegions        - void vTaskAllocateMPURegions(TaskHandle_t xTaskToModify, const MemoryRegion_t...
**         xTaskCreate                    - BaseType_t xTaskCreate(TaskFunction_t pvTaskCode, const char * const pcName,...
**         xTaskCreateRestricted          - BaseType_t xTaskCreateRestricted(TaskParameters_t *pxTaskDefinition,...
**         vTaskDelay                     - void vTaskDelay(const TickType_t xTicksToDelay);
**         vTaskDelayUntil                - void vTaskDelayUntil(TickType_t *const pxPreviousWakeTime,const TickType_t...
**         vTaskDelete                    - void vTaskDelete(TaskHandle_t xTaskToDelete);
**         taskDISABLE_INTERRUPTS         - #define taskDISABLE_INTERRUPTS();
**         taskENABLE_INTERRUPTS          - #define taskENABLE_INTERRUPTS();
**         taskENTER_CRITICAL             - #define taskENTER_CRITICAL();
**         taskEXIT_CRITICAL              - #define taskEXIT_CRITICAL();
**         xTaskGetApplicationTaskTag     - TaskHookFunction_t xTaskGetApplicationTaskTag(TaskHandle_t xTask);
**         xTaskGetCurrentTaskHandle      - TaskHandle_t xTaskGetCurrentTaskHandle();
**         uxTaskGetNumberOfTasks         - UBaseType_t uxTaskGetNumberOfTasks();
**         vTaskGetRunTimeStats           - void vTaskGetRunTimeStats(char * pcWriteBuffer,size_t bufSize);
**         xTaskGetSchedulerState         - BaseType_t xTaskGetSchedulerState();
**         uxTaskGetStackHighWaterMark    - UBaseType_t uxTaskGetStackHighWaterMark(TaskHandle_t xTask);
**         uxTaskGetSystemState           - UBaseType_t uxTaskGetSystemState(TaskStatus_t *const pxTaskStatusArray,const...
**         xTaskGetTickCount              - TickType_t xTaskGetTickCount();
**         xTaskGetTickCountFromISR       - TickType_t xTaskGetTickCountFromISR();
**         vTaskList                      - void vTaskList(char * pcWriteBuffer,size_t bufSize);
**         uxTaskPriorityGet              - UBaseType_t uxTaskPriorityGet(TaskHandle_t xTask);
**         vTaskPrioritySet               - void vTaskPrioritySet(TaskHandle_t xTask,UBaseType_t uxNewPriority);
**         vTaskResume                    - void vTaskResume(TaskHandle_t xTaskToResume);
**         xTaskResumeAll                 - BaseType_t xTaskResumeAll();
**         xTaskResumeFromISR             - BaseType_t xTaskResumeFromISR(TaskHandle_t xTaskToResume);
**         vTaskStepTick                  - void vTaskStepTick(const TickType_t xTicksToJump);
**         vTaskSuspend                   - void vTaskSuspend(TaskHandle_t xTaskToSuspend);
**         vTaskSuspendAll                - void vTaskSuspendAll();
**         taskYIELD                      - #define taskYIELD();
**         vTaskStartScheduler            - void vTaskStartScheduler();
**         vTaskEndScheduler              - void vTaskEndScheduler();
**         xTaskCallApplicationTaskHook   - BaseType_t xTaskCallApplicationTaskHook(TaskHandle_t xTask,void * pvParameter);
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc. 
**     Copyright 2016-2017 NXP 
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file FreeRTOS.h
** @version 01.00
*/         
/*!
**  @addtogroup FreeRTOS_module FreeRTOS module documentation
**  @{
*/         
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Directive 4.9, Function-like macro defined.
 * The macro is used for development validation.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 3.1, C comment contains C++ comment.
 * Detections are URL links from FreeRTOS header text.
 *
 */

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/



#define configUSE_PREEMPTION                     1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION  1
#define configCPU_CLOCK_HZ                       ( 80000000UL )
#define configTICK_RATE_HZ                       ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES                     ( 16 )
#define configMINIMAL_STACK_SIZE                 ( ( unsigned short ) 128 )
#define configMAX_TASK_NAME_LEN                  ( 20 )
#define configUSE_16_BIT_TICKS                   0
#define configIDLE_SHOULD_YIELD                  1
#define configUSE_TASK_NOTIFICATIONS             1
#define configUSE_MUTEXES                        1
#define configUSE_RECURSIVE_MUTEXES              1
#define configUSE_COUNTING_SEMAPHORES            1
#define configQUEUE_REGISTRY_SIZE                0
#define configUSE_QUEUE_SETS                     0
#define configUSE_TIME_SLICING                   1
#define configUSE_NEWLIB_REENTRANT               0
#define configENABLE_BACKWARD_COMPATIBILITY      1
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS  0
#define configUSE_APPLICATION_TASK_TAG           0

/* Memory allocation related definitions. */
#define configSUPPORT_STATIC_ALLOCATION          0
#define configSUPPORT_DYNAMIC_ALLOCATION         1
#define configTOTAL_HEAP_SIZE                    ( ( size_t ) 8192 )
#define configAPPLICATION_ALLOCATED_HEAP         0

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK                      0
#define configUSE_TICK_HOOK                      0
#define configCHECK_FOR_STACK_OVERFLOW           0
#define configUSE_MALLOC_FAILED_HOOK             0
#define configUSE_DAEMON_TASK_STARTUP_HOOK       0

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS            1 
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() (CPU_RunTime = 0ul) /* nothing */ /* default: use Tick counter as runtime counter */   
                                                 /* extern volatile uint32_t CPU_RunTime;  */
#define portGET_RUN_TIME_COUNTER_VALUE()         CPU_RunTime /* default: use Tick counter as runtime counter */ 
#define configUSE_TRACE_FACILITY                 1
#define configUSE_STATS_FORMATTING_FUNCTIONS     1

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES                    0
#define configMAX_CO_ROUTINE_PRIORITIES          ( 2 )

/* Software timer related definitions. */
#define configUSE_TIMERS                         1
#define configTIMER_TASK_PRIORITY                ( 14 ) 
#define configTIMER_QUEUE_LENGTH                 10
#define configTIMER_TASK_STACK_DEPTH             128

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                 1
#define INCLUDE_uxTaskPriorityGet                1
#define INCLUDE_vTaskDelete                      1
#define INCLUDE_vTaskSuspend                     1
#define INCLUDE_vTaskDelayUntil                  1
#define INCLUDE_vTaskDelay                       1
#define INCLUDE_xTaskGetSchedulerState           1
#define INCLUDE_xTaskGetCurrentTaskHandle        1
#define INCLUDE_uxTaskGetStackHighWaterMark      1
#define INCLUDE_xTaskGetIdleTaskHandle           0
#define INCLUDE_eTaskGetState                    0
#define INCLUDE_xEventGroupSetBitFromISR         1
#define INCLUDE_xTimerPendFunctionCall           1
#define INCLUDE_xTaskAbortDelay                  1
#define INCLUDE_xTaskGetHandle                   1
#define INCLUDE_xTaskResumeFromISR               1
#define INCLUDE_xQueueGetMutexHolder             1

/* Definition assert() function. */
#define configASSERT(x)                          if((x)==0) { taskDISABLE_INTERRUPTS(); for( ;; ); }   

/* Tickless Idle Mode */
#define configUSE_TICKLESS_IDLE                  0

/* Additional settings can be defined in the property Settings > User settings > Definitions of the FreeRTOS component */

/* Run time stats gathering definitions. */
#ifdef __ICCARM__
	/* The #ifdef just prevents this C specific syntax from being included in
	assembly files. */
	void vMainConfigureTimerForRunTimeStats( void );
	unsigned long ulMainGetRunTimeCounterValue( void );
#endif
#ifdef __GNUC__
	/* The #ifdef just prevents this C specific syntax from being included in
	assembly files. */
	void vMainConfigureTimerForRunTimeStats( void );
	unsigned long ulMainGetRunTimeCounterValue( void );
#endif

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
  #define configPRIO_BITS                         __NVIC_PRIO_BITS
#else
  #define configPRIO_BITS                         4
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY  (0x0F)

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	 (0x01)

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#ifndef configKERNEL_INTERRUPT_PRIORITY
  #define configKERNEL_INTERRUPT_PRIORITY         (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8-configPRIO_BITS))  
#endif
  
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#ifndef configMAX_SYSCALL_INTERRUPT_PRIORITY
  #define configMAX_SYSCALL_INTERRUPT_PRIORITY    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8-configPRIO_BITS))
#endif

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler                             SVC_Handler
#define xPortPendSVHandler                          PendSV_Handler
#define xPortSysTickHandler                         SysTick_Handler

#endif /* FREERTOS_CONFIG_H */
