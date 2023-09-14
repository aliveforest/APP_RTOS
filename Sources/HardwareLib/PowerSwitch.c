/*
 * PowerSwitch.c
 *
 *  Created on: 2023年9月13日
 *      Author: dengtongbei
 */
#include "PowerSwitch.h"

void Read_User_Option(uint8_t * option);

/* 功耗管理初始化 */
void Power_Man_Init(void){
    /* Initialize Power Manager
     * -   See PowerSettings component for more info
     */
    POWER_SYS_Init(&powerConfigsArr, POWER_MANAGER_CONFIG_CNT, &powerStaticCallbacksConfigsArr, POWER_MANAGER_CALLBACK_CNT);
    RGB_LED_KEY_init();
}

volatile uint8_t option=0; /* 存储用户选项的变量 */
uint32_t frequency; /* 用于存储核心频率的变量 */
status_t retV = STATUS_SUCCESS; /* 用于显示模式变化状态的变量 */
char buffer[20]; /* 用于执行 sprintf 操作的缓冲区 */
/* 电源模式切换 */
void Power_Switch(void) {

    LPUART1_printf((const char *)MENU_MESSAGE ADD_MESSAGE); /* 打印菜单 */
    // if(option<6) ++option;
    // else option=0;
    Read_User_Option(&option);
    /* 如果选项有效，则相应配置 CPU 电源模式 */
    switch (option) {
    case '0': /* HSRUN */
        LED_Ctrl(RedLED, 0); /* red led off */
        /* 将电源模式设置为 HSRUN */
        retV = POWER_SYS_SetMode(HSRUN, POWER_MANAGER_POLICY_AGREEMENT);
        Enable_Peripherals();
        if (retV == STATUS_SUCCESS) {
            LPUART1_printf((const char*)"************************ CPU is in HSRUN.\r\n");
            LPUART1_printf((const char*)"************************ Core frequency: ");
            (void)CLOCK_SYS_GetFreq(CORE_CLOCK, &frequency); /* 获取当前核心时钟频率 */
            LPUART1_printf((const char*)"%ld[Hz] \r\n", frequency); /* 打印 CPU 频率 */
        }else {
            LPUART1_printf((const char*)"Switch HSRUN mode unsuccessfully\r\n");
        }
        break;
    case '1': /* RUN */
        LED_Ctrl(RedLED, 0); /* red led off */
        /* 将电源模式设置为RUN */
        retV = POWER_SYS_SetMode(RUN, POWER_MANAGER_POLICY_AGREEMENT);
        Enable_Peripherals();
        if (retV == STATUS_SUCCESS) {
            LPUART1_printf((const char*)"************************ CPU is in RUN\r\n");
            LPUART1_printf((const char*)"************************ Core frequency: ");
            (void)CLOCK_SYS_GetFreq(CORE_CLOCK, &frequency); /* 获取当前核心时钟频率 */
            LPUART1_printf((const char*)"%ld[Hz] \r\n", frequency); /* 打印 CPU 频率 */
        }else{
            LPUART1_printf((const char*)"Switch RUN mode failed!\r\n");
        }
        break;
    case '2': /* VLPR */
        /* 将电源模式设置为 VLPR */
        retV = POWER_SYS_SetMode(VLPR, POWER_MANAGER_POLICY_AGREEMENT);
        if (retV == STATUS_SUCCESS) {
            LPUART1_printf((const char*)"************************ CPU is in VLPR\r\n");
            LPUART1_printf((const char*)"************************ Core frequency: ");
            (void)CLOCK_SYS_GetFreq(CORE_CLOCK, &frequency); /* 获取当前核心时钟频率 */
            LPUART1_printf((const char*)"%ld[Hz] \r\n", frequency); /* 打印 CPU 频率 */
//            Close_Peripherals();
        }else {
            LPUART1_printf((const char*)"Switch VLPR mode failed!\r\n");
        }
        break;
    case '3': /* STOP1 */
        LPUART1_printf((const char*)"******** CPU is going in STOP1...\r\n");
        Close_Peripherals();
        /* 将电源模式设置为 STOP1 */
        retV = POWER_SYS_SetMode(STOP1, POWER_MANAGER_POLICY_AGREEMENT);
        if (retV == STATUS_SUCCESS) {
            LPUART1_printf((const char*)"CPU was entered STOP1 mode successfully and then woke up to exit STOP1 mode.\r\n");
            LPUART1_printf((const char*)"Current mode is RUN.\r\n");
        }else {
            LPUART1_printf((const char*)"Switch STOP1 mode failed!\r\n");
        }
        break;
    case '4': /* STOP2 */
        LPUART1_printf((const char*)"******** CPU is going in STOP2...\r\n");
        Close_Peripherals();
        /* 将电源模式设置为 STOP2 */
        retV = POWER_SYS_SetMode(STOP2, POWER_MANAGER_POLICY_AGREEMENT);
        if (retV == STATUS_SUCCESS) {
            LPUART1_printf((const char*)"CPU was entered STOP2 mode successfully and then woke up to exit STOP2 mode.\r\n");
            LPUART1_printf((const char*)"Current mode is RUN.\r\n");
        }else {
            LPUART1_printf((const char*)"Switch STOP2 mode failed!\r\n");
        }
        break;
    case '5': /* VLPS */
        LPUART1_printf((const char*)"******** CPU is going in VLPS and need interrupt to wake up CPU\r\n");
        Close_Peripherals();
        /* 将电源模式设置为 VLPS */
        retV = POWER_SYS_SetMode(VLPS, POWER_MANAGER_POLICY_AGREEMENT);
        if (retV == STATUS_SUCCESS) {
            LPUART1_printf((const char*)"CPU was entered VLPS mode successfully and then woke up to exit VLPS mode.\r\n");
            if (POWER_SYS_GetCurrentMode() == POWER_MANAGER_RUN) {
                LPUART1_printf((const char*)"Current mode is RUN.\r\n");
            }else {
                LPUART1_printf((const char*)"Current mode is VLPR.\r\n");
            }
        }else {
            LPUART1_printf((const char*)"Switch VLPS mode failed!\r\n");
        }
        break;
    default:  /* 这一声明不应达到 */
        break;
    }
    LPUART1_printf((const char *)SEPARATOR); /* 打印分隔符 */
}

/* 读取用户输入选项 */
void Read_User_Option(uint8_t * option){
    uint8_t rev = 0;
    xQueueReceive(LPUART_RX_que, &rev, delay_10);
    if (rev < '0' || rev > '5'){ /* 检查选项是否无效 */
        LPUART1_printf((const char *)"Invalid option!\r\n");
        *option = 1;
    }else {
        *option = rev;
    }
}
/* 关闭外设 */
void Close_Peripherals(void){
    PCC-> PCCn[PCC_PORTA_INDEX] &= ~PCC_PCCn_CGC_MASK; /* 关闭 PORTA 时钟 */
    PCC-> PCCn[PCC_PORTD_INDEX] &= ~PCC_PCCn_CGC_MASK; /* 关闭 PORTD时钟 */
    PCC->PCCn[PCC_LPIT_INDEX] &= ~PCC_PCCn_CGC_MASK; /* 关闭 LPIT 时钟 */
    LPUART1->CTRL =	LPUART_CTRL_RIE(0); /* 关闭 LPUART1 中断 */
    INT_SYS_DisableIRQ(LPUART1_RxTx_IRQn); /* 关闭 LPUART1 中断 */
    INT_SYS_DisableIRQ(LPIT0_Ch0_IRQn); /* 关闭 LPIT0 中断 */
} 
/* 开启外设 */
void Enable_Peripherals(void){
    PCC-> PCCn[PCC_PORTA_INDEX] |= PCC_PCCn_CGC_MASK; /* 开启 PORTA 时钟 */
    PCC-> PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK; /* 开启 PORTD时钟 */
    LPUART1_init();
    LPIT0_init();
    SPI_OLED_Init();
} 
