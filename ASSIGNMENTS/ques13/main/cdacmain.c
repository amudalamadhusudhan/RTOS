/* 13. Does your RTOS provide APIs to collect task statistics. If yes, list the statistics parameters that are collected and write a program to display the runtime task statistics?   */


#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTaskLog_1;
TaskHandle_t xHandleTaskLog_2;
eTaskState x;

void task_1(void *pvparameters)
{
    while(1)
    {
        printf("TASK 1 RUNNING\n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void task_2(void *pvparameters)
{
    uint32_t count=0;
    while(1)
    {
        count++;
        printf("TASK 2 RUNNING\n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        if(count==5)
        {
            vTaskDelete(NULL);
        }
    }
}
void app_main()
{

    //y=uxTaskGetNumberOfTasks();

    BaseType_t result;
    
    result=xTaskCreate(task_1,"task_1",1024,NULL,5,&xHandleTaskLog_1);

    if(result==pdPASS)
    {
        printf("task_1 created\n");
    }
    result=xTaskCreate(task_2,"task_2",1024,NULL,5,&xHandleTaskLog_2);

    if(result==pdPASS)
    {
        printf("task_2 created\n");
    }
    while(1)
    {
     x=eTaskGetState( xHandleTaskLog_2 );
     switch(x)
     {
         case eRunning:
             printf("TI IS RUNNING\n");
             break;
         case eReady:
             printf("IT IS READY\n");
             break;
         case eDeleted:
             printf("IT IS DELETED\n");
             break;
         case eBlocked:
             printf("IT IS BLOCKED\n");
             break;
         case eSuspended:
             printf("IT IS SUSPEND\n");
             break;
         default:
             printf("UNKNOW STATE\n");
             break; 
        }  
     printf("STATE :%d\n",x);  
     vTaskDelay(1000/portTICK_PERIOD_MS);
    }

}
