#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "STD.h"

/*Global Variables*/
extern u8 Global_u8FlagModes;
extern Slot Week[7];
u32 Global_u32ListLegnth = 0;
Patient Global_PatientNewPatient;
Slot Week[7];
Patient *New;
Patient *Last;

/*Description: This Function to get witch mode that you want Admin Mode or User Mode or Exit_The_System
 *Arguments	 : it Takes the Flag of the Modes if it = 0 so you choose right choice if not invaled choice
 *Returns	 : it returns the Mode Number Admin_Mode, User_Mode, Exit_The_System
 */
u8 Clinic_u8Modes(u8 Copy_u8FlagMode)
{
	/*Local Variables*/
	u8 Local_u8Mode = 0;
	
	/*This Function to clear the CMD*/
	system("cls");
	
	/*if the Flag != 0 that's mean you have Entered Invaled Choice*/
	while(Copy_u8FlagMode != 0)
	{
		/*This Function to clear the CMD*/
		system("cls");
		
		/*Calling the Function like Macro for the Clinic Introduction*/
		Clinic_Introduction();
		
		/*Take the user choice and put it in a variable Local_u8Mode*/
		printf("Invailed Choice Please, Try again with right Choice");
		printf("\nPlease, Enter the Number of the next Features: \n");
		printf("\n[1]Admin Mode\n[2]User Mode\n[3]Exit the System\n");
		printf("\nYour Choice is: ");
		scanf("%d", &Local_u8Mode);
		
		/*breaking the loop*/
		break;
	}
	
	/*of the flag = 0 that is mean this is first choice*/
	while(Copy_u8FlagMode == 0)
	{
		/*This Function to clear the CMD*/
		system("cls");
		
		/*Calling the Function like Macro for the Clinic Introduction*/
		Clinic_Introduction();
		
		/*Take the user choice and put it in a variable Local_u8Mode*/
		printf("\nPlease, Enter the Number of the next Features: \n");
		printf("\n[1]Admin Mode\n[2]User Mode\n[3]Exit the System\n");
		printf("\nYour Choice is: ");
		scanf("%d", &Local_u8Mode);
		
		/*breaking the loop*/
		break;
	}
	
	/*return the moode choosen by the user*/
	return Local_u8Mode;
}

/*Description: This Function to get the Admin Password and check if it true or false and send the flag 
 *Arguments	 : No Arguments
 *Returns	 : it returns the Flag if Password True = 1 or False = 0
 */
u8 Clinic_u8AdminPassword()
{
	/*Local Variables*/
	/*Iteration is Static because if it is not static it will make increment every time*/
	u8 static Local_u8Iteration = 0, Local_u8PasswordFlag = 0;
	
	/*Password saved in u16 variable*/
	u16 Local_u16Password = 0;
	
	/*Loop for 3 trials and then give an Error and go to the main menue*/
	for(Local_u8Iteration = 0; Local_u8Iteration < 3; Local_u8Iteration++)
	{
		/*First check for the Password if true break and return the Password Flag*/
		if(Local_u16Password == PasswordDefined)
		{
			Local_u8PasswordFlag = True;
			break;
		}
		
		/*then if it is wrong scan the password from the user*/
		scanf("%d", &Local_u16Password);
		
		/*check the scaned value if true break and return the Password Flag*/
		if(Local_u16Password == PasswordDefined)
		{
			Local_u8PasswordFlag = True;
			break;
		}
		/*if user reach third trials with false terminate the loop and go to the main menue*/
		if(Local_u8Iteration == 2)
		{
			printf("\n\n\t\t\t\t\t\t\tYou have Entered the Password 3 Times Wrong");
			printf("\n\t\t\t\t\t\t\t\t\t****BYE BYE****");
			Local_u8PasswordFlag = False;
			Local_u8Iteration = 0;
			break;
		}
		/*if the Password wrong and still before 3 trails please try again*/
		else
		{
			printf("\n****Invalid Password****\n\nPlease, Re-Enter the right Password: ");
		}
	}
	/*Return the flag*/
	return Local_u8PasswordFlag;
}

/*Description: This Function provides all the Admin Functionalites[Add_New_Patient_Record, Edit_Patient_Record
				Reserve_a_Slot_With_The_DoctOR, Cancel_Reservation] 
 *Arguments	 : No Arguments
 *Returns	 : the choosen admin feature
 */
u8 Clinic_u8AdminFunctionalities()
{
	/*Local Variables*/
	u8 Local_u8AdminFeature;
	
	/*This Function to clear the CMD*/
	system("cls");
	
	/*Calling the Function like Macro for the Clinic Introduction*/
	Clinic_Introduction();
	
	/*print that you are in admin Mode and Ask user to choose a Feature*/
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	printf("\nPlease, Choose one of this Features:- \n");
	
	/*Call Function like Macro to print Admin Features*/
	ADMIN_FEATURES();
	printf("\n\nPlease, Enter the number of the Feature: ");
	scanf("%d", &Local_u8AdminFeature);

	return Local_u8AdminFeature;
}

/*Description: This Function to Adding a new Patient by making new Node and assign values to it and allocate it in LinkedList 
 *Arguments	 : No Arguments
 *Returns	 : Non
 */
void Clinic_voidAddNewPatient()
{
	/*Local Variables*/
	u8 static Local_u8Iteration2 = 0, Local_u8FlagID = 0, Local_u8Again = 0, Local_u8FlagAgain = 0;
	u32 Local_u32IDCheck = 0, Local_u8IDUnique = 0;
	//Patient Copy_Patient;
	
	/*This Function to clear the CMD*/
	system("cls");
	
	/*Calling the Function like Macro for the Clinic Introduction*/
	Clinic_Introduction();
	
	/*make the user know that you are in admin mode*/
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	
	/*If liked list length = 0 that is mean it is Empty and that is to creat first Node*/
	if(Global_u32ListLegnth == 0)
	{
		/*Add Patient ID*/
		printf("\nPlease, Enter Patient ID: ");
		scanf("%d", &Global_PatientNewPatient.Struct_u32ID);
		
		/*Patient Name*/
		printf("\nPlease, Enter Patient Name: ");
		scanf("%s", &(Global_PatientNewPatient.Struct_u8Name));
		//gets((Global_PatientNewPatient.Struct_u8Name));
		
		/*Patient Age*/
		printf("\nPlease, Enter Patient Age: ");
		scanf("%d", &Global_PatientNewPatient.Struct_u8Age);
		
		/*this for assign patient gender*/
		while(True)
		{
			printf("\nPlease, Enter the Patient Gender: [1]Male\t[2]Female\n");
			printf("\t\tPatient Gender is: ");
			scanf("%d", &Global_PatientNewPatient.Struct_u8Gender);
			if((Global_PatientNewPatient.Struct_u8Gender == Male) || (Global_PatientNewPatient.Struct_u8Gender == Female))
			{
				break;
			}
			else
			{
				printf("\nPlease, Choose between:\n[1]Male\t[2]Female\n");
			}
		}
	}
	
	/*if the list not empty*/
	else
	{
		/*Creat a Pointer to struct to make the new Node and we used 
		  Malloc to creat the same size of our original struct Node*/
		New = (Patient*)malloc(sizeof(Patient));
		
		/*Ask user to Enter the ID*/
		printf("\nPlease, Enter the Patient ID: ");
		
		/*Check the ID for three times if it repeated or not*/
		//for(Local_u8Iteration2 = 0; Local_u8Iteration2 < 3; Local_u8Iteration2++)
		while(Local_u8IDUnique == 0)
		{
			scanf("%d", &Local_u32IDCheck);
			
			/*call the function of ID Checking and send the ID to it to check*/
			Local_u8FlagID = Clinic_u8IDChecking(Local_u32IDCheck);
			
			/*if ID not repeated assign the values to the new node*/
			if(Local_u8FlagID == False)
			{
				printf("\nID is Not Repeated\n\n");
				(New -> Struct_u32ID) = Local_u32IDCheck;
				Local_u8IDUnique = 1;
			}
			
			/*if it repeated please tey again*/
			else if(Local_u8FlagID == True)
			{
				printf("ID is Repeated Please, try another ID: ");
			}
		}
		Local_u8IDUnique = 0;
		Local_u8FlagID = 0;
		// for(Local_u8Iteration2 = 0; Local_u8Iteration2 < 3; Local_u8Iteration2++)
		// {
			// scanf("%d", &Local_u32IDCheck);
			
			// Copy_Patient = Clinic_PatientIDChecking(Local_u32IDCheck);
			
			// if(Copy_Patient.Struct_u32ID != Local_u32IDCheck)
			// {
				// printf("\nID is Not Repeated\n\n");
				// (New -> Struct_u32ID) = Local_u32IDCheck;;
				// break;
			// }
			// else if(Copy_Patient.Struct_u32ID == Local_u32IDCheck)
			// {
				// printf("ID is repeated please, try another ID: ");
			// }
			
			// if(Local_u8Iteration2 == 2)
			// {
				// printf("\n\t\t*****You have Enterd wrong ID 3 times*****\n");
				// Clinic_u8AdminFunctionalities();
			// }
		// }
		
		/*Assign the Name to the new Node*/
		printf("Please, Enter Patient Name: ");
		scanf("%s", &(New -> Struct_u8Name));
		//gets((New -> Struct_u8Name));
		
		/*Assign the Age to the New Node*/
		printf("\nPlease, Enter Patient Age: ");
		scanf("%d", &New -> Struct_u8Age);
		
		/*this loop for checking the gender*/
		while(True)
		{
			printf("\nPlease, Enter the Patient Gender: [1]Male\t[2]Female\n");
			printf("\t\tPatient Gender is: ");
			scanf("%d", &New -> Struct_u8Gender);
			if(((New -> Struct_u8Gender) == Male) || ((New -> Struct_u8Gender) == Female))
			{
				break;
			}
			else
			{
				printf("\nPlease, Choose between:\n[1]Male\t[2]Female\n");
			}
		}		
		
		/*Make the Node Point to NULL*/
		New -> Next = NULL;
		
		/*then we need to allcoate the new node as a last node in the Linked List*/
		Last = &Global_PatientNewPatient;
		
		/*Search for the last node and make it points to the new node*/
		while((Last -> Next) != NULL)
		{
			Last = (Last -> Next);
		}
		Last -> Next = New;	
	}
	/*add the LinkedList Length*/
	Global_u32ListLegnth++;
	
	/*this loop to check if you want to add another patient*/
	//while(Local_u8FlagAgain == 0)
	// do
	// {
		// /*ask the user add another patient or not*/
		// printf("\nDo you want to add another new patient ?\n[1]yes          [2]No\n");
		// scanf("%d",&Local_u8Again);
		
		// /*if yes want to add another pationt*/
		// if(Local_u8Again == Yes)
		// {
			// printf("-------------------\n");
			
			// /*recursion call the function one more time*/
			// Local_u8Iteration2 = 0;
			// Local_u8FlagID = 0;
			// Local_u8Again = 0;
			// Local_u8FlagAgain = 0;
			// u32 Local_u32IDCheck = 0;
			// Clinic_voidAddNewPatient();
			// break;
		// }
		
		// /*if no set the flag to terminate the loop*/
		// else if(Local_u8Again == No)
		// {
			// Local_u8FlagAgain = No;
		// }
		
		// /*if choose invalid choice*/
		// else
		// {
			// printf("You have to choose between [1] or [2]\n");
		// }
	// }while(Local_u8FlagAgain == 0);
	/*clear the flag*/
	Local_u8FlagAgain = 0;
	Local_u8Iteration2 = 0;
	/*call the admin functionalites*/
	//Clinic_u8AdminFunctionalities();
}

/*Description: This Function to Check the ID that Admin give to the Patient if it  exsist or not to not repeat any IDs 
 *Arguments	 : the ID of the Patient
 *Returns	 : it returns the Flag if ID Repeated True = 1 or Not False = 0
 */
u8 Clinic_u8IDChecking(u32 Local_u32ID)
{
	/*Local Variables*/
	u8 Local_u8Flag = False;
	
	/*if the list legnth greater than 0 that is mean ther are alot of IDs*/
	if(Global_u32ListLegnth > 0)
	{
		/*make the Last points to the Head of the linked List*/
		Last = &Global_PatientNewPatient;
		
		/*check first time the ID if it exist return the flag*/
		if((Last -> Struct_u32ID) == Local_u32ID)
		{
			Local_u8Flag = True;
			return Local_u8Flag;
		}
		
		/*if not exist make a loop to check on the whole Linked list*/
		else
		{
			while((Last -> Next) != NULL)
			{
				Last = (Last -> Next);
				if((Last -> Struct_u32ID) == Local_u32ID)
				{
					Local_u8Flag = True;
					return Local_u8Flag;
				}
			}
		}
	}
}


// Patient Clinic_PatientIDChecking(u32 Local_u32ID)
// {
	// Patient Copy_PatientChecked;
	
	// if(Global_u32ListLegnth > 0)
	// {
		// Last = &Global_PatientNewPatient;
		
		// if((Last -> Struct_u32ID) == Local_u32ID)
		// {
			// Copy_PatientChecked = *Last;
			// return Copy_PatientChecked;
		// }
		
		// else
		// {
			// while((Last -> Next) != NULL)
			// {
				// Last = (Last -> Next);
				// if((Last -> Struct_u32ID) == Local_u32ID)
				// {
					// Copy_PatientChecked = *Last;
					// return Copy_PatientChecked;
				// }
			// }
		// }
	// }
// }

/*Description: This Function to Check the ID and if it match give you athourity to edit the patient info
 *Arguments	 : The Patient ID
 *Returns	 : a Flag if the Patient ID is not exist 
 */
u8 Clinic_u8EditPatientRecord(u32 Copy_u32ID)
{
	/*Local Variables*/
	u8 Local_u8Flag = False, Local_u8Choice = 0, Local_IDFlagChecking = 0;
	
	/*This Function to clear the CMD*/
	system("cls");
	
	/*Calling the Function like Macro for the Clinic Introduction*/
	Clinic_Introduction();
	
	/*make the user know that you are in admin mode*/
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	
	/*if the list legnth greater than 0 that is mean ther are alot of IDs*/
	if(Global_u32ListLegnth > 0)
	{
		/*make the Last points to the Head of the linked List*/
		Last = &Global_PatientNewPatient;
		
		/*check first time the ID if it exist return the flag*/
		if((Last -> Struct_u32ID) == Copy_u32ID)
		{
			printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
		}
		
		/*if not exist make a loop to check on the whole Linked list*/
		else
		{
			while((Last -> Next) != NULL)
			{
				Last = (Last -> Next);
				if((Last -> Struct_u32ID) == Copy_u32ID)
				{
					printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
					break;
				}
			}
		}
		/*if the ID is not exist set the Local_IDFlagChecking and return its value*/
		if(Last -> Struct_u32ID != Copy_u32ID)
		{
			//printf("\nID is Not Exsist");
			Local_IDFlagChecking = 1;
			return Local_IDFlagChecking;
		}
		
		/*ptint the Patient with the found ID info ID, Name, Age and Gender*/
		printf("\nPatient ID is  : %d\n",  Last -> Struct_u32ID);
		printf("Patient Name is  : %s\n", Last -> Struct_u8Name);
		printf("Patient Age is   : %d\n", Last -> Struct_u8Age);
		
		/*this to check the Patient Gender and print it*/
		if(Last -> Struct_u8Gender == Male)
		{
			printf("Patient Gender is: Male\n\n");
		}
		else
		{
			printf("Patient Gender is: Female\n\n");
		}
		
		Lable_3:
		
		/*Choose what do you want to edit Name, Age or Gender*/
		printf("\nPlease, Enter what you need to edit [1]Name\t[2]Age\t[3]Gender");
		printf("\nYour Choice is: ");
		scanf("%d", &Local_u8Choice);
		
		/*Make a switch on this choice*/
		switch(Local_u8Choice)
		{
			/*First case you want to edit the patient name so it will print the old name and ask you to Enter the new one*/
			case 1:
			printf("\nThe Old Name is %s, please Enter the New Name: ", Last -> Struct_u8Name);
			scanf("%s", &(Last -> Struct_u8Name));
			break;
			
			/*Second Case you want to edit the patient Age so it will print the old age and ask you to enter the new one*/
			case 2:
			printf("The old Age is %d, please Enter the new Age: ", Last -> Struct_u8Age);
			scanf("%d", &Last -> Struct_u8Age);
			break;
			
			/*Third Case you want to edit the patient Gender so first it will check the Patient Gender and print it
			 *and ask you to Enter the new Gender between to choices [1]Male [2]Female
			 */
			case 3:
			/*Case patient is Male*/
			if(Last -> Struct_u8Gender == Male)
			{
				printf("\nThe Old Gender was Male, Please Enter the new gender");
				while(True)
				{
					printf("\nPlease, Enter the Patient Gender: [1]Male\t[2]Female\n");
					printf("\t\tPatient Gender is: ");
					scanf("%d", &Last -> Struct_u8Gender);
					if(((Last -> Struct_u8Gender) == Male) || ((Last -> Struct_u8Gender) == Female))
					{
						break;
					}
					else
					{
						printf("\nPlease, Choose between:\n[1]Male\t[2]Female\n");
					}
				}	
			}
			/*Case of Female*/
			else if(Last -> Struct_u8Gender == Female)
			{
				printf("The Old Gender was Female, Please Enter the new gender");
				while(True)
				{
					printf("\nPlease, Enter the Patient Gender: [1]Male\t[2]Female\n");
					printf("\t\tPatient Gender is: ");
					scanf("%d", &Last -> Struct_u8Gender);
					if(((Last -> Struct_u8Gender) == Male) || ((Last -> Struct_u8Gender) == Female))
					{
						break;
					}
					else
					{
						printf("\nPlease, Choose between:\n[1]Male\t[2]Female\n");
					}
				}
			}
			break;
			
			/*The default case if you have entered a wrong choice not a Name, Age or Gender so it take you back to choose again*/
			default:
			printf("\n\nyou have Entered wrong choice pleas, try again\n\n");
			
			/*Lable_3 is the start to ask you what do you want to edit Name, Age or Gender*/
			goto Lable_3;
			break;
		}
		
		/*After Editing it will ask you if you want to edit any other info for the same patient*/
		printf("\nDo you want to Edit any other ifo for the patient ID: %d\t[1]Yes\t[2]No\nPlease, Enter your Choice: ", Last -> Struct_u32ID);
		scanf("%d", &Local_u8Flag);
		
		/*if yes you want to edit other info for the same patient it will take you to Lable_3*/
		if(Local_u8Flag == Yes)
		{
			/*Lable_3 is the start to ask you what do you want to edit Name, Age or Gender*/
			goto Lable_3;
		}
	}
	/*then clear the Local Variables*/
	Local_u8Flag = 0;
	Local_u8Choice = 0;
}

/*Description: Reserve a slot for a doctor from 5 slots per day we have 7 days 
 *Arguments	 : ID 
 *Returns	 : Flag if the ID is not exist
 */
u8 Clinic_u8ReservePatientSlot(u32 Copy_u32ID)
{
	/*Local Variables*/
	u8 Local_u8Flag = False, Local_u8Choice = 0, Local_IDFlagChecking = 0;
	u8 Local_u8Day = 0, Local_u8Slot = 0, Local_u8SlotFlag = 0, Local_u8DayFlag = 0;
	
	/*This Function to clear the CMD*/
	system("cls");
	
	/*Calling the Function like Macro for the Clinic Introduction*/
	Clinic_Introduction();
	
	/*make the user know that you are in admin mode*/
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	
	/*if the list legnth greater than 0 that is mean ther are alot of IDs*/
	if(Global_u32ListLegnth > 0)
	{
		/*make the Last points to the Head of the linked List*/
		Last = &Global_PatientNewPatient;
		
		/*check first time the ID if it exist return the flag*/
		if((Last -> Struct_u32ID) == Copy_u32ID)
		{
			printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
		}
		
		/*if not exist make a loop to check on the whole Linked list*/
		else
		{
			while((Last -> Next) != NULL)
			{
				Last = (Last -> Next);
				if((Last -> Struct_u32ID) == Copy_u32ID)
				{
					printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
					break;
				}
			}
		}
		/*if the ID is not exist set the Local_IDFlagChecking and return its value*/
		if(Last -> Struct_u32ID != Copy_u32ID)
		{
			//printf("\nID is Not Exsist");
			Local_IDFlagChecking = 1;
			return Local_IDFlagChecking;
		}
		/*ptint the Patient with the found ID info ID, Name, Age and Gender*/
		printf("-------------------------");
		printf("\nPatient ID is  : %d\n",  Last -> Struct_u32ID);
		printf("Patient Name is  : %s\n", Last -> Struct_u8Name);
		printf("Patient Age is   : %d\n", Last -> Struct_u8Age);
		
		/*this to check the Patient Gender and print it*/
		if(Last -> Struct_u8Gender == Male)
		{
			printf("Patient Gender is: Male\n");
		}
		else
		{
			printf("Patient Gender is: Female\n");
		}
		
		/*To print the reserved Slot for this Patient*/
		printf("Patient Reserved slot: |%d| Day, |%d| Slot\n", Last -> Struct_u8Day, Last -> Struct_u8Slot);
		printf("-------------------------\n\n");
		
		Lable_7:
		/*Ask the user to choose the day between 7 days and assign the value in Local_u8Day Variable*/
		printf("Choose The Day: ");
		Days();
		printf("\nPlease, Enter the Day you want: ");
		scanf("%d", &Local_u8Day);
		
		//printf("\n\n\n*****Local_u8Day = %d*****\n\n\n", Local_u8Day);
		
		/*if the choosen day right between 1 and 7*/
		if(Local_u8Day < 8 && Local_u8Day > 0)
		{
			/*Minus 1 because of the Week array starts from zero*/
			Local_u8Day -= 1;
			
			//printf("\n\n\n*****Local_u8Day = %d*****\n\n\n", Local_u8Day);
			/*in case you choosed wrong or busy slot and you want to try again*/
			Lable_5:
			printf("\nChoose a slot: ");
			Slots();
			printf("\nPlease, Enter the Desired Slot: ");
			scanf("%d", &Local_u8Slot);
			
			/*switch on the slot as we have 5 slots and check if it busy or not*/
			switch(Local_u8Slot)
			{
				case 1:
				/*if the slot not equal one that is mean it is empty assign the values in it*/
				if(Week[Local_u8Day].Slot_1 != 1)
				{
					Week[Local_u8Day].Slot_1 = 1;
					Week[Local_u8Day].ID_1 = Copy_u32ID;
					(Last -> Struct_u8Day) = (Local_u8Day + 1);
					//printf("\n\n\n*****Local_u8Day = %d*****\n\n\n", Local_u8Day);
					(Last -> Struct_u8Slot) = 1;
				}
				/*esle tell the user that it is busy and ask him if he want to choose another or not*/
				else
				{
					printf("This Slot is Busy\n");
					printf("Do you want to try again for another slot [1]Yes\t[2]No");
					printf("\nYour Choice is: ");
					scanf("%d", &Local_u8SlotFlag);
					if(Local_u8SlotFlag == 1)
					{
						goto Lable_5;
					}
				}
				break;
				
				case 2:
				/*if the slot not equal one that is mean it is empty assign the values in it*/
				if(Week[Local_u8Day].Slot_2 != 1)
				{
					Week[Local_u8Day].Slot_2 = 1;
					Week[Local_u8Day].ID_2 = Copy_u32ID;
					Last -> Struct_u8Day = (Local_u8Day + 1);
					Last -> Struct_u8Slot = 2;
				}
				/*esle tell the user that it is busy and ask him if he want to choose another or not*/
				else
				{
					printf("This Slot is Busy\n");
					printf("Do you want to try again for another slot [1]Yes\t[2]No");
					printf("\nYour Choice is: ");
					scanf("%d", &Local_u8SlotFlag);
					if(Local_u8SlotFlag == 1)
					{
						goto Lable_5;
					}
				}
				break;
				
				case 3:
				/*if the slot not equal one that is mean it is empty assign the values in it*/
				if(Week[Local_u8Day].Slot_3 != 1)
				{
					Week[Local_u8Day].Slot_3 = 1;
					Week[Local_u8Day].ID_3 = Copy_u32ID;
					Last -> Struct_u8Day = (Local_u8Day + 1);
					Last -> Struct_u8Slot = 3;
				}
				/*esle tell the user that it is busy and ask him if he want to choose another or not*/
				else
				{
					printf("This Slot is Busy\n");
					printf("Do you want to try again for another slot [1]Yes\t[2]No");
					printf("\nYour Choice is: ");
					scanf("%d", &Local_u8SlotFlag);
					if(Local_u8SlotFlag == 1)
					{
						goto Lable_5;
					}
				}
				break;
				
				case 4:
				/*if the slot not equal one that is mean it is empty assign the values in it*/
				if(Week[Local_u8Day].Slot_4 != 1)
				{
					Week[Local_u8Day].Slot_4 = 1;
					Week[Local_u8Day].ID_4 = Copy_u32ID;
					Last -> Struct_u8Day = (Local_u8Day + 1);
					Last -> Struct_u8Slot = 4;
				}
				/*esle tell the user that it is busy and ask him if he want to choose another or not*/
				else
				{
					printf("This Slot is Busy\n");
					printf("Do you want to try again for another slot [1]Yes\t[2]No");
					printf("\nYour Choice is: ");
					scanf("%d", &Local_u8SlotFlag);
					if(Local_u8SlotFlag == 1)
					{
						goto Lable_5;
					}
				}
				break;
				
				case 5:
				/*if the slot not equal one that is mean it is empty assign the values in it*/
				if(Week[Local_u8Day].Slot_5 != 1)
				{
					Week[Local_u8Day].Slot_5 = 1;
					Week[Local_u8Day].ID_5 = Copy_u32ID;
					Last -> Struct_u8Day = (Local_u8Day + 1);
					Last -> Struct_u8Slot = 5;
				}
				/*esle tell the user that it is busy and ask him if he want to choose another or not*/
				else
				{
					printf("This Slot is Busy\n");
					printf("Do you want to try again for another slot [1]Yes\t[2]No");
					printf("\nYour Choice is: ");
					scanf("%d", &Local_u8SlotFlag);
					if(Local_u8SlotFlag == 1)
					{
						goto Lable_5;
					}
				}
				break;
				
				default:
				/*Default means you have choosen un-valied number for a slot and ask the user if he want to try another slot or not*/
				printf("you have choosed invalied choice\n");
				printf("Do you want to try again for another slot [1]Yes\t[2]No");
				printf("\nYour Choice is: ");
				scanf("%d", &Local_u8SlotFlag);
				if(Local_u8SlotFlag == 1)
				{
					goto Lable_5;
				}
				break;
			}
		}
		/*this is the user entered un-valied number for a day*/
		else
		{
			printf("\nyou choosed unvalied Day");
			printf("Do you want to try another day [1]Yes\t[2]No");
			scanf("%d", Local_u8DayFlag);
			if(Local_u8DayFlag == 1)
			{
				goto Lable_7;
			}
		}
	}	
}

/*Description: This Function cancel a reservation for a patient 
 *Arguments	 : The Patient ID
 *Returns	 : Flag if the Patient ID is not exist 
 */
u8 Clinic_u8CancelReservation(u32 Copy_u32ID)
{
	u8 Local_IDFlagChecking = 0, Local_u8CancelFlag = 0;
	
	/*This Function to clear the CMD*/
	system("cls");
	
	/*Calling the Function like Macro for the Clinic Introduction*/
	Clinic_Introduction();
	
	/*make the user know that you are in admin mode*/
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	
	/*if the list legnth greater than 0 that is mean ther are alot of IDs*/
	if(Global_u32ListLegnth > 0)
	{
		/*make the Last points to the Head of the linked List*/
		Last = &Global_PatientNewPatient;
		
		/*check first time the ID if it exist return the flag*/
		if((Last -> Struct_u32ID) == Copy_u32ID)
		{
			printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
		}
		
		/*if not exist make a loop to check on the whole Linked list*/
		else
		{
			while((Last -> Next) != NULL)
			{
				Last = (Last -> Next);
				if((Last -> Struct_u32ID) == Copy_u32ID)
				{
					printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
					break;
				}
			}
		}
		/*if the ID is not exist set the Local_IDFlagChecking and return its value*/
		if(Last -> Struct_u32ID != Copy_u32ID)
		{
			//printf("\nID is Not Exsist");
			Local_IDFlagChecking = 1;
			return Local_IDFlagChecking;
		}
		/*ptint the Patient with the found ID info ID, Name, Age and Gender*/
		printf("-------------------------");
		printf("\nPatient ID is  : %d\n",  Last -> Struct_u32ID);
		printf("Patient Name is  : %s\n", Last -> Struct_u8Name);
		printf("Patient Age is   : %d\n", Last -> Struct_u8Age);
		
		/*this to check the Patient Gender and print it*/
		if(Last -> Struct_u8Gender == Male)
		{
			printf("Patient Gender is: Male\n");
		}
		else
		{
			printf("Patient Gender is: Female\n");
		}
		
		/*To print the reserved Slot for this Patient*/
		printf("Patient Reserved slot: |%d| Day, |%d| Slot\n", Last -> Struct_u8Day, Last -> Struct_u8Slot);
		printf("-------------------------\n\n");
		
		/*Ask the User to Make Sure that he want to cancel Reservation*/
		printf("Do you want to cancel this reservation [1]Yes\t[2]No\nPlease, Enter your Choice: ");
		scanf("%d", &Local_u8CancelFlag);
		
		/*If yes Clear the Week Array for this ID and Clear the Reservation in the Node*/
		if(Local_u8CancelFlag == 1)
		{
			/*Switch for the Slots and the equal to be Cleared*/
			switch((Last -> Struct_u8Slot))
			{
				case 1:
				Week[((Last -> Struct_u8Day) - 1)].ID_1 = 0;
				Week[((Last -> Struct_u8Day) - 1)].Slot_1 = 0;
				break;
				
				case 2:
				Week[((Last -> Struct_u8Day) - 1)].ID_2 = 0;
				Week[((Last -> Struct_u8Day) - 1)].Slot_2 = 0;
				break;
				
				case 3:
				Week[((Last -> Struct_u8Day) - 1)].ID_3 = 0;
				Week[((Last -> Struct_u8Day) - 1)].Slot_3 = 0;
				break;
				
				case 4:
				Week[((Last -> Struct_u8Day) - 1)].ID_4 = 0;
				Week[((Last -> Struct_u8Day) - 1)].Slot_4 = 0;
				break;
				
				case 5:
				Week[((Last -> Struct_u8Day) - 1)].ID_5 = 0;
				Week[((Last -> Struct_u8Day) - 1)].Slot_5 = 0;
				break;
			}
			
			/*Clear the Data in the Node*/
			Last -> Struct_u8Day = 0;
			Last -> Struct_u8Slot = 0;
		}
	}	
}

/*Description: This Function to Print the Linked List with all details for all patient 
 *Arguments	 : No Argument
 *Returns	 : Flag if the List is Empty
 */
u8 Clinic_voidPrintList(void)
{	
	/*Local Variables*/
	u8 Local_u8PrintFlag = 0;
	
	printf("\n-------------------------\n");
	
	/*if the List has any data if yes it will start to print*/
	if(Global_u32ListLegnth > 0)
	{	
		Last = &Global_PatientNewPatient;
		
		/*Print The Head of the List*/
		printf("Patient ID is    : %d\n", Last -> Struct_u32ID);
		printf("Patient Name is  : %s\n",  Last -> Struct_u8Name);
		printf("Patient Age is   : %d\n", Last -> Struct_u8Age);
		if(Last -> Struct_u8Gender == Male)
		{
			printf("Patient Gender is: Male\n\n");
		}
		else
		{
			printf("Patient Gender is: Female\n\n");
		}
		if(Last -> Struct_u8Day > 0 && Last -> Struct_u8Slot > 0)
		{
			printf("Patient Reserved Day |%d| Slot |%d|\n\n\n", (Last -> Struct_u8Day), (Last -> Struct_u8Slot));
		}
		
		/*Print the rest of the List*/
		while((Last -> Next) != NULL)
		{
			Last = (Last -> Next);
		
			printf("Patient ID is    : %d\n", Last -> Struct_u32ID);
			printf("Patient Name is  : %s\n",  Last -> Struct_u8Name);
			printf("Patient Age is   : %d\n", Last -> Struct_u8Age);
			if(Last -> Struct_u8Gender == Male)
			{
				printf("Patient Gender is: Male\n\n");
			}
			else
			{
				printf("Patient Gender is: Female\n\n");
			}
			if(Last -> Struct_u8Day > 0 && Last -> Struct_u8Slot > 0)
			{
				printf("Patient Reserved Day |%d| Slot |%d|\n\n\n", (Last -> Struct_u8Day), (Last -> Struct_u8Slot));
			}
		}
		printf("-------------------------\n");
	}
	
	/*if the List Length = 0 that is mean the list is empty then set the flag and return it*/
	else
	{
		Local_u8PrintFlag = 1;
		return Local_u8PrintFlag;
	}
}

/*Description: This Function for User Mode to print the Patient info  
 *Arguments	 : The Oatient ID
 *Returns	 : Flag if the Patient ID is not exist 
 */
u8 Clinic_u8ViewPatientRecord(u32 Copy_u32ID)
{
	u8 Local_IDFlagChecking = 0;
	/*This Function to clear the CMD*/
	system("cls");
	
	/*Calling the Function like Macro for the Clinic Introduction*/
	Clinic_Introduction();
	
	/*make the user know that you are in admin mode*/
	printf("\n\t\t\t\t\t\t\t\tYou are on User Mode\n");
	
	/*if the list legnth greater than 0 that is mean ther are alot of IDs*/
	if(Global_u32ListLegnth > 0)
	{
		/*make the Last points to the Head of the linked List*/
		Last = &Global_PatientNewPatient;
		
		/*check first time the ID if it exist return the flag*/
		if((Last -> Struct_u32ID) == Copy_u32ID)
		{
			printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
		}
		
		/*if not exist make a loop to check on the whole Linked list*/
		else
		{
			while((Last -> Next) != NULL)
			{
				Last = (Last -> Next);
				if((Last -> Struct_u32ID) == Copy_u32ID)
				{
					printf("\nThe ID %d is Found\n\n", Last -> Struct_u32ID);
					break;
				}
			}
		}
		/*if the ID is not exist set the Local_IDFlagChecking and return its value*/
		if(Last -> Struct_u32ID != Copy_u32ID)
		{
			//printf("\nID is Not Exsist");
			Local_IDFlagChecking = 1;
			return Local_IDFlagChecking;
		}
		/*ptint the Patient with the found ID info ID, Name, Age and Gender*/
		printf("-------------------------");
		printf("\nPatient ID is  : %d\n",  Last -> Struct_u32ID);
		printf("Patient Name is  : %s\n", Last -> Struct_u8Name);
		printf("Patient Age is   : %d\n", Last -> Struct_u8Age);
		
		/*this to check the Patient Gender and print it*/
		if(Last -> Struct_u8Gender == Male)
		{
			printf("Patient Gender is: Male\n");
		}
		else
		{
			printf("Patient Gender is: Female\n");
		}
		
		/*To print the reserved Slot for this Patient*/
		printf("Patient Reserved slot: |%d| Day, |%d| Slot\n", Last -> Struct_u8Day, Last -> Struct_u8Slot);
		printf("-------------------------\n\n");
	}	
}

/*Description: This Function to Print The Slots for one Day and shows which empty and wich busy
 *Arguments	 : No Argument
 *Returns	 : Non
 */
void Clinic_voidViewReservation(void)
{
	u8 Local_u8Day = 0, Local_u8Flag = 0;
	/*This Function to clear the CMD*/
	system("cls");
	
	/*Calling the Function like Macro for the Clinic Introduction*/
	Clinic_Introduction();
	
	/*make the user know that you are in admin mode*/
	printf("\n\t\t\t\t\t\t\t\tYou are on User Mode\n");
	
	/*if the list legnth greater than 0 that is mean ther are alot of IDs*/
	if(Global_u32ListLegnth > 0)
	{
		Lable_11:
		
		/*Ask the User for the Day*/
		printf("Please, Enter the day in this week: ");
		Days();
		printf("\n-------------------------\n");
		printf("\nPlease, Enter the Day: ");
		scanf("%d", &Local_u8Day);
		
		/*If the Day is True*/
		if(Local_u8Day < 8 && Local_u8Day > 0)
		{
			/*This Function to clear the CMD*/
			system("cls");
			
			/*Calling the Function like Macro for the Clinic Introduction*/
			Clinic_Introduction();
			
			/*make the user know that you are in admin mode*/
			printf("\n\t\t\t\t\t\t\t\tYou are on User Mode\n");
			/*Minus it by one because the Array starts from zero (Week Array)*/
			Local_u8Day -= 1;
			
			Slots();
			printf("\nSlot Case: \n");
			printf("~~~~~~~~~~~~~~~~~~~~~\n");
			
			/*This to show witch Slot is busy and witch is not*/
			if(Week[Local_u8Day].Slot_1 == 1)
			{
				printf("|1|Busy by the User ID: %d\n", Week[Local_u8Day].ID_1);
			}
			else
			{
				printf("|1|Empty\n");
			}
			
			if(Week[Local_u8Day].Slot_2 == 1)
			{
				printf("|2|Busy by the User ID: %d\n", Week[Local_u8Day].ID_2);
			}
			else
			{
				printf("|2|Empty\n");
			}
			
			if(Week[Local_u8Day].Slot_3 == 1)
			{
				printf("|3|Busy by the User ID: %d\n", Week[Local_u8Day].ID_3);
			}
			else
			{
				printf("|3|Empty\n");
			}
			
			if(Week[Local_u8Day].Slot_4 == 1)
			{
				printf("|4|Busy by the User ID: %d\n", Week[Local_u8Day].ID_4);
			}
			else
			{
				printf("|4|Empty\n");
			}
			
			if(Week[Local_u8Day].Slot_5 == 1)
			{
				printf("|5|Busy by the User ID: %d\n", Week[Local_u8Day].ID_5);
			}
			else
			{
				printf("|5|Empty\n");
			}
		}
		
		/*This if the User Entered un-valied Day*/
		else
		{
			printf("You have Entered Wrong Day");
			printf("Do you want to re-enter another day?[1]Yes\t[2]No");
			scanf("%d", &Local_u8Flag);
			if(Local_u8Flag == 1)
			{
				goto Lable_11;
			}
		}
	}
}
