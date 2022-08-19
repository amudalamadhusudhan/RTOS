/*  20. Write a RTOS application to demonstrate deferred interrupt processing using binary semaphores   */


#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define LED_BUTTON 4
#define LED 2
TaskHandle_t ISR;
TaskHandle_t ISR_2;

uint32_t gpio_val=0;
void gpio_button_handler(void *pv)
{
    BaseType_t xYieldRequired;
    gpio_val=(gpio_val== 0 ? 1:0);
    gpio_set_level(LED,gpio_val);
    xYieldRequired = xTaskResumeFromISR(ISR_2);
    portYIELD_FROM_ISR( xYieldRequired );
}

void isrtask(void *pv)
{
    while(1)
    {
        vTaskSuspend(NULL);
        printf("task released by interrupt\n");
        printf("its working\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
   
}
void buttontask(void *pv)
{
    uint32_t button_val;
    for(;;)
    {
        button_val=gpio_get_level(LED_BUTTON);
        printf("BUTTON PRESSED :%d\n",button_val);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
void app_main()
{
    esp_rom_gpio_pad_select_gpio(LED_BUTTON);
    esp_rom_gpio_pad_select_gpio(LED);
    //gpio_reset_pin(LED_BUTTON);
    gpio_set_direction(LED_BUTTON,GPIO_MODE_INPUT);
    //gpio_reset_pin(LED);
    gpio_set_direction(LED,GPIO_MODE_OUTPUT);
    //define interrupt trigger type
    //negedge by default 1->0
    
    gpio_intr_enable(LED_BUTTON);
    gpio_set_intr_type(LED_BUTTON,GPIO_INTR_ANYEDGE);
    gpio_install_isr_service(ESP_INTR_FLAG_EDGE);
    
    gpio_isr_handler_add(LED_BUTTON,gpio_button_handler,0);
    
    xTaskCreate(buttontask,"buttontask",4096,NULL,5,&ISR);
    xTaskCreate(isrtask,"isr_task",2048,NULL,10,&ISR_2);
}
