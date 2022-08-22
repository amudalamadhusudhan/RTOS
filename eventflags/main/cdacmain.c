#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"
#include "freertos/event_groups.h"
#define MQ_SIZE 4
#define MSG_SIZE 64
EventGroupHandle_t sensor_ef;
TaskHandle_t pressure_task1handle,temperature_task2handle,processing_task3handle,highprio_task4handle;
//QueueHandle_t sensor_q;

void pressure_task1(void *data)
{
   int pdata=200;
   printf("pressure_task1 sarting the pressure_task1\n");
   while(1)
    {
    pdata++;

    //xQueueSend(sensor_q,&pdata,pdMS_TO_TICKS(5000));
   // vTaskDelay(pdMS_TO_TICKS(100));
    xEventGroupSetBits(sensor_ef,(1<<0));
    printf("pressure task setting bit -> event generated\n");
     vTaskDelay(pdMS_TO_TICKS(5000));
    }
      vTaskDelete(NULL);
}

void temperature_task2(void *data)
{
    int tdata=100; 
    printf("temparature_task1 sarting the temparature_task1\n");
    while(1)
    { 
     tdata++;
     //send the data to the queue
     //xQueueSend(sensor_q,&tdata,pdMS_TO_TICKS(5000));
    
         xEventGroupSetBits(sensor_ef,(1<<1));
         printf("temperature task setting bit -> event generated\n");
          vTaskDelay(pdMS_TO_TICKS(1000));

     }
      vTaskDelete(NULL);
}
void processing_task3(void *data)
{
   //int buffer;
    printf("processing_task3 sarting the processing_task3\n");
    while(1)
    { 
      //recive  the data to the 
     // xQueueReceive(sensor_q,&buffer,portMAX_DELAY);
     xEventGroupWaitBits(sensor_ef,(1<<0)|(1<<1),pdTRUE,pdFALSE,portMAX_DELAY);
      printf("processing received event \n");
     
     }
      vTaskDelete(NULL);
}

// void highprio_task4(void *data)
// {
//    int buffer;
//     printf("highprio_task sarting the highprio_task3\n");
//     int count =0;
//     while(1)
//     { 
//       //recive  the data to the 
//       xQueueReceive(sensor_q,&buffer,pdMS_TO_TICKS(1000));
//       printf("highprio received data %d\n",buffer);
//       //vTaskDelay(pdMS_TO_TICKS(1000));
//       count++;
//       if(count>50)
//     {
//       vTaskDelay(pdMS_TO_TICKS(10000));
//     }
//      }
//       vTaskDelete(NULL);
// }

void app_main()
{
  BaseType_t res;
  UBaseType_t priom;
  printf("MT rtos project \n");
  priom = uxTaskPriorityGet(NULL);
  printf("MT task created sucessfully prio %d\n", priom);
 // sensor_q=xQueueCreate( MQ_SIZE,MSG_SIZE);
 sensor_ef=xEventGroupCreate();
  res = xTaskCreate(pressure_task1, "pressure_TASK1", 2048, NULL, 8, &pressure_task1handle);
  res = xTaskCreate(temperature_task2, "temperature_TASK2", 2048, NULL, 8, &temperature_task2handle);
  res = xTaskCreate(processing_task3, "processing_TASK3", 2048, NULL, 8, &processing_task3handle);
 // res = xTaskCreate(highprio_task4, "highprio_TASK4", 2048, NULL, 10, &highprio_task4handle);
}