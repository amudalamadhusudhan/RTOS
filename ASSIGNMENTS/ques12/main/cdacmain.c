/*  12. What are the APIs provided by your RTOS for enabling and disabling the interrupts? Write a program to demonstrate this capability?  */



#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/gpio.h>
#include<freertos/event_groups.h>

static portMUX_TYPE mux;
uint32_t source=0;

void task_1(void *pv)
{
    while(1)
    {
       printf("In Task1 priority......\n");
       taskENTER_CRITICAL(&mux);
       source++;
       taskEXIT_CRITICAL(&mux);
       printf("Source %d \n",source);
       vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}

void task_2(void *pv)
{
    uint32_t c=0;
    while(1)
    {
       c++;
       printf("In Task2 priority.....\n");
       printf("count %d \n",c);
       vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}


void app_main()
{
    vPortCPUInitializeMutex(&mux);
    xTaskCreate(task_1,"task_1",2048,NULL,5,NULL);
    xTaskCreate(task_2,"task_2",2048,NULL,10,NULL);
    printf("Hello C-DAC\n");
}
