/*
 * LCD_interface.h
 *
 *  Created on: Sep 19, 2022
 *      Author: HP
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "DIO_interface.h"
#include "STD.h"
#include "BitMath.h"
#include "LCD_private.h"
#include "LCD_config.h"

void H_LCD_Void_LCDInit();
void H_LCD_Void_LCDWriteCharacter(u8);
void H_LCD_Void_LCDWriteCommand(u8);
void H_LCD_Void_LCDCLEAR();
void H_LCD_Void_LCDWriteString(u8*);
void H_LCD_Void_LCDWriteNumber(s32);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
