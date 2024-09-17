# Flow of the program

In total, there are total 3 user-defined tasks.
- Task1 - ``sw_pres``
- Task2 - ``led_control``
- Task3 - ``lcd_update``

___

###  Task - ``sw_pres``
- Create the task using, ``xTaskCreate(sw_press, "Switch Press", 128, NULL, 4, &sw_press_handle);``
    where,
        - ``sw_press`` is the task_handler which runs when the scheduler is started.
        - "Switch Press" is the name of the task.
        - ``128`` bytes is the size of the stack allocted to the ``sw_press`` task
        - Priority is set to the highest i.e, 4.
        - ``sw_press_handle`` is used to perform any action on the task ``sw_press`` by other tasks.
- The ``sw_press`` monitors the status of two push-button switches (SW1 and SW2).
- This task periodically checks the state of two switches (SW1 and SW2), debounces the input, and sends notifications to the LED Control task (`led_control_handle`) based on the state of the switches. The task runs in an infinite loop and checks the state of the switches every 100 ms. 
- If both switches (SW1 and SW2) are pressed simultaneously, a notification is sent to indicate that both switches are pressed.
- If only SW1 is pressed, a notification is sent to indicate that SW1 is pressed.
- If only SW2 is pressed, a notification is sent to indicate that SW2 is pressed.
- If no switches are pressed, it does not do anything since this is taken care in ``led_control`` task
- This task uses FreeRTOS's `xTaskNotify()` to send notifications to the `led_control_handle` task.
- Notifications are sent with different values to indicate which switch(es) are pressed such as,

- The task includes basic debouncing logic by comparing the current and previous switch states.
- `HAL_GPIO_ReadPin()` is used to read the pin states of the switches.
- The task notifies `led_control_handle` using `xTaskNotify()`, which is designed for inter-task communication in FreeRTOS.

    ```C
    #define SW1_PRESSED					0UL
    #define SW2_PRESSED					1UL
    #define BOTH_SW_PRESSED				2UL
    ```

___

### Task - ``led_control``

- Task to control the behavior of two LEDs (RED and Green(Present on development board)) based on switch press notifications.
- The `led_control()` task waits for notifications from the `sw_press` task, which indicates whether SW1, SW2, or both switches have been pressed.
- Based on the notification received, it controls the state of the LEDs and forwards the notification to the `lcd_update` task to update the display accordingly.
- If SW1 is pressed, the RED LED is turned on, and the notification is sent to the LCD update task.
- If SW2 is pressed, the LD2 (green) LED is turned on, and the notification is sent to the LCD update task.
- If both SW1 and SW2 are pressed simultaneously, the state of the LEDs remains same with no change, and a special notification is sent to the LCD update task to reflect that both switches are pressed.
- If no switches are pressed within the specified timeout period, the task toggles the RED and LD2 LEDs and sends notifications to the LCD update task with alternate statuses.
- The task uses `xTaskNotifyWait()` to block and wait for a notification with a timeout. If a timeout occurs, it toggles the LEDs and alternates between sending two custom notifications: `NO_SW_PRESSED_RED_HIGH` and `NO_SW_PRESSED_GREEN_HIGH`.
- Notifications are received from the `sw_press` task, which detects switch presses.
- Notifications are forwarded to the `lcd_update_handle` task to update the display.
- The task controls the GPIO pins to toggle the state of the LEDs based on the notifications.
- If no notification is received within `CONTROL_NO_SW_PRESS_TIME`, the LEDs are toggled alternately to show that no switch is pressed, and notifications are sent to update the LCD.

___

### Task - ``lcd_update``

- Task to update the LCD display based on the notifications received from the `led_control` task.
- The `lcd_update()` task waits indefinitely for notifications from the `led_control` task. Based on the notification value received, it updates the LCD display to show the current activity and LED status.
- If no switch is pressed, it alternates between displaying "Red HIGH" and "Green HIGH" depending on the internal state of the LEDs in the `led_control` task.
- If SW1 is pressed, it displays that SW1 is active and the RED LED is high.
- If SW2 is pressed, it displays that SW2 is active and the GREEN LED is high.
- If both SW1 and SW2 are pressed simultaneously, it displays a message indicating both switches are pressed but the LED states remain unchanged.
- The task uses `xTaskNotifyWait()` to block until a notification is received. Upon receiving a notification, the LCD display is cleared, and the appropriate message is written to the first and second rows of the LCD based on the notification type.
- Notifications are sent from the `led_control` task based on the current state of the switches and LEDs.
- The LCD is updated by sending appropriate commands and strings to display the activity and status.
- The task uses the HAL functions to interact with the LCD (e.g., `LCD_send_command()` and `LCD_send_string()`).
- A small delay (`HAL_Delay(2)`) is added after clearing the screen to ensure the display is updated properly.

___

### Segger snapshot

![trace analyse](/Docs/SEGGER_Records/Snapshots/Screenshot%202024-09-17%20at%2010.45.09.png)