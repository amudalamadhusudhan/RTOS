/* 21. Write a RTOS application to demonstrate counting semaphores to synchronize a task        */

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/semphr.h>


SemaphoreHandle_t xSemaphore;
TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;

int global_var=0;

void sensortask_1(void *pvparameters)
{
    
    while(1)
    {
        xSemaphoreTake(xSemaphore,portMAX_DELAY);
        global_var++;
        printf("SENSOR TASK  RUNNING: %d\n",global_var);
        xSemaphoreGive(xSemaphore);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
    
}
void Alarmtask_1(void *pvparameters)
{
    
    while(1)
    {
        xSemaphoreTake(xSemaphore,portMAX_DELAY);
        global_var++;
        printf("ALARM TASK  RUNNING: %d\n",global_var);
        xSemaphoreGive(xSemaphore);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
        

}
    
void app_main()
{
    xSemaphore = xSemaphoreCreateCounting( 5, 1 );
     if( xSemaphore != NULL )
    {
        printf("counting semaphore created successfully!\n");
    }
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
