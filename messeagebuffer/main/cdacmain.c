#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"
#include "freertos/timers.h"
#include "freertos/message_buffer.h"

TaskHandle_t task1handle,task2handle, task3handle, task4handle;
MessageBufferHandle_t mb_t1_t2;

void task1(void *data)
{
  printf("task1 sarting the task1\n");
  printf("task1 sending message\n");
  //while(1)
  //{
  xMessageBufferSend(mb_t1_t2,"madhusudhan\n",13,pdMS_TO_TICKS(20000));
  xMessageBufferSend(mb_t1_t2,"madhusudhan2\n",13,pdMS_TO_TICKS(20000));
  xMessageBufferSend(mb_t1_t2,"madhusudhan3\n",13,pdMS_TO_TICKS(20000));
  printf("task1 finished sending the message\n");
  //}
  vTaskDelete(NULL);
}
void task2(void *data)
{
  unsigned char rbuff[200];
  size_t nbytes=0;
  printf("task2 sarting the task2\n");
  while(1)
  {
  printf("task2 requesting for data to be received\n");
  nbytes=xMessageBufferReceive(mb_t1_t2,rbuff,200,pdMS_TO_TICKS(20000));
  printf("task2 recived the data %s\n",rbuff);
   printf("task2 recived the data %d\n",nbytes);
  }
  vTaskDelete(NULL);
}


void app_main()
{
  BaseType_t res;
  UBaseType_t priom;
  printf("MT rtos project \n");
  priom = uxTaskPriorityGet(NULL);
  printf("MT task created sucessfully prio %d\n", priom);
  mb_t1_t2= xMessageBufferCreate(200);
  res = xTaskCreate(task1, "TASK1", 2048, NULL, 8, &task1handle);
  res = xTaskCreate(task2, "TASK2", 2048, NULL, 8, &task2handle);
}