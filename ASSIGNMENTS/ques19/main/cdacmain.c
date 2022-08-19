/*  19. Write a RTOS application to demonstrate the effects of task priorities when sending to and
receiving from a queue.   */


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
        printf("SENSOR TASK  RUNNING:%d\n",sensor_data);
        xQueueSend(queue,&sensor_data,portMAX_DELAY);
        vTaskDelay(100/ portTICK_PERIOD_MS);
    }
}
void Alarmtask_1(void *pvparameters)
{
    int rece_data=0; 
    while(1)
    {
        //printf("ALARM TASK  RUNNING: %d\n",rece_data);
        xQueueReceive(queue,&rece_data,portMAX_DELAY);
        printf("RECEIVED DATA %d\n",rece_data);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    queue=xQueueCreate(4,sizeof(int));
    BaseType_t result;
    
    result=xTaskCreate(sensortask_1,"sensortask_1",2048,NULL,10,&xHandle_1);

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
