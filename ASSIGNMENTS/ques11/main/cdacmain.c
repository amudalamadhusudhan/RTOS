/*  11. What is the API for deleting a task? Write a program demonstrate this capability.     */


#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTaskLog_A;
TaskHandle_t xHandleTaskLog_B;
void TaskLog1(void *pvParametrs)
{
   while(1)
   {
       printf("In TaskLog1\n");
   }
   vTaskDelete(NULL);
}
void TaskLog2(void *pvParametrs)
{
   while(1)
   {
       printf("In TaskLog2\n");
   }
   vTaskDelete(NULL);
}
void app_main()
{
    BaseType_t result;
    result=xTaskCreate(TaskLog1,"TaskLog1",1024,NULL,5,&xHandleTaskLog_A);
    if(result==pdPASS)
    {
        printf("TaskLog1 Created\n");
     }
     result=xTaskCreate(TaskLog2,"TaskLog2",1024,NULL,2,&xHandleTaskLog_B);
    if(result==pdPASS)
    {
        printf("TaskLog2 Created\n");
     }
}
