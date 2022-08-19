#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"
#include"freertos/timers.h"
TaskHandle_t serial_task_handle;
TaskHandle_t ether_task_handle;
TimerHandle_t serial_timer_handle;

void serial_timer_callback(TimerHandle_t xTimer)
{

printf("timer fired\n");

}
void serial_task(void *data)
{
 printf("sarting the serial task\n");
 printf("creating the serial timer\n");
    serial_timer_handle=xTimerCreate("oneshottimer",5000 / portTICK_PERIOD_MS,pdTRUE,NULL,serial_timer_callback);
// pdFASLE FOR ONE SHOT TIMER
    printf("sarting the timer\n");
    xTimerStart(serial_timer_handle,0);
   
    vTaskDelete(serial_task_handle);
    printf("serial task dead\n");
    //vTaskDelay(1000/portTICK_PERIOD_MS);
}

void app_main()
{
    BaseType_t res;
    UBaseType_t priom;
    printf("MT rtos project \n");
    priom = uxTaskPriorityGet(NULL);
    printf("MT task created sucessfully prio %d\n", priom);
    res = xTaskCreate(serial_task, "SERIALTASK", 2048, NULL, 5, &serial_task_handle);
}