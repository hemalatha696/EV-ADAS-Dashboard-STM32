# Drivers

This folder contains the STM32 device support libraries required for the EV Dashboard & ADAS project.

## Folder Structure

```
Drivers/
├── CMSIS/
└── STM32F1xx_HAL_Driver/
```

## Description

The Drivers folder provides the hardware abstraction and processor support required for the STM32F103C8T6 microcontroller.

### CMSIS
- ARM Cortex-M3 core support
- Device startup definitions
- Core peripheral access
- Register definitions

### STM32F1xx HAL Driver
- GPIO Driver
- ADC Driver
- UART Driver
- Timer Driver
- RCC Driver
- DMA Driver
- Flash Driver
- Utility functions

## Purpose

- Hardware Abstraction Layer (HAL)
- Peripheral initialization
- Device configuration
- Standard STM32 driver support

## Target Device

- STM32F103C8T6 (Blue Pill)

## Development Environment

- STM32CubeIDE
- STM32 HAL Library
- Embedded C
