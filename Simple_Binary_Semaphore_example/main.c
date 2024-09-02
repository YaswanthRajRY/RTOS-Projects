/*
*   Project name: Binary semaphore example
*   Author: Yaswanth Raj R Y
*/

#include <avr/io.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "util/delay.h"
#include "semphr.h"
#include "task.h"

SemaphoreHandle_t BinarySemaphore;

void xTask1(void*);
void xTask2(void*);
void blink(int);

int main (void)
{
    DDRB |= (1 << DDB4);
    PORTB |= (1 << PORTB4);

    BinarySemaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(BinarySemaphore);

    xTaskCreate(xTask1, "Task 1", 128, NULL, 1, NULL);
    xTaskCreate(xTask2, "Task 2", 128, NULL, 3, NULL);
    
    vTaskStartScheduler();
}

void xTask1(void* parameter)
{
    int time = 1000;
    while (1)
    {
        xSemaphoreTake(BinarySemaphore, portMAX_DELAY);
        blink(time);
        xSemaphoreGive(BinarySemaphore);
        vTaskDelay(15 / portTICK_RATE_MS );
    }
}

void xTask2(void* parameter)
{
    int time = 500;
    while (1)
    {
        xSemaphoreTake(BinarySemaphore, portMAX_DELAY);
        blink(time);
        xSemaphoreGive(BinarySemaphore);
        vTaskDelay(10 / portTICK_RATE_MS );
    }
}

void blink(int parameter)
{
    int xDelay = parameter / portTICK_RATE_MS;

    for (int i=0; i<5; i++)
    {
        PORTB |= (1 << PORTB4);
        vTaskDelay(xDelay);
        PORTB ^= (1 << PORTB4);
        vTaskDelay(xDelay);
    }
}
