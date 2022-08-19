/* 16. Write a RTOS application to demonstrate the use of changing priority    */

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

/* FreeRTOS allows us to set priorities for tasks, which allows the scheduler to preempt lower priority tasks with higher priority tasks. 
The scheduler is a piece of software inside the operating system in charge of figuring out which task should run at each tick. */
TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;


void sensortask_1(void *pvparameters)
{
    int sensor_data=0;
    while(1)
    {
        sensor_data++;
        printf("SENSOR TASK  RUNNING: %d\n",sensor_data);
        vTaskDelay(100/ portTICK_PERIOD_MS);
        
        
    }
}
void Alarmtask_1(void *pvparameters)
{
    int alarm_data=0; 
    while(1)
    {
        alarm_data++;
        printf("ALARM DATA %d\n",alarm_data);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    BaseType_t result;
    
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
}
