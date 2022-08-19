#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

void task_1(void *pv)
{
    while(1)
    {
       printf("In Task1 priority %d \n",uxTaskPriorityGet(NULL));
       vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}

void task_2(void *pv)
{
    while(1)
    {
       printf("In Task2 priority %d \n",uxTaskPriorityGet(NULL));
       vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}


void app_main()
{
    xTaskCreate(task_1,"task_1",2048,NULL,5,NULL);
    xTaskCreate(task_2,"task_2",2048,NULL,10,NULL);
    printf("Hello C-DAC\n");
}
