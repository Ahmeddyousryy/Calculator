#include "STD.h"
#include "BitMath.h"
#include "LED_interface.h"
#include "BUZZER_interface.h"
#include "PB_interface.h"
#include "RELAY_interface.h"
#include "SSD_interface.h"
#include "LCD_interface.h"
#include "EXTINT_interface.h"
#include "TIMER_interface.h"
#include "WDT_interface.h"
#include "GI_interface.h"
#include "ADC_interface.h"
#include "UART_interface.h"
#include "I2C_interface.h"
#include "AT24C16A_interface.h"
#include "STEPPER_interface.h"
#include "KEYPAD_interface.h"
#include<util\/delay.h>
#include"string.h"

int main(void) {
	H_LCD_Void_LCDInit();
	H_KEYPAD__Void_KeyPadInit();
	char currentPass[] = "1974";  // THE CALCULATOR PASSWORD
	char enteredPass[4];          // THE PASSWORD THAT USER WILL ENTER
	char pass;
	char counter = 0;
	char comp = 0;
	while (1)
	{
		H_LCD_Void_LCDWriteString("Hello User");
		_delay_ms(2000);
		H_LCD_Void_LCDCLEAR();
		H_LCD_Void_LCDWriteString("Please Enter");
		H_LCD_Void_LCDWriteCommand(0xC0);
		H_LCD_Void_LCDWriteString("The Password");
		_delay_ms(2000);
		break;

	}
	H_LCD_Void_LCDCLEAR();
	while (1)
	{

		pass = H_KEYPAD_u8_KeyPadRead();
		while (pass != 0)
		{
			enteredPass[counter++] = pass;
			H_LCD_Void_LCDWriteCharacter('*');
			break;

		}
		if (counter == 4)
		{

			for (char i = 0; i < 4; i++)
			{
				if (enteredPass[i] != currentPass[i])
					comp = 1;
			}
			if (comp == 0)
			{
				H_LCD_Void_LCDCLEAR();
				H_LCD_Void_LCDWriteString("Correct");
				_delay_ms(2000);
				H_LCD_Void_LCDCLEAR();
				break;
			} else
			{
				H_LCD_Void_LCDCLEAR();
				H_LCD_Void_LCDWriteString("InCorrect");
				H_LCD_Void_LCDWriteCommand(0xC0);
				H_LCD_Void_LCDWriteString("Please retry");
				_delay_ms(2000);
				H_LCD_Void_LCDCLEAR();
				counter = 0;
				comp = 0;
			}
		}

	}

	H_LCD_Void_LCDWriteString("D = Enter");
	_delay_ms(2000);

	char exitFlag = '1';
	while (exitFlag == '1') {
		char firstNumber[4] = { 0 }, secondNumber[4] = { 0 };
		char operation;
		char finalOperation;
		char num;
		counter = 0;
		H_LCD_Void_LCDCLEAR();
		H_LCD_Void_LCDWriteString("First no. = ");
		while (1)
		{

			num = H_KEYPAD_u8_KeyPadRead();

			while (num != 0)
			{
				firstNumber[counter++] = num;
				if (num == 'D')
					break;
				H_LCD_Void_LCDWriteCharacter(num);
				break;
			}
			if (num == 'D')
				break;

		}
		H_LCD_Void_LCDCLEAR();
		while (1)
		{
			H_LCD_Void_LCDWriteString("Our operations");
			_delay_ms(2000);
			H_LCD_Void_LCDCLEAR();
			H_LCD_Void_LCDWriteString("A:add , B:sub");
			H_LCD_Void_LCDWriteCommand(0xC0);
			H_LCD_Void_LCDWriteString("C:mul");
			break;

		}
		while (1)
		{
			operation = H_KEYPAD_u8_KeyPadRead();
			while (operation != 0) {

				if (operation == 'A')
				{
					// H_LCD_Void_LCDWriteCharacter('+');
					finalOperation = operation;
					break;
				} else if (operation == 'B')
				{
					// H_LCD_Void_LCDWriteCharacter('-');
					finalOperation = operation;
					break;
				} else if (operation == 'C')
				{
					// H_LCD_Void_LCDWriteCharacter('x');
					finalOperation = operation;
					break;
				} else
					break;

			}
			if (operation == 'A' || operation == 'B' || operation == 'C')
				break;
			else
				continue;

		}

		H_LCD_Void_LCDCLEAR();
		H_LCD_Void_LCDWriteString("Second no = ");
		counter = 0;
		while (1)
		{
			num = H_KEYPAD_u8_KeyPadRead();

			while (num != 0)
			{
				secondNumber[counter++] = num;
				if (num == 'D')
					break;
				H_LCD_Void_LCDWriteCharacter(num);
				break;
			}
			if (num == 'D')
				break;
		}

		H_LCD_Void_LCDCLEAR();

		switch (finalOperation)
		{
		case 'A':
			H_LCD_Void_LCDWriteNumber(atoi(firstNumber) + atoi(secondNumber));
			break;
		case 'B':
			H_LCD_Void_LCDWriteNumber(atoi(firstNumber) - atoi(secondNumber));
			break;
		case 'C':
			H_LCD_Void_LCDWriteNumber(atoi(firstNumber) * atoi(secondNumber));
			break;
		default:
			break;
		}
		_delay_ms(3000);
		H_LCD_Void_LCDCLEAR();

		H_LCD_Void_LCDWriteString("1 to Continue");
		H_LCD_Void_LCDWriteCommand(0xC0);
		H_LCD_Void_LCDWriteString("0 to Exit");

		while (1)
		{
			exitFlag = H_KEYPAD_u8_KeyPadRead();
			if (exitFlag == 0)
				continue;
			else
				break;

		}
		if (exitFlag == '1')
			continue;
		else if (exitFlag == '0')
			break;

	}
	H_LCD_Void_LCDCLEAR();
	H_LCD_Void_LCDWriteString("Thank You");

}

