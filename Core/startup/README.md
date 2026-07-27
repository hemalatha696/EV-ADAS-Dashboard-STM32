# Startup

This folder contains the startup files required to boot the STM32F103C8T6 microcontroller.

## Contents

- startup_stm32f103c8tx.s – Startup assembly file
- system_stm32f1xx.c – System initialization
- Interrupt vector table
- Reset handler

## Responsibilities

- Initializes the microcontroller after reset
- Sets up the interrupt vector table
- Initializes the system clock
- Calls the `main()` function
- Prepares memory before program execution

## Target Device

- STM32F103C8T6 (Blue Pill)

## Toolchain

- STM32CubeIDE
- STM32 HAL Library
- ARM GCC Compiler
