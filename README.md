# tracker-stm8s-sim800c
A Tracker Based on STM8S and SIM800C.

## Feature
* No GPS Module, approximate location.
* Using HTTP to upload data.
* Low cost.

## Hardware
+-STM8S-+       +-SIM800C-+
|       |       |         |
|    D5 +-------+ RXD     |
|       |       |         |
|    D6 +-------+ TXD     |
|       |       |         |
|   GND +-------+ GND     |
|       |       |         |
|    C7 +-|4K7|-+ PWX     |
|       |       |         |
+-------+       +---------+

## How to use
### ST Visual Develop
* Create a project by ST Visual Develop.
* Copy \*.c and \*.h to the project folder.
* Add \*.c and \*.h into the project in ST Visual Develop.

### SDCC
* Write a Makefile.
