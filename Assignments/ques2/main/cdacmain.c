/*    2. What is the mechanism used to make a task periodic for the RTOS you are using? Write a
program to make a task periodic with periodicity of 500ms.   */



#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

void task_1(void *pv)
{
    while(1)
    {
       printf("In Task1 priority %d \n",uxTaskPriorityGet(NULL));
       vTaskDelay(500/portTICK_PERIOD_MS);
     }
}

void app_main()
{
    xTaskCreate(task_1,"task_1",2048,NULL,10,NULL);
    printf("Main Task\n");
}
