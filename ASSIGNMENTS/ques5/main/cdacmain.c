/*  5. Swap the priority and observe the changes in the output. What is your conclusion on the
sequence of printing the messages.  */


#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

void task_1(void *pv)
{
    while(1)
    {
       printf("In Task1 priority....\n");
       vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}

void task_2(void *pv)
{
    while(1)
    {
       printf("In Task2 priority.....\n");
       vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}


void app_main()
{
    xTaskCreate(task_1,"task_1",1048,NULL,30,NULL);
    xTaskCreate(task_2,"task_2",1048,NULL,10,NULL);
    printf("Hello C-DAC\n");
}
