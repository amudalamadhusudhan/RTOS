/*     4. Create two task with priority 10 and 20. Each task prints its own custom message.   */


#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>



void task_1(void *pv)
{
   while(1)
   {
       printf("In Task1.....\n");
       vTaskDelay(1000/portTICK_PERIOD_MS);
   }
}

void task_2(void *pv)
{
    while(1)
    {
       printf("In Task2.....\n");
       vTaskDelay(1000/portTICK_PERIOD_MS);
    }
     
}



void app_main()
{
    xTaskCreate(task_1,"task_1",1048,NULL,10,NULL);
    xTaskCreate(task_2,"task_2",1048,NULL,20,NULL);
    printf("Hello C-DAC\n");
}
