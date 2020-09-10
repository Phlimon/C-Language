///////////////////////////////////////////////////*Linked List*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*Liberaries*/
#include<stdlib.h>
#include<stdio.h>

#define True  1
#define False 0

#define Male   1
#define Female 2

#define Admin_Mode      1
#define User_Mode       2
#define Exit_The_System 3

#define Clinic_Introduction() printf("\n\t\t\t\t\t\t\t**********Welcome to Our Clinic**********");\
							  printf("\n\t\t\t\t\t\t\t*****************************************\n\n");

#define ADMIN_FEATURES() printf("\n[1]Add New Patient Record\n");\
						 printf("[2]Edit Patient Record\n");\
						 printf("[3]Reserve a Slot with the Doctor\n");\
						 printf("[4]Cancel Reservation\n");\
						 printf("Exit Admin Mode Press any number else");
						
#define USER_FEATURES() printf("\n[1]View Patient Records\n");\
						printf("[2]View Today's Reservation\n\n");
							
/*STD Types*/
typedef struct Patients Patient;
typedef unsigned short int u32;
typedef unsigned char u8;
typedef enum Admin_Featuress Admin_Features;
typedef enum User_Featuress User_Features;

/*Global Variables*/
Patient New_Patient;
Patient *New;
Patient *Last;
u8 Mode;
u8 Flag_2 = 0;
u32 ListLength = 0;

/*Struct for what i need in linked List (Data, Link)*/
struct Patients
{
	u8 Name[100];
	u32 ID;
	u8 Age;
	u8 Gender;
	Patient *Next;
};

/*Enum for Admin Features*/
enum Admin_Featuress
{
	Add_New_Patient_Record = 1,
	Edit_Patient_Record,
	Reserve_a_Slot_With_The_DoctOR,
	Cancel_Reservation,
	Exit_Admin_Mode
};

/*Enum For User Features*/
enum User_Featuress
{
	View_Patient_Record = 1,
	View_Today_Resrvations
};

/*Functions ProtoTypes*/
void Clinic_voidModes();
void Clinic_voidAddNewPatient();
void PrintLinkedList();
u8 Clinic_u8IDChecking(u32 ID);
u8 Clinic_u8AdminModePassword();
void Clinic_VoidAdminFunctions();

/*Main Function*/
void main(void)
{
	/*this to clear the CMD*/
	system("cls");
	
	/*Flag_1 for Exit the while Loop*/
	u8 static Flag_1 = 0;
	
	/*Local Variables*/
	u8 i, Pass;
	
	/*my Variables*/
	
	u32 static Input;
	
	u8 ExitFlag = 0;
	
	/*LOOP*/
	while(ExitFlag == 0)
	{
		Clinic_voidModes();
		/*Choices avaliable*/
	
		switch(Mode)
		{
			case Admin_Mode:
				system("cls");
				Clinic_Introduction();
				
				printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
				printf("\n\nPlease, Enter Your Password: ");
				
				Pass = Clinic_u8AdminModePassword();
				
				if(Pass == True)
				{
					Clinic_VoidAdminFunctions();
				}
				else
				{
					ExitFlag = 1;
				}
			break;
			
			case User_Mode:
			PrintLinkedList();
			break;
			
			case Exit_The_System:
				printf("\n\t\t\t\t\t\t\t\t  ******Thank you******");
				printf("\n\t\t\t\t\t\t\t ****************************************");
				ExitFlag = 1;
			break;
			
			default:
				Flag_2++;
				system("cls");
			break;
		}
	}
}

void Clinic_voidModes()
{	
	system("cls");
	
	while(Flag_2 != 0)
	{
		system("cls");
		Clinic_Introduction();
		printf("Invailed Choice Please, Try again with right Choice");
		printf("\nPlease, Enter the Number of the next Features: \n");
		printf("\n[1]Admin Mode\n[2]User Mode\n[3]Exit the System\n");
		printf("\nYour Choice is: ");
		scanf("%d", &Mode);
		break;
	}
	while(Flag_2 == 0)
	{
		system("cls");
		Clinic_Introduction();
		printf("\nPlease, Enter the Number of the next Features: \n");
		printf("\n[1]Admin Mode\n[2]User Mode\n[3]Exit the System\n");
		printf("\nYour Choice is: ");
		scanf("%d", &Mode);
		break;
	}
}

u8 Clinic_u8AdminModePassword()
{
	u8 static i, Password;
	u32 Pass;
	
	for(i = 0; i < 3; i++)
	{
		if(Pass == 1234)
		{
			Password = True;
			break;
		}
		
		scanf("%d", &Pass);
		
		if(Pass == 1234)
		{
			Password = True;
			break;
		}
		else if(i == 2)
		{
			printf("\n\n\t\t\t\t\t\t\tYou have Entered the Password 3 Times Wrong");
			printf("\n\t\t\t\t\t\t\t\t\t****BYE BYE****");
			Password = False;
			break;
		}
		else
		{
			printf("\n****Invalid Password****\n\nPlease, Re-Enter the right Password: ");
		}
		
	}
	return Password;
}

void Clinic_VoidAdminFunctions()
{
	u8 Admin_Feature; 
	
	system("cls");
	
	Clinic_Introduction();
	
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	printf("\nPlease, Choose one of this Features:- \n");
	
	ADMIN_FEATURES();
	printf("\n\nPlease, Enter the number of the Feature: ");
	scanf("%d", &Admin_Feature);
	
	switch(Admin_Feature)
	{
		case Add_New_Patient_Record:
			Clinic_voidAddNewPatient();
			break;
		break;
		
		case Edit_Patient_Record:
		
		break;
		
		case Reserve_a_Slot_With_The_DoctOR:
		
		break;
		
		case Cancel_Reservation:
		
		break;
		
		default:
			Clinic_voidModes();
		/*Empty to break the switch case and then break the switch in the main function the looping in while loop*/
		break;
	}
}

void Clinic_voidAddNewPatient()
{ 
	u32 IDFC; //ID For Checking
	u8 Flag_4, /*Flag_3 = 0,*/ Flag_6 = 0, Again, i;
	//Flag_3 For Choosing the Gender
	//Flag_4 For the ID
	//Flag_6 For Add another Patient or No
	
	system("cls");
	Clinic_Introduction();
	printf("\n\t\t\t\t\t\t\t\tYou are on Admin Mode");
	
	/*First Node to Creat*/
	/*that is mean Linked List Length = 0*/
	if(ListLength == 0)
	{		
		printf("\nPlease, Enter Your ID: ");
		scanf("%d", &New_Patient.ID);
		
		printf("Please, Enter Your Name: ");
		scanf("%s", &New_Patient.Name);
		
		printf("Please, Enter the your Age: ");
		scanf("%d", &New_Patient.Age);
		
		while(1)
		{
			printf("Please, Enter Your Gender: [1]Male\t\t[2]Female\n");
			printf("Gender is: ");
			scanf("%d", &New_Patient.Gender);
			if(((New_Patient.Gender) == Male) || ((New_Patient.Gender) == Female))
			{
				break;
			}
			else
			{
				printf("\nYou to Choose between : [1]Male\t\t[2]Female\n");
			}
		}
		
		ListLength++;
	}
	
	else
	{	
		//Flag_3 = 0;
		/*when tha last point to null and you want to add node you will need the (Node) Size*/
		/*so the next is to callculate the New Node Size*/
		New = (Patient*)malloc(sizeof(Patient));
		
		/*After we have a new node we need to assign the values in it*/
		printf("\nPlease, Enter Your ID: ");
		
		for(i = 0; i < 3; i++)
		{
			scanf("%d", &IDFC);
			
			Flag_4 = Clinic_u8IDChecking(IDFC);
			
			if(Flag_4 == True)
			{
				printf("ID Is NOT Repeated\n");
				(New -> ID) = IDFC;
				break;
			}
			
			if(Flag_4 == False)
			{
				printf("ID Is Repeated Please try another ID: ");
			}
		}
		
		printf("Please, Enter Your Name: ");
		scanf("%s", &New -> Name);
		
		printf("Please, Enter the your Age: ");
		scanf("%d", &New -> Age);
		
		while(1)
		{
			printf("Please, Enter Your Gender: [1]Male\t\t[2]Female\n");
			printf("Gender is: ");
			scanf("%d", &(New -> Gender));
			if(((New -> Gender) == Male) || ((New -> Gender) == Female))
			{
				break;
			}
			else
			{
				printf("\nYou to Choose between : [1]Male\t\t[2]Female\n");
			}
		}
		
		/*then we make the New poit Next and ewual NULL so you can add a new Node*/
		New -> Next = NULL;
	
		/*then you need no make if a new node added to be added in the last*/
		Last = &New_Patient;
		
		/*Search for the Last Node*/
		while((Last -> Next) != NULL)
		{
			Last = (Last -> Next);
		}
		Last -> Next = New;
		
		/*then you need to increase the legnth*/
		ListLength++;
		//Flag_3 = 0;
	}
	
	while(Flag_6 != 1)
	{
		printf("\nDo you want to add another new patient ?\n[1]yes          [2]No\n");
		scanf("%d",&Again);
		
		if(Again == 1)
		{
		 printf("-------------------\n");		
		 Clinic_voidAddNewPatient();
		 break;
		}
		else if(Again == 2)
		{
			Flag_6 = 1;
		}	
		else
		{
			printf("{You must choose [1] OR [2]}\n"); 
		}	
	}	
	Flag_6 = 0;
	Clinic_VoidAdminFunctions();
}

void PrintLinkedList()
{
	printf("\n-------------------------\n");
	
	if(ListLength > 0)
	{
		Last = &New_Patient;
		u32 i = 1;
		
		/*Print The Head of the List*/
		printf("User Name %d = %s\n", i, Last -> Name);
		printf("User Number %d = %d\n", i, Last -> ID);
		printf("User Number %d = %d\n\n", i, Last -> Age);
		
		/*Print the rest of the List*/
		while((Last -> Next) != NULL)
		{
			Last = (Last -> Next);
		
			printf("User Name %d = %s\n", (i + 1), (Last -> Name));
			printf("Node Number %d = %d\n", (i + 1), (Last -> ID));
			printf("Node Number %d = %d\n\n", (i + 1), (Last -> Age));
			i++;
		}
		printf("-------------------------\n");
	}
}

u8 Clinic_u8IDChecking(u32 ID)
{	
	u8 Flag_5 = True;

	if(ListLength > 0)
	{
		Last = &New_Patient;
		
		if((Last -> ID) == ID)
		{
			Flag_5 = False;
			
			return Flag_5;
		}
		else
		{
			/*Print the rest of the List*/
			while((Last -> Next) != NULL)
			{
				Last = (Last -> Next);
			
				if((Last -> ID) == ID)
				{
					Flag_5 = False;
					break;
				}
			}
		}
	}
	return Flag_5;
}