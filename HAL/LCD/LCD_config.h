/*
 * LCD_config.h
 *
 *  Created on: Sep 10, 2022
 *      Author: HP
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_D0                  PA0_PIN
#define LCD_D1                  PA1_PIN
#define LCD_D2                  PA2_PIN
#define LCD_D3                  PA3_PIN
#define LCD_D4                  PA4_PIN
#define LCD_D5                  PA5_PIN
#define LCD_D6                  PA6_PIN
#define LCD_D7                  PA7_PIN


#define LCD_RS                  PB1_PIN
#define LCD_RW                  PB2_PIN
#define LCD_EN                  PB3_PIN

#define LCD_MODE               _4_BIT_MODE
// Select between _4_BIT_MODE  OR _8_BIT_MODE

#endif /* HAL_LCD_LCD_CONFIG_H_ */
