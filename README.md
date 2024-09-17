# RTOS-Projects


Welcome to the RTOS Project repository! This repository aims to cover various RTOS concepts using the ATmega328P microcontroller and FreeRTOS. Here, you'll find simple and easily understandable projects and examples that demonstrate different aspects of real-time operating systems.

## Overview

This repository is dedicated to exploring real-time operating system (RTOS) concepts with a focus on FreeRTOS and the ATmega328P microcontroller. The projects and examples provided aim to help beginners and enthusiasts understand and implement RTOS principles effectively.

## Prerequisites

To run the projects in this repository, you will need:

- **AVR-GCC**: Compiler for building C code for AVR microcontrollers.
- **AVRDUDE**: Tool for uploading compiled firmware to the ATmega328P.
- **FreeRTOS Library**: Included in this repository or referenced as needed.
- **Programmer**: Such as USBasp or Arduino as ISP.
- **ATMega328P Microcontroller**: Tested platform for FreeRTOS operations.

## Getting Started

1. Clone the repository:
    ```
    gh repo clone YaswanthRajRY/RTOS-Projects
    ```

2. Navigate to the project folder of your choice:
    ```
    cd RTOS-Projects/ProjectName
    ```

3. Compile the code using AVR-GCC:
    ```
    make all
    ```

4. Upload the compiled code to your microcontroller using AVRDUDE:
    ```
    make flash
    ```

5. Use a terminal as a serial monitor (if applicable) to observe task execution and output.
