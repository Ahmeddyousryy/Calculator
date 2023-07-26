#include "LCD_interface.h"
void H_LCD_Void_LCDInit()
{
#if LCD_MODE == _8_BIT_MODE
     	M_DIO_Void_SetPinDirection(LCD_D0,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_D1,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_D2,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_D3,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_D4,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_D5,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_D6,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_D7,OUTPUT);

		M_DIO_Void_SetPinDirection(LCD_RS,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_RW,OUTPUT);
		M_DIO_Void_SetPinDirection(LCD_EN,OUTPUT);

		M_DIO_Void_SetPinValue(LCD_RW,LOW);

		H_LCD_Void_LCDWriteCommand(LCD_8_BIT_MODE);
		_delay_ms(5);
		H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_COMMAND);
		_delay_ms(5);
		H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_4);
		_delay_ms(5);
		H_LCD_Void_LCDWriteCommand(0x01);

#elif LCD_MODE == _4_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_RS, OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RW, OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN, OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_D4, OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5, OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6, OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7, OUTPUT);

	M_DIO_Void_SetPinValue(LCD_RW,LOW);


	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_3);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_4);
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_COMMAND);


#endif
}





void H_LCD_Void_LCDWriteCharacter(u8 Copy_u8_Character)
{
	M_DIO_Void_SetPinValue(LCD_RS,HIGH);

#if LCD_MODE == _8_BIT_MODE
	     M_DIO_Void_SetPinValue(LCD_D0, GET_BIT(Copy_u8_Character,0));
		 M_DIO_Void_SetPinValue(LCD_D1, GET_BIT(Copy_u8_Character,1));
		 M_DIO_Void_SetPinValue(LCD_D2, GET_BIT(Copy_u8_Character,2));
		 M_DIO_Void_SetPinValue(LCD_D3, GET_BIT(Copy_u8_Character,3));
		 M_DIO_Void_SetPinValue(LCD_D4, GET_BIT(Copy_u8_Character,4));
		 M_DIO_Void_SetPinValue(LCD_D5, GET_BIT(Copy_u8_Character,5));
		 M_DIO_Void_SetPinValue(LCD_D6, GET_BIT(Copy_u8_Character,6));
		 M_DIO_Void_SetPinValue(LCD_D7, GET_BIT(Copy_u8_Character,7));


		 M_DIO_Void_SetPinValue(LCD_EN,HIGH);
		 _delay_ms(1);
		 M_DIO_Void_SetPinValue(LCD_EN,LOW);
#elif LCD_MODE == _4_BIT_MODE

		         M_DIO_Void_SetPinValue(LCD_D4, GET_BIT(Copy_u8_Character,4));
				 M_DIO_Void_SetPinValue(LCD_D5, GET_BIT(Copy_u8_Character,5));
				 M_DIO_Void_SetPinValue(LCD_D6, GET_BIT(Copy_u8_Character,6));
				 M_DIO_Void_SetPinValue(LCD_D7, GET_BIT(Copy_u8_Character,7));

				 M_DIO_Void_SetPinValue(LCD_EN, HIGH);
	             _delay_ms(1);
	             M_DIO_Void_SetPinValue(LCD_EN,LOW);


 		       M_DIO_Void_SetPinValue(LCD_D4, GET_BIT(Copy_u8_Character, 0));
         	   M_DIO_Void_SetPinValue(LCD_D5, GET_BIT(Copy_u8_Character, 1));
	           M_DIO_Void_SetPinValue(LCD_D6, GET_BIT(Copy_u8_Character, 2));
	           M_DIO_Void_SetPinValue(LCD_D7, GET_BIT(Copy_u8_Character, 3));

	           M_DIO_Void_SetPinValue(LCD_EN,HIGH);
	       	  _delay_ms(1);
	   		  M_DIO_Void_SetPinValue(LCD_EN,LOW);



#endif

	   		  _delay_ms(5);
}

void H_LCD_Void_LCDWriteCommand(u8 Copy_u8_Command)
{

	      M_DIO_Void_SetPinValue(LCD_RS,LOW);
#if LCD_MODE == _8_BIT_MODE
	         M_DIO_Void_SetPinValue(LCD_D0, GET_BIT(Copy_u8_Command,0));
			 M_DIO_Void_SetPinValue(LCD_D1, GET_BIT(Copy_u8_Command,1));
			 M_DIO_Void_SetPinValue(LCD_D2, GET_BIT(Copy_u8_Command,2));
			 M_DIO_Void_SetPinValue(LCD_D3, GET_BIT(Copy_u8_Command,3));
			 M_DIO_Void_SetPinValue(LCD_D4, GET_BIT(Copy_u8_Command,4));
			 M_DIO_Void_SetPinValue(LCD_D5, GET_BIT(Copy_u8_Command,5));
			 M_DIO_Void_SetPinValue(LCD_D6, GET_BIT(Copy_u8_Command,6));
			 M_DIO_Void_SetPinValue(LCD_D7, GET_BIT(Copy_u8_Command,7));

	     	M_DIO_Void_SetPinValue(LCD_EN, HIGH);
	    	_delay_ms(1);
	    	M_DIO_Void_SetPinValue(LCD_EN, LOW);
#elif LCD_MODE ==_4_BIT_MODE

	    	M_DIO_Void_SetPinValue(LCD_D4, GET_BIT(Copy_u8_Command, 4));
	    	M_DIO_Void_SetPinValue(LCD_D5, GET_BIT(Copy_u8_Command, 5));
	    	M_DIO_Void_SetPinValue(LCD_D6, GET_BIT(Copy_u8_Command, 6));
	    	M_DIO_Void_SetPinValue(LCD_D7, GET_BIT(Copy_u8_Command, 7));

	    	M_DIO_Void_SetPinValue(LCD_EN, HIGH);
	    	_delay_ms(1);
	    	M_DIO_Void_SetPinValue(LCD_EN, LOW);

	    	M_DIO_Void_SetPinValue(LCD_D4, GET_BIT(Copy_u8_Command, 0));
	    	M_DIO_Void_SetPinValue(LCD_D5, GET_BIT(Copy_u8_Command, 1));
	    	M_DIO_Void_SetPinValue(LCD_D6, GET_BIT(Copy_u8_Command, 2));
	    	M_DIO_Void_SetPinValue(LCD_D7, GET_BIT(Copy_u8_Command, 3));

	    	M_DIO_Void_SetPinValue(LCD_EN, HIGH);
	    	_delay_ms(1);
	    	M_DIO_Void_SetPinValue(LCD_EN, LOW);
#endif
	    	_delay_ms(5);
	}
void H_LCD_Void_LCDCLEAR()
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_COMMAND);
}
void H_LCD_Void_LCDWriteString(u8*Copy_u8_Arr)
{
	u8 Local_u8_Counter=0;
	while(Copy_u8_Arr[Local_u8_Counter]!=NULL)
	{
		 H_LCD_Void_LCDWriteCharacter(Copy_u8_Arr[Local_u8_Counter]);
		 Local_u8_Counter++;

	}
}
void H_LCD_Void_LCDWriteNumber(s32 Copy_S32_Number)
{
	s8 Local_S8_Counter = 0;
	u8 Local_U8_Arr[10] = {0};
	if(Copy_S32_Number < 0)
	{
		Copy_S32_Number = Copy_S32_Number * -1;
		H_LCD_Void_LCDWriteCharacter('-');
	}

	do
	{
		Local_U8_Arr[Local_S8_Counter] = Copy_S32_Number % 10;
		Copy_S32_Number                = Copy_S32_Number / 10;
		Local_S8_Counter++;
	}while(Copy_S32_Number != 0);

	while(Local_S8_Counter > 0)
	{
		H_LCD_Void_LCDWriteCharacter(Local_U8_Arr[--Local_S8_Counter] + 48);
	}
}


