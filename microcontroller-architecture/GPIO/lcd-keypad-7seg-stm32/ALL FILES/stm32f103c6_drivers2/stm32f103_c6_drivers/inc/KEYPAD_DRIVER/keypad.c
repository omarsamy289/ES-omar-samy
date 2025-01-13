/*
 * keypad.c
 *
 * Created: 12/19/2024 4:25:38 PM
 *  Author: omar
 */

#include <KEYPAD_DRIVER/keypad.h>
int Keypad_Row[] = { ROW1, ROW2, ROW3, ROW4 }; //rows of the keypad
int Keypad_Col[] = { COL1, COL2, COL3, COL4 }; //columns

void KEYPAD_INIT() {
//
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW1) ;
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW2) ;
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW3) ;
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW4) ;
	pinconfig.PinNumber = ROW1;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = ROW2;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = ROW3;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = ROW4;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = COL1;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);
	pinconfig.PinNumber = COL2;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = COL3;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = COL4;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

//	SET_BIT (DataDir_KEYPAD_PORT,COL1) ;
//	SET_BIT (DataDir_KEYPAD_PORT,COL2) ;
//	SET_BIT (DataDir_KEYPAD_PORT,COL3) ;
//	SET_BIT (DataDir_KEYPAD_PORT,COL4) ;
//	KEYPAD_PORT = 0xFF;
	MCAL_GPIO_WRITEPORT(KEYPAD_PORT, 0xFF);
}


char KEYPAD_GETKEY() {

	volatile unsigned int i, j;

	for (i = 0; i < 4; i++) {

//		SET_BIT(KEYPAD_PORT,Keypad_Col[0]) ;
//		SET_BIT(KEYPAD_PORT,Keypad_Col[1]) ;
//		SET_BIT(KEYPAD_PORT,Keypad_Col[2]) ;
//		SET_BIT(KEYPAD_PORT,Keypad_Col[3]) ;
//		RESET_BIT(KEYPAD_PORT,Keypad_Col[i]) ;

		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[0], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[1], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[2], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[3], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[i], PIN_RESET);

		for (j = 0; j < 4; j++) {

			if ((MCAL_GPIO_READPIN(KEYPAD_PORT,Keypad_Row[j])) == 0) {
				while (!(MCAL_GPIO_READPIN(KEYPAD_PORT,Keypad_Row[j])));
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'A';

}
