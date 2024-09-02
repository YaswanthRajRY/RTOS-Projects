/*
*   Project name: Mutex example
*   Author: Yaswanth Raj R Y
*/

#include <avr/io.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "util/delay.h"
#include "semphr.h"
#include "task.h"

SemaphoreHandle_t Mutex;

void xTask1(void*);
void xTask2(void*);
void blink(int);

const char* receivedData;

int main (void)
{
    DDRB |= (1 << DDB4);
    PORTB |= (1 << PORTB4);

    Mutex = xSemaphoreCreateMutex();

    xTaskCreate(xTask1, "Task 1", 128, NULL, 1, NULL);
    xTaskCreate(xTask2, "Task 2", 128, NULL, 3, NULL);
    
    vTaskStartScheduler();
}

void xTask1(void* parameter)
{
    int time = 100;
    while (1)
    {
        blink(time);
        vTaskDelay(2000/ portTICK_PERIOD_MS);
    }
}

void xTask2(void* parameter)
{
    int time = 1000;
    while (1)
    {
        blink(time);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void blink(int parameter)
{
    int xDelay = parameter;

    xSemaphoreTake(Mutex, portMAX_DELAY);
    for (int i=0; i<5; i++)
    {
        PORTB |= (1 << PORTB4);
        vTaskDelay(xDelay / portTICK_PERIOD_MS);
        PORTB ^= (1 << PORTB4);
        vTaskDelay(xDelay / portTICK_PERIOD_MS);
    }
    xSemaphoreGive(Mutex);
}
