/*  18. Write a RTOS application to demonstrate the use of task to task communication using
Queue management APIs. Also demonstrate blocking on a queue.   */


#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/queue.h>

QueueHandle_t queue;
TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;


void sensortask_1(void *pvparameters)
{
    int sensor_data=0;
    while(1)
    {
        sensor_data++;
        printf("SENSOR TASK  RUNNING: STACK SIZE %d\n",uxTaskGetStackHighWaterMark(NULL));
        xQueueSend(queue,&sensor_data,portMAX_DELAY);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void Alarmtask_1(void *pvparameters)
{
    int rece_data=0; 
    while(1)
    {
        printf("ALARM TASK  RUNNING: STACK SIZE %d\n",uxTaskGetStackHighWaterMark(NULL));
        xQueueReceive(queue,&rece_data,portMAX_DELAY);
        printf("RECEIVED DATA %d\n",rece_data);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    queue=xQueueCreate(10,sizeof(int));
    BaseType_t result;
    
    result=xTaskCreate(sensortask_1,"sensortask_1",2048,NULL,5,&xHandle_1);

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
