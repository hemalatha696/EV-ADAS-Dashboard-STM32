# STM32F1xx HAL Driver

This folder contains the **STM32 Hardware Abstraction Layer (HAL)** drivers for the STM32F103C8T6 microcontroller.

## Purpose

The HAL Driver provides a high-level interface for configuring and controlling the STM32 peripherals without directly accessing hardware registers.

## Main Drivers

- GPIO
- ADC
- UART (USART)
- TIM (Timers)
- RCC (Reset and Clock Control)
- DMA
- EXTI (External Interrupts)
- FLASH
- PWR
- CORTEX

## Features

- Peripheral initialization
- Hardware abstraction
- Standard STM32 API
- Simplified peripheral configuration
- Portable and reusable embedded firmware

## Target Device

- STM32F103C8T6 (Blue Pill)

## Development Environment

- STM32CubeIDE
- STM32 HAL Library
- Embedded C

## Project Usage

These HAL drivers are used by the EV Dashboard & ADAS project for:

- Reading ADC sensor values
- UART communication
- GPIO control
- Timer configuration
- System clock initialization
- Interrupt handling
