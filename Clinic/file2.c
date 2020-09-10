#include<stdio.h>
#include<stdlib.h>
//++++++++++++++++++++++++++++++++++++++++include_files++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//========================================typedefs======================================================


typedef unsigned  char u8;
typedef unsigned long int u32;
typedef float f32;
typedef double f64;

//=======================================#defines=========================================================
#define male 1
#define female 2
#define repeated 1
#define unrepeated 0
#define slots()		printf("|1| From 2:00 pm to 2:30 pm\n");\
					printf("|2| From 2:30 pm to 3:00 pm\n");\
					printf("|3| From 3:00 pm to 3:30 pm\n");\
					printf("|4| From 4:00 pm to 4:30 pm\n");\
                    printf("|5| From 4:30 pm to 5:00 pm\n")
typedef enum 
	{
		Add_new_patient_record = 1,
		Edit_patient_record ,
		Reserve_a_slot_with_the_doctor,
		Cancel_reservation
	}features;

struct  user
	{
		u8 name[10];
		u8    age;
		u8    gender;
		u32   id;
		struct user *nptr;
	};

typedef struct user node;	

struct day
{
	u8 slot1 ;
	u8 slot2 ;
	u8 slot3 ;
	u8 slot4 ;
	u8 slot5 ;
	u32 id1;
	u32 id2;
	u32 id3;
	u32 id4;
	u32 id5;
};
	
//****************************************functions_prototypes+++++++++++++++++++++++++++++++++++++++++++++++++++	
 
 void ll_NewPatient(void);
 u8  ll_checkid(u32 check);	
 void ll_EditPatient(u32 x);
 void ll_ViewRecord(u32 x);
 void arr_ReserveSlot(u32 x);
 void arr_ViewReservations(void);

//****************************************linked list+++++++++++++++++++++++++++++++++++++++++++++++++++++	
	node *head = NULL;
	node *tail = NULL;

//****************************************global values**********************************************	
	u32 ID;//used each time i take id
	struct day week[7];
	
//****************************************main function***************************************************	
void main(void)
{
	u8 mode, user_mode, y, yy, yyy, flag = 0, flag1=0, flag5 = 0, flag6 = 0, flag7 = 0, i;
	static u8 Edit ;
	static u32 password;
	features feature;
while(flag != 1)
{	
	printf("\n===================\n");
	printf("\nchoose  the mode number please\n(1)Admin mode\n(2)User mode\n");
	scanf("%d",& mode);
	printf("===================\n");
	
	switch(mode)
	{
//============================================admin mode=============================================================
			case 1 :
		
			for(i = 0; i < 3; i++)
			{
					printf("\nplease enter password\n");
					scanf("%d",& password);
					
					if( password == 1234)//true pass dah lsa 
					{   
						printf("\n===================\n");
						printf("choose number of wanted feature:\n_______________________________\n(1)Add new patient record\n(2)Edit patient record\n(3)Reserve a slot with the doctor\n(4)Cancel reservation\n ");
						scanf("%d",& feature);
						switch(feature)
						{
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^first feature in admin^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
							case Add_new_patient_record:
								
								printf("\n===================\n");
								ll_NewPatient();
								
								break;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^second featurein admin^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^							
							case Edit_patient_record:
								
								 printf("\n===================\n");
								 printf("Enter the ID of user you wanted to edit\n");
								 scanf("%d",& ID);
								 Edit  = ll_checkid (ID);
								 if( Edit == 1 )
								 {
									ll_EditPatient(ID);
								 } 
								 else
								 {
									printf("you entered unexisted ID\n"); 
								 }
								break;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^third feature admin^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
							case Reserve_a_slot_with_the_doctor:
									
									do
									{
									 printf("\n===================\n");
									 printf("Enter the ID of user \n");
									 scanf("%d",& ID);
									 Edit  = ll_checkid (ID);
									 if( Edit == 1 )
									 {
										arr_ReserveSlot(ID);
									 } 
									 else
									 {
										printf("you entered unexisted ID\n");
										printf("\n-------------------\n");
										
									 }
							
									 printf("Do you want to reserve another reservation ?\n [1]Yes					[2]Go to start menu\n");
									 scanf("%d",& yy );
									 printf("\n-------------------\n");
									 if( yy == 2)
									 {
										flag6 = 1; 
									 } 
									 else if( yy == 1);
									 else 
									 {
										 printf("{You entered wrong choice}\n");
										 printf("\n-------------------\n");
									 }
									}
									while(flag6 == 0);
								break;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^fourth feature admin^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 
																printf("4");
								break;

							default:
								printf("{wrong feature number}\n");
						}
						break;//end of features 
					}
					
					else if( i == 2)
					{
						printf("sorry, you entered password wrong for 3 times\n");
						break;
					}	
					
			}//end of for loop
			
		
		
		break;//end of admin case
//______________________________________________________user mode________________________________________________________________________________		
		
		case 2 :
				
				printf("\n**********++++++++++**********\n");
				printf("Welcome User\n Choose wanted feature :\n [1]View patient record\n [2]View today's reservations\n ->");	
				scanf("%d",& user_mode);
				printf("\n**********++++++++++**********\n");
	
//first user feature{view record}:->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				
				if(user_mode == 1)
				{
					printf("Enter the patient ID\n");
					scanf("%d",& ID);
					
					Edit  = ll_checkid (ID);
					
					 if( Edit == 1 )
					 {
						ll_ViewRecord(ID);
					 } 
					 else
					 {
						printf("you entered unexisted ID\n"); 
					 }
					
					printf("\n******************************\n");	
					while(flag5 == 0)
					{	
						printf("DO you want to view another patient record ?\n1)yes					2)no\n");
						scanf("%d",& y);
							
						if(y == 1)
						{	
							 printf("Enter another patient ID\n");
							 scanf("%d",& ID);
							 Edit = ll_checkid (ID);
							 
							 if( Edit == 1 )
								 {
									ll_ViewRecord(ID);
								 } 
							 else
								 {
									printf("you entered unexisted ID\n"); 
								 }
						}
						else if( y == 2)
						{
							flag5 = 1;
						}
						else
						{
							printf("{you must choose 1 OR 2}\n");
						}							
					}		
				}
//second user feature{view today}:->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>				
				else if(user_mode == 2)//reservations
				{
					do
					{	
						arr_ViewReservations();
						printf("Do you want to show another day 's reservations ?\n [1]Yes					[2]Go to start menu\n");
						scanf("%d",& yyy );
						printf("\n-------------------\n");
						if( yyy == 2)
						 {
							flag7 = 1; 
						 } 
						else if( yyy == 1);
						else 
						 {
							 printf("{You entered wrong choice}\n");
							 printf("\n-------------------\n");
						 }					
					}
					while(flag7 == 0);
				}
				else
				{
					printf("sorry , no available feature has this number\n ");
				}	
				
		break;//end of user case
		default:
	
		printf("you entered undefined mode number\n");
		printf("\n===================\n");
	}
//=======================================close the program===============================================	
	while(flag1 == 0)
	{
		printf("*****************************************************************\n\nDO you want to : \n(1)Exit					(2)go to start menu\n");
		scanf("%d",& Edit);
		
		if(Edit == 1)
		{
			flag = 1;
			flag1 = 1;
			printf("&&&&&&&&&&&&&&&&&&&&&&&&&{The Program is closed }&&&&&&&&&&&&&&&&&&&&&&&&& ");
		}
		else if(Edit == 2)
		{
			flag1=1;
		}	
		else
		{
			printf("error ,you entered wrong choice\n ");
		}
	}
}}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&fun1&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void ll_NewPatient(void)
 {
	struct user *ptr;
	u8 again, Ok, flag3 = 0;
	static u8 flag4 = 0;
	u32 check;
	ptr = (struct user*) malloc(sizeof(struct user));
	
	printf("Enter patient:\n______________\n\n(1)first name \n[In case the name exceed 10 letters enter Nickname & do not use spaces ]\n");
	scanf("%s",& ptr -> name);
	printf("-------------------\n");
	
	printf("\n(2)age\n");
	scanf("%d",& ptr -> age);
	printf("-------------------\n");

	while(flag3 == 0)
		{		
			printf("\n(3)gender number: 1]male					2]female\n");
			scanf("%d",& Ok);
				if(Ok == 1||Ok == 2)
				{
					ptr -> gender = Ok;
					flag3 = 1;
				}
				else
				{
				 printf("{You must enter number 1 or 2 only}\n");	
				}
		}		
	printf("-------------------\n");
	
	printf("\n(4)id\n");
    scanf("%d",& check);

	if( head == NULL)
	{
		ptr -> id = check;
	}
	
	else 
	{
		u8 diss = ll_checkid(check);
		
		switch(diss)
		{
			case repeated :
				while(1)
				{
				  printf("You entered an already used id choose new one\n");
				  scanf("%d",& check);
				  u8 case1 = ll_checkid(check);
				  if(case1 == unrepeated)
				   {
					  ptr -> id = check;
					  break;
					}
				}
				break;
		
			case unrepeated :
				 ptr -> id = check;
				 
				break;
		
		}	
	}
	printf("-------------------\n");
	
	
	if(head == NULL)
	{
		head = ptr;
		tail = ptr;
		ptr -> nptr = NULL;
	}
	else
	{
		tail -> nptr = ptr;
		tail = ptr;
		ptr -> nptr = NULL;
		
	}	
	
	do
	{
		printf("Do you want to add another new patient ?\n[1]yes          [2]No\n");
		scanf("%d",& again);
		
		if(again == 1)
		{
		 printf("-------------------\n");		
		 ll_NewPatient();
	
		}
		else if(again == 2)
		{
			flag4 = 1;
		}	
		else
		{
			printf("{You must choose [1] OR [2]}\n"); 
		}	
	}	
	while(flag4 == 0);
 }
 
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& fun2&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

u8  ll_checkid (u32 check)
{
	struct user *ptr = head;
	
	while (ptr != NULL) 
	{
		if((ptr->id)==check)
		{	
		 return repeated ;
		}
		else
		{
		 ptr = ptr-> nptr;
		}
	}
	return unrepeated ;
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&fun3(edit exist id)&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void ll_EditPatient(u32 x)
{
	node *ptr = head;
	static u32 y;
	static u8 Ok, flag1;

	while((ptr -> id) != x)
	{
		ptr = ptr -> nptr;
	}
	
	printf("Choose one number for type of information you want to edit(1]Name, 2]ID, 3]Gender, 4]Age)\n");
	scanf("%d",& y);
	
	
	if (y == 1)//name
	{
		printf("-------------------\n");
		printf("you choose to change the name which is %s\nso,Please enter the new one\n", ptr -> name);
		scanf("%s",& ptr -> name);
	}
		
    else if (y == 2)//ID
	{
		printf("-------------------\n");
		printf("(Note : if you make any reservations with the old ID,you must change it by the new ID)\n ");
		printf("you choose to change the ID which is %d\nso,Please enter the new one\n", ptr -> id);		
		scanf("%d",& y);
		
		Ok = ll_checkid(y);
		if(Ok == 0)
		{
		 ptr -> id = y;
		}
		else 
		{
		 printf("you entered used ID try again\n");
		}
		
	}
 
	else if (y == 3)//gender
	{
		printf("-------------------\n");
		
		while(flag1 == 0)
		{
			printf("you choose to change gender which is number %d\nchoose update 1 or 2: 1]male					2]female\n", ptr -> gender);
			scanf("%d",& Ok);
					if(Ok == 1||Ok == 2)
					{
						ptr -> gender = Ok;
						flag1 = 1;
					}
					else
					{
					 printf("{you must enter number 1 or 2 only}\n");	
					}
		}	
	}

	else if (y == 4)//age
	{
		printf("-------------------\n");
		printf("you choose to change the age which is %d\nso,Please enter the new one\n", ptr -> age);
		scanf("%d",& ptr -> age);
	}
	else
	{
		printf("-------------------\n");
		printf("you entered wrong choice \n");
	}	
    
	printf("DO you want to change another user's information \n(1)yes					(2)no\n");
	scanf("%d",& y);
	
	if(y == 1)
	{	
		
		 u8 Edit = ll_checkid (ptr->id);
		 if( Edit == 1 )
		 {
			ll_EditPatient(ptr -> id);
		 } 
	}	
	
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& fun3 print info&&&&&&&&&&&&&&&&&&&&&&&&&&
void ll_ViewRecord(u32 x)
{
	node *ptr = head;
	
	while((ptr -> id) != x)
	{
		ptr = ptr -> nptr;
	}
	
	printf(" I)user Name:%s\n II)Age:%d\n III)gender: ", ptr -> name, ptr -> age);
	switch(ptr -> gender)
	{
		case male :
		printf("Male\n");
		break;
		
		case female :
		printf("Female\n");
		break;
		
		default:
		printf("error , refer to admin please");
	}	
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& fun reserve slot&&&&&&&&&&&&&&&&&&&&&&&&&& 

void arr_ReserveSlot(u32 x)
{
	static u8 free,i ;
			
	printf("\n-------------------\n");
	printf("first, Choose the day at  this week:\n [1]Saturday\n [2]Sunday\n [3]Monday\n [4]Tuesday\n [5]Wednesday\n [6]thurday\n [7]Friday\n");
	scanf("%d",& i);
	printf("\n-------------------\n");

	if(i < 8 && i > 0)
	{	
		i-=1;//choosen day of week
		
		printf("Second ,Please enter desired slot :\n");
		slots();
		scanf("%d",& free);//desired slot
		printf("\n-------------------\n");
		
		switch(free)//must be from 1 to 5
		{
			case 1://from 2pm
			if((week[i].slot1)!=1)
			{
				week[i].slot1=1;
				week[i].id1= x ;
			}
			else
			{
				printf("{This slot is choosen by another patient} \n");
				printf("\n-------------------\n");
			}
			break;
			
			case 2://from 2:30 pm
			if((week[i].slot2)!=1)
			{
				week[i].slot2=1;
				week[i].id2= x;
			}
			else
			{
				printf("{This slot is choosen by another patient} \n");
				printf("\n-------------------\n");
			}
			break;	
			
			case 3://from 3 pm
			if((week[i].slot3)!=1)
			{
				week[i].slot3=1;
				week[i].id3= x;
			}
			else
			{
				printf("{This slot is choosen by another patient} \n");
				printf("\n-------------------\n");
			}
			break;	
			
			case 4://from 4 pm
			if((week[i].slot4)!=1)
			{
				week[i].slot4=1;
				week[i].id4= x;
			}
			else
			{
				printf("{This slot are choosen by another patient} \n");
				printf("\n-------------------\n");
			}
			break;	
			
			case 5://from 4:30
			if((week[i].slot5)!=1)
			{
				week[i].slot5=1;
				week[i].id5= x;
			}
			else
			{
				printf("{This slot are choosen by another patient} \n");
				printf("\n-------------------\n");
			
			}
			break;
			
			default :
			printf("{You choose unexisted slot} \n");
			printf("\n-------------------\n");
			
	
		}	
	}
	else
	{
		printf("{You entered wrong day}\n");
		printf("\n-------------------\n");
	}	
	
	
	/*for(u8 i=0;i<7;i++)
	{
		printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",week[i].slot1,week[i].slot2,week[i].slot3,week[i].slot4,week[i].slot5,week[i].id1,week[i].id2,week[i].id3,week[i].id4,week[i].id5);
	}*/
}	
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&fun View today reservation&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void arr_ViewReservations(void)
{
	static u8 free,i ;
	
	printf("first, Choose the day at  this week:\n [1]Saturday\n [2]Sunday\n [3]Monday\n [4]Tuesday\n [5]Wednesday\n [6]thurday\n [7]Friday\n");
	scanf("%d",& i);
	printf("\n-------------------\n");

	if(i < 8 && i > 0)
	{	
		i-=1;//choosen day of week
		slots();//appear slots
		printf("\nSlot case :\n ");	
		printf("~~~~~~~~~~~~\n");
		
		
			//from 2pm
			if((week[i].slot1)==1)
			{
				printf("|1|BUSY by User of ID -> %d\n",week[i].id1);
			}
			else
			{
				printf("|1|Empty \n");
			}
			
			if((week[i].slot2)==1)//2:30 pm
			{
				printf("|2|BUSY by User of ID -> %d\n",week[i].id2);
			}
			else
			{
				printf("|2|Empty \n");
			}
			
			if((week[i].slot3)==1)//3 pm
			{
				printf("|3|BUSY by User of ID -> %d\n",week[i].id3);
			}
			else
			{
				printf("|3|Empty \n");
			}
			
			if((week[i].slot4)==1)//4 pm
			{
				printf("|4|BUSY by User of ID -> %d\n",week[i].id4);
			}
			else
			{
				printf("|4|Empty \n");
			}
			
			if((week[i].slot5)==1)//4:30 pm
			{
				printf("|5|BUSY by User of ID -> %d\n",week[i].id5);
				printf("\n-------------------\n");
			}
			else
			{
				printf("|5|Empty \n");
				printf("\n-------------------\n");
			}
	}
	else
	{
		printf("{You entered wrong day}\n");
		printf("\n-------------------\n");
	}	
}