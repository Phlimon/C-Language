/////////////////////////////////////////////////Clinic System\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*Liberaries*/
#include<stdio.h>
#include<stdlib.h>

/*Defines*/
#define Admin_Mode 1
#define User_Mode  2
#define Exit_The_System 3

#define Male 1
#define Female 2

#define Repeated 0
#define UnRepeated 1

#define ADMIN_FEATURES() printf("\n[1]Add New Patient Record\n");\
						 printf("[2]Edit Patient Record\n");\
						 printf("[3]Reserve a Slot with the Doctor\n");\
						 printf("[4]Cancel Reservation\n");\
						 printf("[5]Exit Admin Mode");
						 
#define USER_FEATURES() printf("\n[1]View Patient Records\n");\
						printf("[2]View Today's Reservation\n\n");
				   
/*STD Types*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef enum Admin_Featuress Admin_Features;
typedef enum User_Featuress User_Features;
typedef struct Patients Patient;

/*Global Variables*/
enum Admin_Featuress
{
	Add_New_Patient_Record = 1,
	Edit_Patient_Record,
	Reserve_a_Slot_With_The_DoctOR,
	Cancel_Reservation,
	Exit_Admin_Mode
};

enum User_Featuress
{
	View_Patient_Record = 1,
	View_Today_Resrvations
};

struct Patients
{
	u8 Name[100];
	u8 Age;
	u8 Gender;
	u32 ID;
	Patient *Next;
};

Patient New_Patient;
Patient *New;
Patient *Last;
//Patient *Head;
u32 ListLength = 0;
u32 Password;
u32 CHECK_ID;

/*Functions Prototypes*/
void AddPatient();
int PASSWORD();
void ADMIN_VoidFunctions();
u8 ID_u8Checking();
u8 Modes();

/*Main Function*/
void main(void)
{
	system("cls");
	
	u8 Flag_1 = 0;
	u8 Flag_5 = 0;
	
	while(Flag_5 != 1)
	{
		Flag_5 = 0;
		u32 Mode, i = 0, Password;
		
		Mode = Modes();
		
		switch(Mode)
		{
			case Admin_Mode:
			system("cls");
			printf("\n\t\t\t\t\t\t\t**********Welcome to Our Clinic**********");
			printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
			printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
			printf("\n\nPlease, Enter Your Password: ");
			
			Flag_1 = PASSWORD();	
			
			if(Flag_1 == 1)
			{
				break;
			}
			else if(Flag_1 == 0)
			{
				ADMIN_VoidFunctions();			
			}	
			break;
			
			case User_Mode:
			USER_FEATURES();
			break;
			
			case Exit_The_System:
			Flag_5 = 1;
			break;
			
			default:
			printf("\n\t\t\t\tInvalide Choice Please, try again\n");
			break;
		}
	}		
}


u8 Modes()
{
	u8 Mode;
	
	system("cls");
	printf("\n\t\t\t\t\t\t\t**********Welcome to Our Clinic**********");
	printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
	printf("Please, Choose your Mode by Entering the Number of the Mode: \n");
	printf("\n[1]Admin Mode\n[2]User Mode\n[3]Exit the System\n");
	printf("\nYour Choice is: ");
	scanf("%d", &Mode);
	
	return Mode;
}

int PASSWORD()
{
	u32 i, Flag_4;
	
	for(i = 0; i < 3; i++)
	{
		if(Password == 1234)
		{
			Flag_4 = 0;
			break;
		}
		
		scanf("%d", &Password);
		
		if(Password == 1234)
		{
			Flag_4 = 0;
			break;
		}
		
		else if(i == 2)
		{
			printf("\n\n\t\t\t\t\t\t\tyou have Entered the Password 3 times wrong\n\t\t\t\t\t\t\t\t\t****Bye Bye****");
			Flag_4 = 1;
		}
		
		else
			{
				printf("\n****Invalid Password****\n\nPlease, Enter Your Password: ");
			}
	}
	return Flag_4;
}

void AddPatient()
{
	u8 Flag_2 = 0, Flag_3 = 0, Flag_4 = 0, Again = 0, ID, Iteration;
	
	system("cls");
	printf("\n\t\t\t\t\t\t\t**********Welcome to Our Clinic**********");
	printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");

	if(ListLength == 0)
	{
		printf("\nPlease, Enter the Patient Name: ");
		scanf("%s", &New_Patient.Name);
		
		printf("please, Enter The Patient Age: ");
		scanf("%d", &New_Patient.Age);
		while(Flag_2 != 1)
		{
			printf("please, Enter The Patient Gender\n\n[1]Male\n[2]Female\n\nGender is: ");
			scanf("%d", &New_Patient.Gender);
			if(New_Patient.Gender == Male || New_Patient.Gender == Female)
			{
				Flag_2 = 1;
			}
			else
			{
				printf("\nPlease, Enter Number [1]Male or [2]Female Thanks");
			}
		}
		
		printf("please, Enter The Patient ID: ");
		scanf("%d", &New_Patient.ID);
		
		ListLength++;
	}
	
	else
	{
		New = (Patient*)malloc(sizeof(Patient));
		
		printf("\nPlease, Enter the Patient Name: ");
		scanf("%s", &New -> Name);
		
		printf("please, Enter The Patient Age: ");
		scanf("%d", &New -> Age);
		while(Flag_4 != 1)
		{
			printf("please, Enter The Patient Gender\n\n[1]Male\n[2]Female\n\nGender is: ");
			scanf("%d", &New -> Gender);
			if((New -> Gender = Male) || (New -> Gender = Female))
			{
				Flag_4 = 1;
			}
			else
			{
				printf("\nPlease, Enter Number [1]Male or [2]Female Thanks");
			}
		}
		
		printf("please, Enter The Patient ID: ");
		//scanf("%d", &CHECK_ID);
		ID = ID_u8Checking();
		
		if(ID == UnRepeated)
		{
			(New -> ID) = ID;
			//scanf("%d", &New -> ID);
		}
		else
		{
			// for(Iteration = 0; Iteration < 3; Iteration++)
			// {
				// printf("The ID you Entered is Repeated\n\tPlease, Try again");
				
				// if(Iteration == 2)
				// {
					// printf("you have Entered the ID repeated for 3 times\n\tPlease try again later\n\t\tThank You");
					 ADMIN_VoidFunctions();
				// }
			// }
		}
		//scanf("%d", &New -> ID);
		
		New -> Next = NULL;
		
		Last = &New_Patient;
		
		while((Last -> Next) != NULL)
		{
			Last = (Last -> Next);
		}
		Last -> Next = New;
		
		ListLength++;
	}
	
	do
	{
		printf("\nDo you want to add another new patient ?\n[1]yes          [2]No\n");
		scanf("%d",&Again);
		
		if(Again == 1)
		{
		 printf("-------------------\n");		
		 AddPatient();
	
		}
		else if(Again == 2)
		{
			Flag_3 = 1;
		}	
		else
		{
			printf("{You must choose [1] OR [2]}\n"); 
		}	
	}	
	while(Flag_3 == 0);
}

void ADMIN_VoidFunctions()
{
	u32 AD_Feature;
	
	system("cls");
	printf("\n\t\t\t\t\t\t\t**********Welcome to Our Clinic**********");
	printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	printf("\nPlease, Choose one of this Features:- \n\n");

	ADMIN_FEATURES();
	printf("\n\nPlease, Enter the number of the Feature: ");
	scanf("%d", &AD_Feature);
	
	switch(AD_Feature)
	{
		case Add_New_Patient_Record:
		AddPatient();
		break;
		
		case Edit_Patient_Record:
		break;
		
		case Reserve_a_Slot_With_The_DoctOR:
		break;
		
		case Cancel_Reservation:
		break;
		
		case Exit_Admin_Mode:
		Modes();
		break;
		
		default:
		break;
	}
	ADMIN_VoidFunctions();
}


// u8 ID_u8Checking(u32 IDCheck)
// {

	// Head = &New_Patient;
	// while((Head -> Next) != NULL)
	//while((New -> ))	
		// {
			// printf("%ssssssssssssssssssssssssssssssssssssssd", Head ->Next);
			// if((Head -> ID) == IDCheck)
			// {
				// return Repeated;
			// }
			// else
			// {
				// Head = (Head -> Next);
			// }
		// }
	// return UnRepeated;
// }


// u8 ID_u8Checking(u32 IDCheck)
// {
	// Last = &New_Patient;
	
	// u32 i = 1;
	
	// if(IDCheck == (Last -> ID))
	// {
		// return Repeated;
	// }
	// else
	// {
		// while((Last -> Next) != NULL)
		// {
			// Last = (Last -> Next);
			
			// if(IDCheck == Last -> ID)
			// {
				// return Repeated;
			// }
		// }
	// }
	// return UnRepeated;
// }

u8 ID_u8Checking()
{
	u32 i, Flag_6;
	
	for(i = 0; i < 3; i++)
	{
		if(CHECK_ID == (Last -> ID))
		{
			Flag_6 = Repeated;
			break;
		}
		
		scanf("%d", &CHECK_ID);
		
		if(CHECK_ID == (Last -> ID))
		{
			Flag_6 = Repeated;
			break;
		}
		
		else if(i == 2)
		{
			printf("\n\n\t\t\t\t\t\t\tyou have Entered the ID 3 times Repeated\n\t\t\t\t\t\t\t\t\t****Bye Bye****");
			Flag_6 = 1;
		}
		
		else
			{
				printf("\n****Repated ID****\n\nPlease, Try another ID: ");
			}
	}
	return Flag_6;
}
