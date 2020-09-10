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
	u8 Local_u8ExitFlag = 0, Local_u8Mode = 0, Usles, Local_u8PasswordFlag = 0, Local_u8ReserveIDFlag = 0;
	u8 Local_u8AdminFeature = 0, Local_u8EditFalg = 0, Local_u8EditIDFlag = 0, Local_u8PrintFlag = 0; 
	u8 Local_u8TryAnotherIDFlag = 0, Local_u8CancelReservationFlag = 0, Local_u8UserFeature = 0;
	u8 Local_u8PatientRecordFlag = 0, Local_u8Flag = 0, Local_u8UserFlag = 0;
	u32 Local_u32ID = 0;
	
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
					Lable_4:
					/*This Function to clear the CMD*/
					system("cls");
					
					/*Calling the Function like Macro for the Clinic Introduction*/
					Clinic_Introduction();
					
					/*make the user know that you are in admin mode*/
					printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
					
					/*Ask the User to Enter The Patient ID to Edit*/
					printf("\nPlease, Enter the Patient ID to Edit: ");
					scanf("%d", &Local_u32ID);
					
					/*Call the Edit Function and make a flag to recieve the return Value*/
					Local_u8EditIDFlag = Clinic_u8EditPatientRecord(Local_u32ID);
					
					/*If the Flag Value = 1 That is mean the ID is not Found*/
					if(Local_u8EditIDFlag == 1)
					{
						printf("\n\nThe ID you have Entered is not Found");
						
						/*Ask if you want to try another ID and make a flag to assign the Value in*/
						printf("\nDo you want to try again\t[1]Yes\t[2]No\nPlease, Enter your Choice: ");
						scanf("%d", &Local_u8EditFalg);
						
						/*if Yes go to Lable_4 if no go to Lable_2*/
						if(Local_u8EditFalg == Yes)
						{
							/*Lable_4 is the start of Case Edit Patient in Admin Functionalities*/
							goto Lable_4;
						}
						else
						{
							/*Lable_2 is Back to the Admin Functionalities*/
							goto Lable_2;
						}
					}
					
					/*Clear the Local Variable*/
					Local_u32ID = 0;
					
					/*Ask the user if want to Edit another patient and make a flag to assign the Value*/
					printf("\nDo you want to Edit another Patient record\t[1]Yes\t[2]No\nPlease, Enter your Choice: ");
					scanf("%d", &Local_u8EditFalg);
					
					/*if Yes go to Lable_4 if no go to Lable_2*/
					if(Local_u8EditFalg == Yes)
					{
						/*Lable_4 is the start of Case Edit Patient in Admin Functionalities*/
						goto Lable_4;
					}
					else 
					{
						/*Lable_2 is Back to the Admin Functionalities*/
						goto Lable_2;
					}
					break;
					
					/*case 3 as Enum Admin Features*/
					case Reserve_a_Slot_With_The_DoctOR:
					/*get the user to the first of case 3 Reserve_a_Slot_With_The_DoctOR*/
					Lable_6:
					
					/*This Function to clear the CMD*/
					system("cls");
					
					/*Calling the Function like Macro for the Clinic Introduction*/
					Clinic_Introduction();
					
					/*make the user know that you are in admin mode*/
					printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
					printf("\nPlease, Enter The Patient ID: ");
					scanf("%d", &Local_u32ID);
					
					/*Call the Edit Function and make a flag to recieve the return Value*/
					Local_u8ReserveIDFlag = Clinic_u8ReservePatientSlot(Local_u32ID);
					
					/*if Function returend flag with one that's mean it is un-valied ID as the user if he want to try another ID*/
					if(Local_u8ReserveIDFlag == 1)
					{
						printf("\nThe ID not Found");
						printf("\nDo you want to try another ID [1]Yes\t[2]No");
						scanf("%d", &Local_u8TryAnotherIDFlag);
						
						/*if Yes goto Lable_6 back to the first of Case 3 Reserve_a_Slot_With_The_DoctOR*/
						if(Local_u8TryAnotherIDFlag == 1)
						{
							goto Lable_6;
						}
					}
					/*else back to the Admin Functionalities*/
					else
					{
						goto Lable_2;
					}
					break;
					
					/*case 4 as Enum Admin Features*/
					case Cancel_Reservation:
					Lable_8:
					/*This Function to clear the CMD*/
					system("cls");
					
					/*Calling the Function like Macro for the Clinic Introduction*/
					Clinic_Introduction();
					
					/*make the user know that you are in admin mode*/
					printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
					
					/*Ask the User to Enter The ID*/
					printf("\nPlease, Enter The Patient ID: ");
					scanf("%d", &Local_u32ID);
					
					/*Call a function Cancel Reservation with Return flag for the un-Valied IDs*/
					Local_u8CancelReservationFlag = Clinic_u8CancelReservation(Local_u32ID);
					
					/*If the Return = 1 means the ID is not Found and Ask if you want to try another ID*/
					if(Local_u8CancelReservationFlag == 1)
					{
						printf("\nThe ID not Found");
						printf("\nDo you want to try another ID [1]Yes\t[2]No");
						scanf("%d", &Local_u8TryAnotherIDFlag);
						
						/*if Yes goto Lable_6 back to the first of Case 3 Reserve_a_Slot_With_The_DoctOR*/
						if(Local_u8TryAnotherIDFlag == 1)
						{
							goto Lable_8;
						}
					}
					/*else back to the Admin Functionalities*/
					else
					{
						goto Lable_2;
					}
					break;
					
					/*case 5 as Enum Admin Features*/
					case Print_All_Patients_Records:
					/*This Function to clear the CMD*/
					system("cls");
					
					/*Calling the Function like Macro for the Clinic Introduction*/
					Clinic_Introduction();
					
					/*make the user know that you are in admin mode*/
					printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
					/*Clear this Flag to because you have Entered a right Choice*/
					Global_u8FlagModes = 0;
					Local_u8PrintFlag = 0;
					
					/*Call the function to print the List with return if the List is Empty*/
					Local_u8PrintFlag = Clinic_voidPrintList();
					if(Local_u8PrintFlag == 1)
					{
						printf("\n\t\t\t\t\t\t\t\t****The List is Empty****");
					}
					
					printf("\n\n\nto back to admin features press [1]Yes\nplease, Enter your Choice: ");
					scanf("%d", &Local_u8Flag);
					if(Local_u8Flag == 1)
					{
						/*goto admin Functionalities*/
						goto Lable_2;
					}
					else
					{
						/*go to Choosing Mode*/
						goto Lable_1;
					}
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
			
			/*Clear the Used Variables*/
			Global_u8FlagModes = 0;
			Local_u8Mode = 0;
			Local_u8PasswordFlag = 0;
			break;
			
			
			
			
			/*Case 2 User Mode*/
			case User_Mode:
			Lable_10:
			Local_u8TryAnotherIDFlag = 0;
			/*This Function to clear the CMD*/
			system("cls");
			
			/*Calling the Function like Macro for the Clinic Introduction*/
			Clinic_Introduction();
			
			/*make the user know that you are in user mode*/
			printf("\n\t\t\t\t\t\t\t\tYou are on User Mode\n");
			
			/*ask the user to choose from the User Functionalities*/
			printf("Please, Choose one of These Features:-\n");
			USER_FEARURES();
			printf("\n\nPlease, Enter your choice: ");
			scanf("%d", &Local_u8UserFeature);
			
			/*Switch for the User Functionalities*/
			switch(Local_u8UserFeature)
			{
				/*Case 1 to view Ptient Record*/
				case View_Patient_Record:
				Lable_9:
				/*This Function to clear the CMD*/
				system("cls");
				
				/*Calling the Function like Macro for the Clinic Introduction*/
				Clinic_Introduction();
				
				/*make the user know that you are in admin mode*/
				printf("\n\t\t\t\t\t\t\t\tYou are on User Mode");
				
				/*Ask the User to Enter the ID*/
				printf("\nPlease, Enter The Patient ID: ");
				scanf("%d", &Local_u32ID);
				
				/*Call the function and give ID as Paramter and return the flag if the ID is not found*/
				Local_u8PatientRecordFlag = Clinic_u8ViewPatientRecord(Local_u32ID);
				if(Local_u8PatientRecordFlag == 1)
				{
					printf("\nThe ID not Found");
					printf("\nDo you want to try another ID [1]Yes\t[2]No");
					scanf("%d", &Local_u8TryAnotherIDFlag);
					
					/*if Yes goto Lable_9 back to the first of Case 1 View_Patient_Record*/
					if(Local_u8TryAnotherIDFlag == 1)
					{
						goto Lable_9;
					}
				}
				/*else back to the Admin Functionalities*/
				else
				{
					printf("\n\nPlease, press any Key followed by Enter to get back to user mode: ");
					scanf("%d", &Local_u8UserFlag);
					
					/*go back to User Mode*/
					goto Lable_10;
				}
				break;
				
				case View_Today_Reservations:
				/*This Function to clear the CMD*/
				system("cls");
				
				/*Calling the Function like Macro for the Clinic Introduction*/
				Clinic_Introduction();
				
				/*make the user know that you are in admin mode*/
				printf("\n\t\t\t\t\t\t\t\tYou are on User Mode");
				Clinic_voidViewReservation();
				printf("\n\nPlease, press any Key followed by Enter to get back to user mode: ");
				scanf("%d", &Local_u8UserFlag);
				goto Lable_10;
				break;
				
				default:
				goto Lable_1;
				break;
			}
			
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