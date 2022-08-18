#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"
TaskHandle_t serial_task_handle;
TaskHandle_t ether_task_handle;
void serial_task(void *data)
{
    UBaseType_t prio;
    while (1)
    {

        prio = uxTaskPriorityGet(serial_task_handle);
        printf("serial task started %d\n", prio);
    }
    vTaskDelete(serial_task_handle);
}
void ether_task(void *data)
{
    UBaseType_t prioe;
    while (1)
    {

        prioe = uxTaskPriorityGet(ether_task_handle);
        printf("ether task started %d\n", prioe);
    }
    vTaskDelete(ether_task_handle);
}
void app_main()
{
    BaseType_t res;
    UBaseType_t priom;
    printf("MT rtos project \n");
    priom = uxTaskPriorityGet(NULL);
    printf("MT task created sucessfully prio %d\n", priom);
    res = xTaskCreate(serial_task, "SERIALTASK", 2048, NULL, 5, &serial_task_handle);
    res = xTaskCreate(ether_task, "ETHERTASK", 2048, NULL, 6, &ether_task_handle);
}