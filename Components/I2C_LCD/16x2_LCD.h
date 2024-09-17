#ifndef __16x2_LCD__H
#define __16x2_LCD__H

#include <stdint.h>
#include "stm32f4xx_hal.h"

#define CORTEX_M4			1UL

// Slave address
#define LCD_ADDR			0x4E

// This includes the 3 bit (backlight) which is always 1
#define COMMAND_BYTE		0x0C
#define STROBE				0x08
#define DATA_BYTE			0x0D

#define ROW_1				0x80
#define ROW_2				0xC0

#define CLEAR_SCREEN		0X01

extern I2C_HandleTypeDef hi2c1;

void LCD_init(void);
void LCD_send_command(uint8_t command_to_send);
void LCD_send_data(uint8_t data_to_sent);
void LCD_send_string(char *string_to_send);


#endif
