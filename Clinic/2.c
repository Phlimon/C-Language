/////////////////////////////////////////////////Clinic System\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*Liberaries*/
#include<stdio.h>
#include<stdlib.h>

/*Defines*/
#define Admin_Mode      1
#define User_Mode       2
#define Exit_The_System 3

#define Male   1
#define Female 2

#define Repeated   0
#define UnRepeated 1

#define False 1
#define True  0

#define ADMIN_FEATURES() printf("\n[1]Add New Patient Record\n");\
						 printf("[2]Edit Patient Record\n");\
						 printf("[3]Reserve a Slot with the Doctor\n");\
						 printf("[4]Cancel Reservation\n");\
						 printf("Exit Admin Mode Press any number else");
						 
#define USER_FEATURES() printf("\n[1]View Patient Records\n");\
						printf("[2]View Today's Reservation\n\n");
						
#define Clinic_Introduction() printf("\n\t\t\t\t\t\t\t**********Welcome to Our Clinic**********");\
							  printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
						
/*STD Types*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef enum Admin_Featuress Admin_Features;
typedef enum User_Featuress User_Features;
typedef struct Patients Patient;

/*LinkedList Struct (New_Patient)*/
Patient New_Patient;

/*Pointers for LinkedList Head and Tail*/
Patient *New;
Patient *Last;

/*Global Variables*/
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

/*Struct For LinkedList*/
struct Patients
{
	u8 Name[100];
	u8 Age;
	u8 Gender;
	u32 ID;
	Patient *Next;
};

/*Global Variables*/
u32 ListLength = 0;
/*Flag for wrong choice in features*/
u8 Flag_2 = 0;

u8 Mode;
	
/*Functions ProtoTypes*/
void Clinic_voidModes();
u8 Clinic_u8AdminModePassword();
void Clinic_VoidAdminFunctions();
//void Clinic_voidAddNewPatient();
//u8 Clinic_u8IDChecking(u32 I_D);
void AddNode();
void PrintLinkedList();
u8 IDCheck(u32 ID);

/*Main Function*/
void main(void)
{
	/*this to clear the CMD*/
	system("cls");
	
	/*Flag_1 for Exit the while Loop*/
	u8 static Flag_1 = 0;
	
	/*Local Variables*/
	u8 i, Pass;
	
	while(Flag_1 != 1)
	{
		if(Flag_1 == 1)
		{
			break;
		}
		Clinic_voidModes();
		
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
					Flag_1 = 1;
				}
				
			break;
			
			case User_Mode:
			break;
			
			case Exit_The_System:
				printf("\n\t\t\t\t\t\t\t\t  ******Thank you******");
				printf("\n\t\t\t\t\t\t\t ****************************************");
				Flag_1 = 1;
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
			AddNode();
		break;
		
		case Edit_Patient_Record:
		
		break;
		
		case Reserve_a_Slot_With_The_DoctOR:
		
		break;
		
		case Cancel_Reservation:
		
		break;
		
		case Exit_Admin_Mode:
		/*Empty to break the switch case and then break the switch in the main function the looping in while loop*/
		break;
	}
}

void AddNode()
{ 
	u32 IDFC; //ID For Checking
	u8 Flag_4, Flag_3 = 0, Flag_6 = 0, Again, i;
	//Flag_3 For Choosing the Gender
	//Flag_4 For the ID
	//Flag_6 For Add another Patient or No
	
	/*First Node to Creat*/
	/*that is mean Linked List Length = 0*/
	if(ListLength == 0)
	{		
		printf("Please, Enter Your ID: ");
		scanf("%d", &New_Patient.ID);
		
		printf("\nPlease, Enter Your Name: ");
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
		Flag_3 = 0;
		/*when tha last point to null and you want to add node you will need the (Node) Size*/
		/*so the next is to callculate the New Node Size*/
		New = (Patient*)malloc(sizeof(Patient));
		
		/*After we have a new node we need to assign the values in it*/
		printf("\nPlease, Enter Your ID: ");
		//scanf("%d", &New -> ID);
		scanf("%d", &IDFC);
		
		Flag_4 = IDCheck(IDFC);
		
		if(Flag_4 == True)
		{
			printf("ID Is NOT Repeated\n");
			(New -> ID) = IDFC;
		}
		
		if(Flag_4 == False)
		{
			printf("ID Is Repeated\n");
			(New -> ID) = 5;
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
		Flag_3 = 0;
	}
	
	while(Flag_6 != 1)
	{
		printf("\nDo you want to add another new patient ?\n[1]yes          [2]No\n");
		scanf("%d",&Again);
		
		if(Again == 1)
		{
		 printf("-------------------\n");		
		 AddNode();
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
}

u8 IDCheck(u32 ID)
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

	// for(i = 0; i < 3; i++)
			// {
				// if(Flag_4 == True)
				// {
					// (New -> ID) = IDFC;
					// break;
				// }
				
				// printf("The ID is Repeated Please, Try another ID: \n");
				// scanf("%d", &IDFC);
				// Flag_4 = Clinic_u8IDChecking(IDFC);
				// printf("bbbbbbbbbbbjjjjjjjjjjjj          %d", Flag_4);
	
				// if(Flag_4 == True)
				// {
					// (New -> ID) = IDFC;
					// break;
				// }
				// else if(i == 2)
				// {
					// printf("You have Entered Repeated ID 3 Times");
					// printf("Thanks");
					// Clinic_VoidAdminFunctions();
				// }
			// }