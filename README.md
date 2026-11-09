# Embedded C Projects

A collection of embedded systems projects developed using Embedded C and the LPC2129 ARM7 microcontroller. These projects focus on sensor interfacing, peripheral configuration, hardware control, communication protocols, and real-time monitoring.

## Projects

### 1. Multi-Sensor Environmental Monitoring System

An environmental monitoring project that uses multiple sensors to measure environmental conditions.

**Key features:**
- Temperature measurement using LM35.
- Light intensity measurement using LDR.
- Soil moisture monitoring.
- Water detection using a digital sensor.
- ADC-based analog data acquisition.
- LCD and UART-based monitoring.
- LED-based status indication.

### 2. Smart Industrial Safety Monitoring System

An industrial safety monitoring project designed to monitor temperature, worker movement, and flame conditions.

**Key features:**
- Temperature monitoring using LM35.
- Worker movement detection using PIR sensor.
- Flame detection.
- Real-time safety status evaluation.
- 16×2 LCD status display.
- UART communication with PC/Laptop.
- Green, yellow, and red LED indicators.

### 3. Real-Time Sensor Monitoring Station

A real-time sensor monitoring project that collects multiple sensor readings and transmits the information to a Linux terminal through UART.

**Key features:**
- Temperature monitoring.
- Light intensity measurement using LDR.
- Voltage measurement using a potentiometer.
- Vibration detection.
- Flame detection.
- UART-based terminal output.
- LED and buzzer alerts.
- Timer0 interrupt-based periodic monitoring.

## Technologies and Concepts

- Embedded C programming
- LPC2129 ARM7 microcontroller
- ADC interfacing
- GPIO programming
- UART serial communication
- I2C communication
- Timer configuration and interrupts
- Sensor interfacing
- LCD interfacing
- Modular programming
- Makefiles and embedded firmware development

## Repository Structure

```text
embedded-c/
│
├── README.md
│
├── EnvironmentMonitor/
│   └── source files...
│
├── Smart Industry Monitoring system/
│   └── source files...
│
└── Real-Time Sensor Monitoring Station/
    └── source files...
```

## Learning Objectives

- Understand ARM7 microcontroller architecture.
- Configure and access peripheral registers.
- Interface analog and digital sensors.
- Implement ADC-based data acquisition.
- Understand UART and I2C communication.
- Work with hardware timers and interrupts.
- Develop modular embedded firmware.
- Understand real-time hardware monitoring and control.

## About

This repository documents my practical work and learning in embedded systems development using the LPC2129 microcontroller.

The projects demonstrate the interaction between embedded software, hardware peripherals, sensors, and communication interfaces.

More experiments and improvements will be added as I continue developing my embedded systems skills.
