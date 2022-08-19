/*  17. If you RTOS supports idle task hooking, write a program to demonstrate it   */


#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/event_groups.h>

//when other task are not running the idle task will run
uint32_t ulIdleCycleCount = 0;
TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;
TaskHandle_t xHandle_3;

void sensortask_1(void *pvparameters)
{
    uint32_t count=0;
    while(1)
    {
        count++;
        printf("SENSOR TASK  RUNNING \n");
        if(count==5)
        {
            vTaskDelete(NULL);
        }
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void Alarmtask_1(void *pvparameters)
{ 
    uint32_t count=0;
    while(1)
    {
        count++;
        printf("ALARM TASK RUNNING \n");
        if(count==7)
        {
            vTaskDelete(NULL);
        }
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void idletask(void *pv)                                              //idle task
{
    while(1)
    {
        ulIdleCycleCount++;
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    
}
void app_main()
{
    BaseType_t foridle; 
    BaseType_t result;
    
    foridle=xTaskCreatePinnedToCore(idletask,"idle_task",4096,NULL,0,&xHandle_3,0);   //idle task created and pin to cpu core 0
    if(foridle==pdPASS)
    {
        printf("idle task created and added to cpu core 0\n");
    }
    result=xTaskCreate(sensortask_1,"sensortask_1",2048,NULL,15,&xHandle_1);
    if(result==pdPASS)
    {
        printf("sensortask created\n");
    }
    result=xTaskCreate(Alarmtask_1,"Alarmtask_1",2048,NULL,5,&xHandle_2);
    if(result==pdPASS)
    {
        printf("Alarmtask created\n");
    }
    while(1)
    {
        printf("IDLE SPARE %d\n",ulIdleCycleCount);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
