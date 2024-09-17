/*
 * LCD_I2C.c
 *
 *  Created on: Sep 16, 2024
 *      Author: simpleyetfulling
 */


#include "16x2_LCD.h"

void LCD_init(void){
	  // 4 bit initialisation
	  HAL_Delay(50);  
	  LCD_send_command(0x30);
	  HAL_Delay(5); 
	  LCD_send_command(0x30);
	  HAL_Delay(1);
	  LCD_send_command(0x30);
	  HAL_Delay(10);
	  LCD_send_command(0x20);  // 4bit mode
	  HAL_Delay(10);

	  // display initialisation
	  LCD_send_command(0x28); // Function set (4 bit mode), (2 line display) (5x8 characters)
	  HAL_Delay(1);
	  LCD_send_command(0x08); //Display on/off control ---> display off
	  HAL_Delay(1);
	  LCD_send_command(0x01);  // clear display
	  HAL_Delay(2);
	  LCD_send_command(0x06); //Entry mode set -->(increment cursor)  (no shift)
	  HAL_Delay(1);
	  LCD_send_command(0x0C); //Display on/off control -->  (Cursor and blink, last two bits)
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
	uint8_t upper_byte, lower_byte;
	uint8_t byte_order[4];

	upper_byte = (data_to_sent & 0xf0);
	lower_byte = ((data_to_sent << 4) & 0xf0);

	byte_order[0] = upper_byte | 0x0D;
	byte_order[1] = upper_byte | 0x09;
	byte_order[2] = lower_byte | 0x0D;
	byte_order[3] = lower_byte | 0x09;

#ifdef CORTEX_M4
	HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, (uint8_t *)byte_order, sizeof(byte_order), 5);
#endif

}

void LCD_send_string(char *string_to_send){
	while(*string_to_send){
		LCD_send_data(*string_to_send++);
	}
}

