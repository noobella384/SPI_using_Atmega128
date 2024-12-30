# SPI Communication Using ATmega128

## Project Overview

This project demonstrates **SPI (Serial Peripheral Interface)** communication using the **ATmega128 microcontroller**. SPI is a high-speed, full-duplex, synchronous communication protocol widely used in embedded systems. The project implements key functionalities, including UART communication, LED control, and an LCD interface, while addressing challenges in hardware and software integration.

The repository contains source code, documentation, and implementation details for a comprehensive understanding of the SPI protocol and its applications.

---

## Key Features

- **SPI Communication**: Master-slave communication implemented using the ATmega128 microcontroller.
- **UART Integration**: Serial communication for debugging and testing.
- **LCD Interface**: Display outputs and debugging information.
- **LED Control**: Basic GPIO operations to demonstrate peripheral control.
- **Hardware & Software Cohesion**: Seamless integration of ATmega128 peripherals and external hardware.

---

## Repository Structure

| **File**                    | **Description**                                                                 |
|-----------------------------|---------------------------------------------------------------------------------|
| `Master.c`                  | Source code for the master implementation in SPI communication.                |
| `Slave.c`                   | Source code for the slave implementation in SPI communication.                 |
| `UART.c`                    | UART communication implementation for serial debugging and testing.           |
| `LED-toggle.c`              | Demonstrates LED blinking functionality using GPIO.                            |
| `LCD.c`                     | Code to interface with an LCD for displaying outputs and debugging information.|
| `traffic1.atsln`            | Atmel Studio 7.0 project file integrating LCD functionality for traffic-like scenarios. |
| `SPI1.atsln`                | Atmel Studio 7.0 project file for SPI master communication setup.              |
| `SPI2.atsln`                | Atmel Studio 7.0 project file for SPI slave communication setup.               |
| `UART.atsln`                | Atmel Studio 7.0 project file for UART implementation.                         |
| `LEDBlinkToggle.atsln`      | Atmel Studio 7.0 project file for LED blink functionality.                     |
| `SSP Miniproject.pdf`       | Final documentation of the SPI miniproject, including implementation details.  |
| `SSP Miniproject Updates.pdf`| Progress and updates documentation of the project timeline.                    |

---

## Project Workflow

1. **Initial Setup**:
   - Installed **Microchip Studio** and configured the development environment.
   - Established UART for debugging.
   - Implemented basic LED blinking to test GPIO.

2. **Development Phases**:
   - Week 1: UART implementation and initial understanding of SPI.
   - Week 2: SPI protocol implementation and debugging.
   - Week 3: Integrated LCD functionality and prepared final deliverables.

3. **Challenges**:
   - Resolving incorrect SPI pin outputs.
   - Addressing hardware issues with the LCD.
   - Synchronizing SPI master and slave communication.

---

## Software & Hardware Used

### Software
- **Microchip Studio**: IDE for developing and debugging ATmega128 firmware.
- **RealTerm**: Serial communication software for UART testing.
- **AVRDUDE**: USBasp driver for flashing firmware.

### Hardware
- **ATmega128 Development Board**: Central microcontroller for the project.
- **DB9 Cable**: For serial communication.
- **USBasp ISP Programmer**: Flashing the firmware onto the ATmega128.
- **LCD Module**: For output display.
- **LEDs and Resistors**: Basic GPIO testing.
