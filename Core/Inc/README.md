# Inc

This folder contains the header files (`.h`) for the EV Dashboard & ADAS project.

## Purpose

The header files define:

- Function declarations
- Data structures
- Macros and constants
- Global variables
- Configuration settings

These files provide interfaces for the source files located in the `Src` folder.

## Main Header Files

- main.h – Main application definitions
- gpio.h – GPIO configuration
- adc.h – ADC interface
- tim.h – Timer interface
- usart.h – UART communication
- ev_control.h – EV dashboard functions
- adas.h – ADAS logic
- ultrasonic.h – Ultrasonic sensor interface
- buzzer.h – Buzzer control
- fault.h – Fault handling

## Features

- Modular firmware design
- Hardware abstraction
- Function prototypes
- Peripheral configuration
- Shared project definitions

## Development Environment

- STM32CubeIDE
- STM32 HAL Library
- Embedded C
- STM32F103C8T6 (Blue Pill)
