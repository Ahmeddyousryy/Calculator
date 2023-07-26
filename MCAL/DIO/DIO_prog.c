#include"DIO_interface.h"
#include "DIO_private.h"
void M_DIO_Void_SetPinDirection(u8 Copy_u8_Group,u8 Copy_u8_State)
{
	u8 Local_u8_Group=Copy_u8_Group/10;
	u8 Local_u8_Pin=Copy_u8_Group%10;
	if(Copy_u8_State)
	{

	  switch(Local_u8_Group)
	    {
	     case 1:
	    	        SET_BIT(DDRA,Local_u8_Pin);
			         break;
	     case 2:
	     	    	 SET_BIT(DDRB,Local_u8_Pin);
	     			 break;
	     case 3:
	     	    	 SET_BIT(DDRC,Local_u8_Pin);
	     			 break;
	     case 4:
	     	    	 SET_BIT(DDRD,Local_u8_Pin);
	     			 break;

       	}

    }
	else
	{
		switch(Local_u8_Group)
			    {
			     case 1:
			    	        CLR_BIT(DDRA,Local_u8_Pin);
					         break;
			     case 2:
			     	    	 CLR_BIT(DDRB,Local_u8_Pin);
			     			 break;
			     case 3:
			     	    	 CLR_BIT(DDRC,Local_u8_Pin);
			     			 break;
			     case 4:
			     	    	 CLR_BIT(DDRD,Local_u8_Pin);
			     			 break;

		       	}
	}

}
void M_DIO_Void_SetPinValue(u8 Copy_u8_Group,u8 Copy_u8_State)
{
	u8 Local_u8_Group=Copy_u8_Group/10;
	u8 Local_u8_Pin=Copy_u8_Group%10;
	if(Copy_u8_State)
	{

	  switch(Local_u8_Group)
	    {
	     case 1:
	    	        SET_BIT(PORTA,Local_u8_Pin);
			         break;
	     case 2:
	     	    	 SET_BIT(PORTB,Local_u8_Pin);
	     			 break;
	     case 3:
	     	    	 SET_BIT(PORTC,Local_u8_Pin);
	     			 break;
	     case 4:
	     	    	 SET_BIT(PORTD,Local_u8_Pin);
	     			 break;

       	}

    }
	else
	{
		switch(Local_u8_Group)
			    {
			     case 1:
			    	        CLR_BIT(PORTA,Local_u8_Pin);
					         break;
			     case 2:
			     	    	 CLR_BIT(PORTB,Local_u8_Pin);
			     			 break;
			     case 3:
			     	    	 CLR_BIT(PORTC,Local_u8_Pin);
			     			 break;
			     case 4:
			     	    	 CLR_BIT(PORTD,Local_u8_Pin);
			     			 break;

		       	}
	}

}
u8 M_DIO_u8_GetPinValue(u8 Copy_u8_Value)
{
	u8 Local_u8_Group=Copy_u8_Value/10;
	u8 Local_u8_Pin=Copy_u8_Value%10;
	u8 Local_u8_Return;
	switch (Local_u8_Group)
	{
	                 case 1:
	                	 Local_u8_Return= GET_BIT(PINA,Local_u8_Pin);
						         break;
				     case 2:
				    	 Local_u8_Return= GET_BIT(PINB,Local_u8_Pin);
				     			 break;
				     case 3:
				    	 Local_u8_Return= GET_BIT(PINC,Local_u8_Pin);
				     			 break;
				     case 4:
				    	 Local_u8_Return= GET_BIT(PIND,Local_u8_Pin);
				     			 break;
	}
	return Local_u8_Return;


}
void M_DIO_Void_ToggPin(u8 Copy_u8_Group)
{
	u8 Local_u8_Group=Copy_u8_Group/10;
	u8 Local_u8_Pin=Copy_u8_Group%10;
	 switch(Local_u8_Group)
		    {
		     case 1:
		    	        TOG_BIT(PORTA,Local_u8_Pin);
				         break;
		     case 2:
		     	    	 TOG_BIT(PORTB,Local_u8_Pin);
		     			 break;
		     case 3:
		     	    	 TOG_BIT(PORTC,Local_u8_Pin);
		     			 break;
		     case 4:
		     	    	 TOG_BIT(PORTD,Local_u8_Pin);
		     			 break;

	       	}
}
void M_DIO_Void_SetPinPullUpRes(u8 Copy_u8_Group,u8 Copy_u8_State)
{
	u8 Local_u8_Group=Copy_u8_Group/10;
		u8 Local_u8_Pin=Copy_u8_Group%10;
		if(Copy_u8_State==ENABLE)
		{

		  switch(Local_u8_Group)
		    {
		     case 1:
		    	        SET_BIT(PORTA,Local_u8_Pin);
				         break;
		     case 2:
		     	    	 SET_BIT(PORTB,Local_u8_Pin);
		     			 break;
		     case 3:
		     	    	 SET_BIT(PORTC,Local_u8_Pin);
		     			 break;
		     case 4:
		     	    	 SET_BIT(PORTD,Local_u8_Pin);
		     			 break;

	       	}

	    }
		else
		{
			switch(Local_u8_Group)
				    {
				     case 1:
				    	        CLR_BIT(PORTA,Local_u8_Pin);
						         break;
				     case 2:
				     	    	 CLR_BIT(PORTB,Local_u8_Pin);
				     			 break;
				     case 3:
				     	    	 CLR_BIT(PORTC,Local_u8_Pin);
				     			 break;
				     case 4:
				     	    	 CLR_BIT(PORTD,Local_u8_Pin);
				     			 break;

			       	}
		}
}



