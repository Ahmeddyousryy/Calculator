/*
 * KEYPAD_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: HP
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_
#include "STD.h"
#
#include "DIO_interface.h"
#include "KEYPAD_config.h"
void H_KEYPAD__Void_KeyPadInit(void);
u8 H_KEYPAD_u8_KeyPadRead(void);


#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
