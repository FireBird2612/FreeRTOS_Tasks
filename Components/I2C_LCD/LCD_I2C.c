/*
 * LCD_I2C.c
 *
 *  Created on: Sep 16, 2024
 *      Author: simpleyetfulling
 */


#include "16x2_LCD.h"

void LCD_init(void){
	  // 4 bit initialisation
	  HAL_Delay(50);  // wait for >40ms
	  LCD_send_command(0x30);
	  HAL_Delay(5);  // wait for >4.1ms
	  LCD_send_command(0x30);
	  HAL_Delay(1);  // wait for >100us
	  LCD_send_command(0x30);
	  HAL_Delay(10);
	  LCD_send_command(0x20);  // 4bit mode
	  HAL_Delay(10);

	  // display initialisation
	  LCD_send_command(0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	  HAL_Delay(1);
	  LCD_send_command(0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	  HAL_Delay(1);
	  LCD_send_command(0x01);  // clear display
	  HAL_Delay(2);
	  LCD_send_command(0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	  HAL_Delay(1);
	  LCD_send_command(0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void LCD_send_command(uint8_t command_to_send){
	uint8_t byte_order[4];

	/*	Extract the upper 4 bits from the command_to_send	*/
	uint8_t upper_byte = (command_to_send & 0xF0);

	/*	Extract the lower 4 bits and left shift to the upper 4, because the 0 to 3 will always be for RS, RW, E and Backlight
	 * 	as per datasheet	*/
	uint8_t lower_byte = ((command_to_send << 4) & 0xF0);

	/*	Send upperbyte with control commands, followed by lower bytes with control commands	*/
	byte_order[0] = upper_byte | COMMAND_BYTE;
	byte_order[1] = upper_byte | STROBE;
	byte_order[2] = lower_byte | COMMAND_BYTE;
	byte_order[3] = lower_byte | STROBE;

#ifdef CORTEX_M4
	HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, (uint8_t *)byte_order, sizeof(byte_order), 5);
#endif

}

void LCD_send_data(uint8_t data_to_sent){
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data_to_sent&0xf0);
	data_l = ((data_to_sent<<4)&0xf0);
	data_t[0] = data_u|0x0D;
	data_t[1] = data_u|0x09;
	data_t[2] = data_l|0x0D;
	data_t[3] = data_l|0x09;

#ifdef CORTEX_M4
	HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, (uint8_t *)data_t, sizeof(data_t), 5);
#endif

}

void LCD_send_string(char *string_to_send){
	while(*string_to_send){
		LCD_send_data(*string_to_send++);
	}
}

