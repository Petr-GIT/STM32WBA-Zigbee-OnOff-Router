# Zigbee OnOff Router Demo application

## Overview
This application demonstrates how to use the STM32WBA65 Nucleo board in different Zigbee configurations,
showcasing different real-world use case scenarios. The configurations are set by defines in the app_zigbee_endpoint.c file.

## Boards Needed
 * [NUCLEO-WBA65RI](https://www.st.com/en/evaluation-tools/nucleo-wba65ri.html)
    
## Configuration Options
You can select one of the following configurations by setting the respective define to 1:

Light Switch (On/Off Client)
Light Bulb (On/Off Server)


Example:
```
#define APP_ZIGBEE_LIGHTSWITCH_CONFIG                1
#define APP_ZIGBEE_LIGHTBULB_CONFIG                  0
```

For this demo example you need have extra device working as Cooordinator to which you will connect the nucleo board

### <b>Button Functions Used in Light Switch configuration (On/Off Client)</b>
SW1 [Toggle]:  Push to send a toggle request to binded devices.
SW3 [Automatic toggle]: Start/Stop Automatic Toggle Timer sending periodically Toggle request.


### <b>LED Indicators</b>
RED LED: Indicates the state of the On/Off attribute of the On/Off Server cluster (similar to a light bulb).
BLUE LED: Indicates that the device has joined a Zigbee network.

### <b>To setup the application:</b>

Open the project select preferred configuration by editing respective defines in app_zigbee_endpoint.c build it and load your generated application on your STM32WB devices.
  
 
## How to use it?

<b>Getting traces</b>

  To get the traces you need to connect your Board to the Hyperterminal (through the STLink Virtual COM Port).
  The UART must be configured as follows:
```
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits 
    - Stop Bit = 1 bit
    - Parity = none
    - Flow control = none
```

## Keywords

Zigbee, IoT, Internet of Things, Network, Connectivity, FreeRTOS, commissioning, persistence, CSA, Connectivity Standard Alliance, STM32, P-NUCLEO-WB55, Touch Link, NVM, OTA

## Known issues
n/a
