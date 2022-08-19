/*     3. Find the APIs in your RTOS that provides timestamp and use it to print the periodic task.
Observe the jitter in the timestamp vs the periodicity. Enhance the code to 10 periodic tasks
with different periodicity. Futher observe the jitter in each of the task.      */


#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

volatile TickType_t x;

void task_1(void *pv)
{
    while(1)
    {
       printf("In Task1.....\n");
       x=xTaskGetTickCount();
       printf("task1:%d\n",x);
       vTaskDelay(100/portTICK_PERIOD_MS);
     }
}

void task_2(void *pv)
{
    while(1)
    {
       printf("In Task2.....\n");
       vTaskDelay(200/portTICK_PERIOD_MS);
     }
}

void task_3(void *pv)
{
    while(1)
    {
       printf("In Task3.....\n");
       vTaskDelay(300/portTICK_PERIOD_MS);
     }
}

void task_4(void *pv)
{
    while(1)
    {
       printf("In Task4.....\n");
       vTaskDelay(400/portTICK_PERIOD_MS);
     }
}

void task_5(void *pv)
{
    while(1)
    {
       printf("In Task5.....\n");
       vTaskDelay(500/portTICK_PERIOD_MS);
     }
}

void task_6(void *pv)
{
    while(1)
    {
       printf("In Task6.....\n");
       vTaskDelay(600/portTICK_PERIOD_MS);
     }
}

void task_7(void *pv)
{
    while(1)
    {
       printf("In Task7.....\n");
       vTaskDelay(700/portTICK_PERIOD_MS);
     }
}

void task_8(void *pv)
{
    while(1)
    {
       printf("In Task8.....\n");
       vTaskDelay(800/portTICK_PERIOD_MS);
     }
}

void task_9(void *pv)
{
    while(1)
    {
       printf("In Task9.....\n");
       vTaskDelay(900/portTICK_PERIOD_MS);
     }
}

void task_10(void *pv)
{
    while(1)
    {
       printf("In Task10.....\n");
       vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}

void app_main()
{
    xTaskCreate(task_1,"task_1",2048,NULL,5,NULL);
    xTaskCreate(task_2,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_3,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_4,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_5,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_6,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_7,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_8,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_9,"task_2",2048,NULL,5,NULL);
    xTaskCreate(task_10,"task_2",2048,NULL,5,NULL);
    printf("Hello C-DAC\n");
}
