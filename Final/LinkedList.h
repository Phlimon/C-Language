/*Header Protection*/
#ifndef _Linked_List_H
#define _Linked_List_H

#include "STD.h"

typedef struct Patients Patient;
typedef enum Admin_Featuress Admin_Feature;

struct Patients
{
	u32 Struct_u32ID;
	u8 Struct_u8Name[100];
	u8 Struct_u8Age;
	u8 Struct_u8Gender;
	Patient *Next;
};

/*Enum for Admin Features*/
enum Admin_Featuress
{
	Add_New_Patient_Record = 1,
	Edit_Patient_Record,
	Reserve_a_Slot_With_The_DoctOR,
	Cancel_Reservation
};						 


/*Including the Standard types Library*/
#include "STD.h"

/*Defines for the Modes of the Program*/
#define Admin_Mode      1
#define User_Mode       2
#define Exit_The_System 3

#define True  1
#define False 0

#define Male 	1
#define Female  2

#define Yes 1
#define No  2

#define PasswordDefined 1234

/*thisis the introduction for our Program and mad as Macro to Easy and Readablity*/
#define Clinic_Introduction() printf("\n\t\t\t\t\t\t\t**********Welcome to Our Clinic**********");\
							  printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
							  
#define ADMIN_FEATURES() printf("\n[1]Add New Patient Record\n");\
						 printf("[2]Edit Patient Record\n");\
						 printf("[3]Reserve a Slot with the Doctor\n");\
						 printf("[4]Cancel Reservation\n");\
						 printf("Exit Admin Mode Press any number else");	


/*Description: This Function to get witch mode that you want Admin Mode or User Mode or Exit_The_System
 *Arguments	 : it Takes the Flag of the Modes if it = 0 so you choose right choice if not invaled choice
 *Returns	 : it returns the Mode Number Admin_Mode, User_Mode, Exit_The_System
 */							  
u8 Clinic_u8Modes(u8 Copy_u8FlagMode);

/*Description: This Function to get the Admin Password and check if it true or false and send the flag 
 *Arguments	 : No Arguments
 *Returns	 : it returns the Flag if Password True = 1 or False = 0
 */
u8 Clinic_u8AdminPassword();							  

/*Description: This Function provides all the Admin Functionalites[Add_New_Patient_Record, Edit_Patient_Record
				Reserve_a_Slot_With_The_DoctOR, Cancel_Reservation] 
 *Arguments	 : No Arguments
 *Returns	 : Non
 */
u8 Clinic_u8AdminFunctionalities();

/*Description: This Function to Adding a new Patient by making new Node and assign values to it and allocate it in LinkedList 
 *Arguments	 : No Arguments
 *Returns	 : Non
 */
void Clinic_voidAddNewPatient();

/*Description: This Function to Check the ID that Admin give to the Patient if it  exsist or not to not repeat any IDs 
 *Arguments	 : the ID of the Patient
 *Returns	 : it returns the Flag if ID Repeated True = 1 or Not False = 0
 */
u8 Clinic_u8IDChecking(u32 Local_u32ID);

//Patient Clinic_PatientIDChecking(u32 Local_u32ID);

void Clinic_voidPrintList(void);
#endif