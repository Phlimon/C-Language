#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "STD.h"

/*Global Variables*/
extern u8 Global_u8FlagModes;
u32 Global_u32ListLegnth = 0;
Patient Global_PatientNewPatient;
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
 *Returns	 : Non
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


void Clinic_voidPrintList(void)
{
	u32 Local_u32Iteration = 1;
	
	printf("\n-------------------------\n");

	if(Global_u32ListLegnth > 0)
	{	
		Last = &Global_PatientNewPatient;
		
		/*Print The Head of the List*/
		printf("User Name %d = %s\n", Local_u32Iteration, Last -> Struct_u8Name);
		printf("User Number %d = %d\n", Local_u32Iteration, Last -> Struct_u32ID);
		printf("User Number %d = %d\n\n", Local_u32Iteration, Last -> Struct_u8Age);
		
		/*Print the rest of the List*/
		while((Last -> Next) != NULL)
		{
			Last = (Last -> Next);
		
			printf("User Name %d = %s\n", (Local_u32Iteration + 1), (Last -> Struct_u8Name));
			printf("Node Number %d = %d\n", (Local_u32Iteration + 1), (Last -> Struct_u32ID));
			printf("Node Number %d = %d\n\n", (Local_u32Iteration + 1), (Last -> Struct_u8Age));
			Local_u32Iteration++;
		}
		printf("-------------------------\n");
	}
}