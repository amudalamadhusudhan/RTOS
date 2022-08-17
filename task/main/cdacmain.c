#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
TaskHandle_t serial_task_handle;
void serial_task(void *data)
{
    printf("serial task started\n");
    xTaskDelete(serial_task_handle);
}
void app_main()
{
    BaseType_t res;

    printf("MT rtos project\n");
    res = xTaskCreate(serial_task, "SERIALTASK", 1024, NULL, 5, &serial_task_handle);
    if (res == pdPASS)
    {
        printf("MT task created sucussfully\n");
    }
}