/*  23. Write a RTOS application to manage resources using mutual exclusion   */
 
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/semphr.h>


SemaphoreHandle_t rev;
TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;
int sensor_data=0;

void sensortask_1(void *pvparameters)
{
    
    while(1)
    {
        xSemaphoreTake(rev,portMAX_DELAY);
        sensor_data++;
        printf("SENSOR TASK  RUNNING: %d\n",sensor_data);
        xSemaphoreGive(rev);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        
    }
}
void Alarmtask_1(void *pvparameters)
{ 
    while(1)
    {
        xSemaphoreTake(rev,portMAX_DELAY);
        sensor_data++;
        
        printf("RECEIVED DATA %d\n",sensor_data);
        xSemaphoreGive(rev);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    rev=xSemaphoreCreateMutex();
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
