/* 22. Write a RTOS application to demonstrate the usage of queues within an interrupt service routine   */
 
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/queue.h>

#define BUTTON 2
//usage of queues within an interrupt service routine

QueueHandle_t queue;
TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;
uint32_t button_val;

void sensortask_1(void *pvparameters)
{
    button_val=gpio_get_level(BUTTON);
    //printf("BUTTON PRESSED :%d\n",button_val);
    xQueueSendFromISR(queue,&button_val,NULL);
}
void Alarmtask_1(void *pvparameters)
{
    int rece_data=0; 
    while(1)
    {
        printf("ALARM TASK  RUNNING: STACK SIZE %d\n",uxTaskGetStackHighWaterMark(NULL));
        xQueueReceiveFromISR(queue,&rece_data,NULL);
        printf("RECEIVED DATA %d\n",rece_data);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    queue=xQueueCreate(10,sizeof(int));
    BaseType_t result;
    
    //result=xTaskCreate(sensortask_1,"sensortask_1",2048,NULL,5,&xHandle_1);

    
    gpio_reset_pin(BUTTON);
    gpio_set_direction(BUTTON,GPIO_MODE_INPUT);

    gpio_intr_enable(BUTTON);
    gpio_set_intr_type(BUTTON,GPIO_INTR_ANYEDGE);
    gpio_install_isr_service(ESP_INTR_FLAG_EDGE);
    gpio_isr_handler_add(BUTTON,sensortask_1,0);

    result=xTaskCreate(Alarmtask_1,"Alarmtask_1",2048,NULL,5,&xHandle_2);

    if(result==pdPASS)
    {
        printf("Alarmtask created\n");
    }
}
