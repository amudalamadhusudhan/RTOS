/*   15. Create a task to suspend itself after 1200 ms and resume it from another task      */



#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/queue.h>
#include<freertos/semphr.h>

#define ALARM_PIN 15
TaskHandle_t sensorHandle;
TaskHandle_t processHandle;
void SensorTask(void *pv)
{
    int sensor_data=0;
    while(1)
    {
       sensor_data++;
       printf("Sensor Task: sensor_data %d\n",sensor_data);
       //vTaskDelay(300/portTICK_PERIOD_MS);
       if(sensor_data==12)
       {
           vTaskResume(processHandle);
           printf("sensor task:sensor_data %d\n",sensor_data); 
           sensor_data=0;
           //vTaskDelay(300/portTICK_PERIOD_MS);
      }
         vTaskDelay(300/portTICK_PERIOD_MS);
    }
}

void ProcessingTask(void *pv)
{
    int recv_data=0;
    while(1)
    {
        recv_data++;
        //vTaskSuspend(NULL);
        printf("Processing Task:recv_data %d\n",recv_data);
        // vTaskDelay(300/portTICK_PERIOD_MS);
        if(recv_data==12)
       {
          // vTaskResume(sensorHandle);
           vTaskSuspend(NULL);
           printf("process task:recv_data %d\n",recv_data);
           recv_data=0; 
           //vTaskDelay(300/portTICK_PERIOD_MS);
      }
      vTaskDelay(300/portTICK_PERIOD_MS);
    }
}
       

void app_main()
{

    xTaskCreate(SensorTask,"SensorTask",2048,NULL,5,&sensorHandle);
    xTaskCreate(ProcessingTask,"ProcessindTask",2048,NULL,3,&processHandle);
    printf("Hello world\n");
}
