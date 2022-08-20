#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"
#include"freertos/timers.h"
#include"freertos/semphr.h"
TaskHandle_t adc_task_handle;
TaskHandle_t processing_task_handle;
SemaphoreHandle_t adcsignal;
void adc_task(void *data)
{
 printf("AT sarting the adc task\n");
 vTaskDelay(1000/portTICK_PERIOD_MS);
 xSemaphoreGive(adcsignal);
 printf("AT posted signal to processing task\n");
 //vTaskDelay(1000/portTICK_PERIOD_MS);
 //pdMS_TO_TICKs(5000);
  vTaskDelete(NULL);
}
void processing_task(void *data)
{
 printf("PT sarting the processing task\n");
 xSemaphoreTake(adcsignal,0);
 printf("PT got the signal\n");
 vTaskDelete(NULL);
}
void app_main()
{
    BaseType_t res;
    UBaseType_t priom;
    printf("MT rtos project \n");
    priom = uxTaskPriorityGet(NULL);
    printf("MT task created sucessfully prio %d\n", priom);
    adcsignal=xSemaphoreCreateBinary();
    res = xTaskCreate(adc_task, "SERIALTASK", 2048, NULL, 5, &adc_task_handle);
      res = xTaskCreate(processing_task, "processingTASK", 2048, NULL, 5, &processing_task_handle);
}