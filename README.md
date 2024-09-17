# Overview:

This system consists of three main FreeRTOS tasks: sw_press, led_control, and lcd_update. Together, these tasks manage the state of two switches and two LEDs, and display relevant information on an LCD.

# Goal:

1. Given 2 LEDs: Green and Red
2. A task that reads input from 2 Switch at 100ms.
3. When SW1 is pressed, red LED turns ON and when SW2 is pressed, green LED turns ON
4. If both Switch, SW1 and SW2 are pressed at the same time, no changes in the state of the LEDs.
5. If no switch is pressed, the led will start blinking one by one until any switch press is detected.
6. The LED status and the switch press will be update on the LCD at all times.


# Results:
 ![SW2 is Pressed](EMotoRad_A/Docs/SW2.jpg)
