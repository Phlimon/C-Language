///////////////////////////////////////////////////*Linked List*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*Liberaries*/
#include<stdlib.h>
#include<stdio.h>

#define True 1
#define False 0

#define Male 0
#define Female 1

/*STD Types*/
typedef struct Patients Patient;
typedef unsigned short int u32;
typedef unsigned char u8;

/*Global Variables*/
u32 ListLength = 0;
Patient New_Patient;
Patient *New;
Patient *Last;

/*Struct for what i need in linked List (Data, Link)*/
struct Patients
{
	u8 Name[100];
	u8 Age;
	u8 Gender;
	u32 ID;
	Patient *Next;
};

/*Functions ProtoTypes*/
void AddNode();
void PrintLinkedList();
u8 Clinic_u8IDChecking(u32 ID);

/*Main Function*/
void main(void)
{
	/*my Variables*/
	u8 static NewName;
	u32 static Input, NewSalary;
	u32 static New_ID;
	u8 ExitFlag = 0;
	
	/*LOOP*/
	while(ExitFlag == 0)
	{
		/*Choices avaliable*/
		printf("\n(0)To Add Node Enter\n");
		printf("(1)To Print the Linked List Enter\n");
		printf("(2)To Exit Enter\n\n");
		printf("Please, Enter your Choice: ");
		scanf("%d", &Input);
		
		switch(Input)
		{
			case 0:

			AddNode();
			printf("\nThank you your Node Added\n");
			break;
			
			case 1:
			PrintLinkedList();
			break;
			
			case 2:
			printf("\n\n  **Thank you**\n*****BYE BYE*****\n\n");
			ExitFlag = 1;
			break;
			
			default:
			printf("\nInvailed Choice,\nPlease, Try Again..\nThank you\n");
			break;
		}
	}
}

void AddNode()
{ 
	u32 IDFC; //ID For Checking
	u8 Flag_4, Flag_3 = 0, i;
	
	/*First Node to Creat*/
	/*that is mean Linked List Length = 0*/
	if(ListLength == 0)
	{		
		printf("\nPlease, Enter Your ID: ");
		scanf("%d", &New_Patient.ID);	

		printf("\nPlease, Enter Your Name: ");
		scanf("%s", &New_Patient.Name);
		
		printf("\nPlease, Enter the your Age: ");
		scanf("%d", &New_Patient.Age);
			
		while(Flag_3 != 1)
		{
			printf("Please, Enter Patient Gender: [1]Male\t\t[2]Female\n");
			printf("Gender is: ");
			scanf("%d", &New_Patient.Gender);
			
			if((New_Patient.Gender) == Male || (New_Patient.Gender) == Female)
			{
				Flag_3 = 1;
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
		/*when tha last point to null and you want to add node you will need the (Node) Size*/
		/*so the next is to callculate the New Node Size*/
		New = (Patient*)malloc(sizeof(Patient));
		
		/*After we have a new node we need to assign the values in it*/
		printf("\nPlease, Enter Your ID: ");
		//scanf("%d", &New -> ID);
		scanf("%d", &IDFC);
		
		Flag_4 = Clinic_u8IDChecking(IDFC);
		
		if(Flag_4 == True)
		{
			printf("ID Is NOT Repeated");
			(New -> ID) = IDFC;
		}
		
		if(Flag_4 == False)
		{
			printf("ID Is Repeated");
			(New -> ID) = 5;
		}
		
		printf("Please, Enter Your Name: ");
		scanf("%s", &New -> Name);
		
		printf("Please, Enter the your Age: ");
		scanf("%d", &New -> Age);
		
		while(Flag_3 != 1)
		{
			printf("Please, Enter Patient Gender: [1]Male\t\t[2]Female\n");
			printf("Gender is: ");
			scanf("%d", &New_Patient.Gender);
			
			if((New_Patient.Gender) == Male || (New_Patient.Gender) == Female)
			{
				Flag_3 = 1;
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
	}
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
		if((Last -> Gender) == Male)
		{
			printf("User Number %d = Male\n", i);
		}
		else
		{
			printf("User Number %d = Female\n", i);
		}
		
		/*Print the rest of the List*/
		while((Last -> Next) != NULL)
		{
			Last = (Last -> Next);
		
			printf("User Name %d = %s\n", (i + 1), (Last -> Name));
			printf("Node Number %d = %d\n", (i + 1), (Last -> ID));
			printf("Node Number %d = %d\n\n", (i + 1), (Last -> Age));
			if((Last -> Gender) == Male)
		{
			printf("User Number %d = Male\n", (i + 1));
		}
		else
		{
			printf("User Number %d = Female\n", (i + 1));
		}
			i++;
		}
		printf("-------------------------\n");
	}
}

u8 Clinic_u8IDChecking(u32 ID)
{	
	u8 Flag_2 = True;

	if(ListLength > 0)
	{
		Last = &New_Patient;
		u32 i = 1;
		
		if((Last -> ID) == ID)
		{
			Flag_2 = False;
			
			return Flag_2;
		}
		else
		{
			/*Print the rest of the List*/
			while((Last -> Next) != NULL)
			{
				Last = (Last -> Next);
			
				if((Last -> ID) == ID)
				{
					Flag_2 = False;
					break;
				}
			}
		}
	}
	return Flag_2;
}