# Embedded Systems project
## A simple Calculator using AVR atmega32 mircocontroller and other peripherals

### Objectives 
* A simple calculator that can perform 3 operaions [ Addition , Subtraction , Multipication ] using a password of 4 digits


### Hardware 
* AVR atmega32 microcontroller
* Keypad
* LCD

### Software Layered Architecture
#### App --> Application
* main
#### HAL --> Hardware abstraction layer
* Keypad
* LCD
#### MCAL --> Mircocontroller abstraction layer
* DIO --> Digital input output

### Driver files
* prog.c       --> program
* config.h     --> contains configuration that modified by user
* interface.h  --> contains macros and fuction prototype
* private.h    --> constains registers description and private functions
  




