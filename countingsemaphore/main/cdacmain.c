#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"
#include "freertos/timers.h"
#include "freertos/semphr.h"
TaskHandle_t task1handle,task2handle, task3handle, task4handle;

SemaphoreHandle_t serial_counting_sem;
void task1(void *data)
{
  printf("task1 sarting the task1\n");
  printf("task1 requesting for the serial port\n");
  xSemaphoreTake(serial_counting_sem,pdMS_TO_TICKS(20000));
  printf("task1 got the serialport\n");
  vTaskDelay(10000 / portTICK_PERIOD_MS);
  xSemaphoreGive(serial_counting_sem);
  printf("task1 released the serialport\n");
    vTaskDelete(NULL);
}
void task2(void *data)
{
  printf("task2 sarting the task2\n");
  printf("task2 requesting for the serial port\n");
  xSemaphoreTake(serial_counting_sem,pdMS_TO_TICKS(20000));
  printf("task2 got the serialport\n");
  vTaskDelay(2000 / portTICK_PERIOD_MS);
  xSemaphoreGive(serial_counting_sem);
  printf("task2 released the serialport\n");
  vTaskDelete(NULL);
}
void task3(void *data)
{
  printf("task3 sarting the task3\n");
  printf("task3 requesting for the serial port\n");
  xSemaphoreTake(serial_counting_sem,pdMS_TO_TICKS(20000));
  printf("task3 got the serialport\n");
  vTaskDelay(3000 / portTICK_PERIOD_MS);
  xSemaphoreGive(serial_counting_sem);
  printf("task3 released the serialport\n");
  vTaskDelete(NULL);
}
void task4(void *data)
{
  printf("task4 sarting the task4\n");
  printf("task4 requesting for the serial port\n");
  xSemaphoreTake(serial_counting_sem,pdMS_TO_TICKS(20000));
  printf("task4 got the serialport\n");
  vTaskDelay(8000 / portTICK_PERIOD_MS);
  xSemaphoreGive(serial_counting_sem);
  printf("task4 released the serialport\n");
  vTaskDelete(NULL);
}

void app_main()
{
  BaseType_t res;
  UBaseType_t priom;
  printf("MT rtos project \n");
  priom = uxTaskPriorityGet(NULL);
  printf("MT task created sucessfully prio %d\n", priom);
  serial_counting_sem = xSemaphoreCreateCounting(3, 3);
  res = xTaskCreate(task1, "TASK1", 2048, NULL, 8, &task1handle);
  res = xTaskCreate(task2, "TASK2", 2048, NULL, 8, &task2handle);
  res = xTaskCreate(task3, "TASK3", 2048, NULL, 8, &task3handle);
  res = xTaskCreate(task4, "TASK4", 2048, NULL, 8, &task4handle);
}