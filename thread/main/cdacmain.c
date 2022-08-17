#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"
TaskHandle_t serial_task_handle;
void *serial_task(void *data)
{
    while (1)
    {
        printf("serial task started\n");
    }
}
void app_main()
{
    BaseType_t res;

    printf("MT rtos project\n");
    pthread_t sid;
    pthread_create(&sid, NULL, serial_task, NULL);
    pthread_join(sid, NULL);
    // res=xTaskCreate(serial_task, "SERIALTASK",1024,NULL,5,&serial_task_handle);
    // if(res==pdPASS)
    // {
    // printf("MT task created sucussfully\n");

    // }
}