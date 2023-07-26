/*
 * KEYPAD_prog.c
 *
 *  Created on: Sep 16, 2022
 *      Author: HP
 */
#include "KEYPAD_interface.h"
void H_KEYPAD__Void_KeyPadInit(void)
{
	M_DIO_Void_SetPinDirection(KEYPAD_R0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R3_PIN,OUTPUT);


	M_DIO_Void_SetPinValue(KEYPAD_R0_PIN, HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R1_PIN, HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R2_PIN, HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R3_PIN, HIGH);

	M_DIO_Void_SetPinDirection(KEYPAD_C0_PIN, INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C1_PIN, INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C2_PIN, INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C3_PIN, INPUT);

	M_DIO_Void_SetPinPullUpRes(KEYPAD_C0_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C1_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C2_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C3_PIN,ENABLE);

}

u8 H_KEYPAD_u8_KeyPadRead(void)
{

	u8 Local_u8_Reading=0;
	u8 Local_u8_Col;
	u8 Local_u8_Row;
#if KEYPAD == KEYPAD_MODEL_A

	u8 Local_u8_Arr[4][4] =     {
			                    {'1','2','3','A'},
	                            {'4','5','6','B'},
							    {'7','8','9','C'},
							    {'*','0','#','D'}
	                            };
#elif KEYPAD == KEYPAD_MODEL_B

	u8 Local_u8_Arr[4][4] =     {
				                    {'1','2','3','A'},
		                            {'4','5','6','B'},
								    {'7','8','9','C'},
								    {'*','0','#','D'}
		                            };
	#endif

   for(Local_u8_Row=KEYPAD_R0_PIN;Local_u8_Row<=KEYPAD_R3_PIN;Local_u8_Row++)
    {
    	  M_DIO_Void_SetPinValue(Local_u8_Row,LOW);
    	for(Local_u8_Col=KEYPAD_C0_PIN;Local_u8_Col<=KEYPAD_C3_PIN;Local_u8_Col++)
    	{

    		if(M_DIO_u8_GetPinValue(Local_u8_Col)==0)
    		{
    			_delay_ms(120);                               //to avoid bouncing
    			if(M_DIO_u8_GetPinValue(Local_u8_Col)==0)
    			{
    			while(M_DIO_u8_GetPinValue(Local_u8_Col)==0);  //to stuck here
                Local_u8_Reading = Local_u8_Arr[Local_u8_Row - KEYPAD_R0_PIN  ][Local_u8_Col - KEYPAD_C0_PIN];
    		    break;
    			}
    		   }
    		}
               if(Local_u8_Reading!=0)
            	   break;

    	 M_DIO_Void_SetPinValue(Local_u8_Row,HIGH);
     }
     return Local_u8_Reading;
}



