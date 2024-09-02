/*
*   Project name: Counting semaphore example
*   Author: Yaswanth Raj R Y
*/

#include <avr/io.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "util/delay.h"
#include "semphr.h"
#include "task.h"

SemaphoreHandle_t countingSemaphore;

void xTask1(void*);
void xTask2(void*);
void xTask3(void*);
void xTask4(void*);
void xTask5(void*);
void blink(uint8_t);

int main (void)
{
    DDRB = 0x1F;
    PORTB = 0x1F;

    countingSemaphore = xSemaphoreCreateCounting(3, 3);

    xTaskCreate(xTask1, "Task 1", 128, NULL, 5, NULL);
    xTaskCreate(xTask2, "Task 2", 128, NULL, 4, NULL);
    xTaskCreate(xTask3, "Task 3", 128, NULL, 3, NULL);
    xTaskCreate(xTask4, "Task 4", 128, NULL, 2, NULL);
    xTaskCreate(xTask5, "Task 5", 128, NULL, 1, NULL);
    
    vTaskStartScheduler();
}

void xTask1(void* parameter)
{
    while (1)
    {
        if (xSemaphoreTake(countingSemaphore, portMAX_DELAY) == pdTRUE)
        {
            blink(PORTB4);
            xSemaphoreGive(countingSemaphore);
        }
        vTaskDelay(100 / portTICK_RATE_MS);
    }
}

void xTask2(void* parameter)
{
    while (1)
    {
        if (xSemaphoreTake(countingSemaphore, portMAX_DELAY) == pdTRUE)
        {
            blink(PORTB3);
            xSemaphoreGive(countingSemaphore);
        }
        vTaskDelay(100 / portTICK_RATE_MS);
    }
}

void xTask3(void* parameter)
{
    while (1)
    {
        if (xSemaphoreTake(countingSemaphore, portMAX_DELAY) == pdTRUE)
        {
            blink(PORTB2);
            xSemaphoreGive(countingSemaphore);
        }
        vTaskDelay(100 / portTICK_RATE_MS);
    }
}

void xTask4(void* parameter)
{
    while (1)
    {
        if (xSemaphoreTake(countingSemaphore, portMAX_DELAY) == pdTRUE)
        {
            blink(PORTB1);
            xSemaphoreGive(countingSemaphore);
        }
        vTaskDelay(100 / portTICK_RATE_MS);
    }
}

void xTask5(void* parameter)
{
    while (1)
    {
        if (xSemaphoreTake(countingSemaphore, portMAX_DELAY) == pdTRUE)
        {
            blink(PORTB0);
            xSemaphoreGive(countingSemaphore);
        }
        vTaskDelay(100 / portTICK_RATE_MS);
    }
}

void blink(uint8_t xPin)
{
    for(int i=0; i<5; i++)
    {
        PORTB ^= (1 << xPin);
        vTaskDelay(500 / portTICK_RATE_MS);
        PORTB ^= (1 << xPin);
        vTaskDelay(500 / portTICK_RATE_MS);
    }
}
