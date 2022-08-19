/* 24. Write a RTOS application to demonstrate a priority inversion problem. If your RTOS sup-
ports priority inheritance or priority ceiling, use it to solve the priority inversion problem.   */

 

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

static SemaphoreHandle_t sem;     //priority inversion problem solved.
TaskHandle_t low;
TaskHandle_t high;
TaskHandle_t medium;
//shared resource
uint32_t global=0;
 TickType_t timestamp;
void Lowpriority(void *pv)
{
    while(1)
    {
        xSemaphoreTake(sem, portMAX_DELAY);
        global++;
        printf("LOW PRIORITY TAKE MUTEX\n");
        xSemaphoreGive(sem);
        printf("LOW PRIORITY GIVE MUTEX\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
void Highpriority(void *pv)
{
    while(1)
    {
        xSemaphoreTake(sem, portMAX_DELAY);
        printf("HIGH PRIORITY TAKE MUTEX\n");
        global++;
        xSemaphoreGive(sem);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    } 
}
void Mediumpriority(void *pv)
{
    while(1)
    {
        printf("MEDIUM PRIORITY TASK \n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    sem= xSemaphoreCreateMutex();
    //LOW PRIORITY TASK
    xTaskCreate(Lowpriority,"Low_priority",2048,NULL,1,&low);

    // Introduce a delay to force priority inversion
    vTaskDelay(1 / portTICK_PERIOD_MS);

    //HIGH PRIORITY TASK
    xTaskCreate(Highpriority,"High_priority",2048,NULL,5,&high);
    //MEDIUM PRIORITY TASK
    xTaskCreate(Mediumpriority,"Medium_priority",2048,NULL,3,&medium);


}

