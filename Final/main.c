#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "STD.h"

/*Global Variables*/
u8 Global_u8FlagModes = 0;

/*Main Function*/
void main(void)
{
	/*This To Clear CMD*/
	system("cls");
	
	/*Local Variables*/
	u8 Local_u8ExitFlag = 0, Local_u8Mode = 0, Usles, Local_u8PasswordFlag = 0;
	u8 Local_u8AdminFeature = 0;
	
	/*Loop for the Whole Program Exit by setting the flag Local_u8ExitFlag*/
	while(Local_u8ExitFlag == 0)
	{
		/*Calling the Clinic_u8Modes Function and get the return in Local_u8Mode Variable*/
		Lable_1:
		Local_u8Mode = Clinic_u8Modes(Global_u8FlagModes);
		
		/*Switch on the Local_u8Mode Variable*/
		switch(Local_u8Mode)
		{
			/*if it equals 1 that is a Admin Mode Case*/
			case Admin_Mode:
			/*This Function to clear the CMD*/
			system("cls");
			
			/*Clear this Flag to because you have Entered a right Choice*/
			Global_u8FlagModes = 0;
			
			/*Calling function like macro for the clinic introduction*/
			Clinic_Introduction();
			
			/*Ask the User to Enter the Password*/
			printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
			printf("\n\nPlease, Enter Your Password: ");
			
			/*Calling the Admin Password function to enter and check the password*/
			Local_u8PasswordFlag = Clinic_u8AdminPassword();
			
			/*if the returned value true call the adminFunctions*/
			if(Local_u8PasswordFlag == True)
			{
				printf("Password Is True");
				Lable_2:
				Local_u8AdminFeature = Clinic_u8AdminFunctionalities();
				
				/*Switch on the input from the User to choose the Feature*/
				switch(Local_u8AdminFeature)
				{
					/*case 1 as Enum Admin Features*/
					case Add_New_Patient_Record:
					/*Call the function of adding new patient*/
					Clinic_voidAddNewPatient();
					goto Lable_2;
					break;
					
					/*case 2 as Enum Admin Features*/
					case Edit_Patient_Record:
					printf("Edit_New_Patient");
					scanf("%d", &Local_u8AdminFeature);
					break;
					
					/*case 3 as Enum Admin Features*/
					case Reserve_a_Slot_With_The_DoctOR:
					printf("Reserve_a_Slot_With_The_DoctOR");
					scanf("%d", &Local_u8AdminFeature);
					break;
					
					/*case 4 as Enum Admin Features*/
					case Cancel_Reservation:
					printf("Cancel_Reservation");
					scanf("%d", &Local_u8AdminFeature);
					break;
					
					/*default go to Clinic Modes again*/
					default:
					//Local_u8Mode = Clinic_u8Modes(Global_u8FlagModes);
					goto Lable_1;
					break;
				}
			}
			
			/*if the returend value false terminate the loop*/
			else
			{
				Local_u8ExitFlag = 1;
			}
			Global_u8FlagModes = 0;
			Local_u8Mode = 0;
			Local_u8PasswordFlag = 0;
			break;
			
			/*if it equals 1 that is a Admin Mode Case*/
			case User_Mode:
			/*Clear this Flag to because you have Entered a right Choice*/
			Global_u8FlagModes = 0;
			Clinic_voidPrintList();
			scanf("%d", &Usles);
			break;
			
			/*if it equals 1 that is a Admin Mode Case*/
			case Exit_The_System:
			printf("\n\t\t\t\t\t\t\t\t  ******Thank you******");
			printf("\n\t\t\t\t\t\t\t ****************************************");
			Local_u8ExitFlag = 1;
			break;
			
			/*if it equals 1 that is a Admin Mode Case*/
			default:
			/*This Flag to check your choice in clinic moode function*/
			Global_u8FlagModes++;
			
			/*This Function to clear the CMD*/
			system("cls");
			break;
		}
		Global_u8FlagModes = 0;
		Local_u8Mode = 0;
		Local_u8PasswordFlag = 0;
	}
}

