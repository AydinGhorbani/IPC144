/*/////////////////////////////////////////////////////////////////////////
			Assignment 1 - Milestone 2
Full Name  : Aydin Ghorbani
Student ID#: 124170226
Email      : aghorbani8@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
	   "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
	printf("Name  : %s\n"
	       "Number: %05d\n"
	       "Phone : ", patient->name, patient->patientNumber);
	displayFormattedPhone(patient->phone.number);
	printf(" (%s)\n", patient->phone.description);
    }
    else
    {
	printf("%05d %-15s ", patient->patientNumber,
	       patient->name);
	displayFormattedPhone(patient->phone.number);
	printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
	printf("Veterinary Clinic System\n"
	       "=========================\n"
	       "1) PATIENT     Management\n"
	       "2) APPOINTMENT Management\n"
	       "-------------------------\n"
	       "0) Exit System\n"
	       "-------------------------\n"
	       "Selection: ");
	selection = inputIntRange(0, 2);
	putchar('\n');
	switch (selection)
	{
	case 0:
	    printf("Are you sure you want to exit? (y|n): ");
	    selection = !(inputCharOption("yn") == 'y');
	    putchar('\n');
	    if (!selection)
	    {
		printf("Exiting system... Goodbye.\n\n");
	    }
	    break;
	case 1:
	    menuPatient((*data).patients, data->maxPatient);
	    break;
	case 2:
	    printf("<<< Feature not yet available >>>\n\n");
	    break;
	}
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
	printf("Patient Management\n"
	       "=========================\n"
	       "1) VIEW   Patient Data\n"
	       "2) SEARCH Patients\n"
	       "3) ADD    Patient\n"
	       "4) EDIT   Patient\n"
	       "5) REMOVE Patient\n"
	       "-------------------------\n"
	       "0) Previous menu\n"
	       "-------------------------\n"
	       "Selection: ");
	selection = inputIntRange(0, 5);
	putchar('\n');
	switch (selection)
	{
	case 1:
	    displayAllPatients(patient, max, FMT_TABLE);
	    suspend();
	    break;
	case 2:
	    searchPatientData(patient, max);
	    break;
	case 3:
	    addPatient(patient, max);
	    suspend();
	    break;
	case 4:
	    editPatient(patient, max);
	    break;
	case 5:
	    removePatient(patient, max);
	    suspend();
	    break;
	}
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
	printf("Edit Patient (%05d)\n"
	       "=========================\n"
	       "1) NAME : %s\n"
	       "2) PHONE: ", patient->patientNumber, patient->name);
	
	displayFormattedPhone(patient->phone.number);
	
	printf("\n"
	       "-------------------------\n"
	       "0) Previous menu\n"
	       "-------------------------\n"
	       "Selection: ");
	selection = inputIntRange(0, 2);
	putchar('\n');

	if (selection == 1)
	{
	    printf("Name  : ");
	    inputCString(patient->name, 1, NAME_LEN);
	    putchar('\n');
	    printf("Patient record updated!\n\n");
	}
	else if (selection == 2)
	{
	    inputPhoneData(&patient->phone);
	    printf("Patient record updated!\n\n");
	}

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {

    int i, flagRecord = 1;
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
	if (patient[i].patientNumber != 0) {
	    displayPatientData(&patient[i], fmt);
	    flagRecord = 0;
	}
    }
    if (flagRecord) {
	printf("*** No records found ***");
    }

    printf("\n");


}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {

    int selection = 0;

    do {
	printf("Search Options\n");
	printf("==========================\n");
	printf("1) By patient number\n");
	printf("2) By phone number\n");
	printf("..........................\n");
	printf("0) Previous menu\n");
	printf("..........................\n");
	printf("Selection: ");
	selection = inputIntRange(0, 2);
	printf("\n");

	switch (selection) {
	case 1:
	    searchPatientByPatientNumber(patient, max);
	    printf("\n");
	    suspend();
	    break;
	case 2:
	    searchPatientByPhoneNumber(patient, max);
	    printf("\n");
	    suspend();
	    break;
	}
    } while (selection != 0); 
}


// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
    int i, listSize = 0;
    //    gets current list size
    for (i = 0; i < max; i++) {
	if (patient[i].patientNumber != 0) { 
	    listSize++;
	}
    }
    if (max > listSize) {

	patient[listSize].patientNumber = nextPatientNumber(patient, max); 
	inputPatient(patient + listSize); 
	printf("*** New patient record added ***\n\n");
    }
    else {
	printf("ERROR: Patient listing is FULL!\n\n");
    }
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {

    int patientIndex, input;
    printf("Enter the patient number: ");
    input = inputInt();
    printf("\n");
    patientIndex = findPatientIndexByPatientNum(input, patient, max);// find patient in current array by index. if not found -1.

    if (patientIndex != -1) {

	menuPatientEdit(&patient[patientIndex]);
    }
    else {
	printf("ERROR: Patient record not found!\n\n");
    }
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)


void removePatient(struct Patient patient[], int max) {

    int patientIndex, input;
    char choice;
    printf("Enter the patient number: ");
    input = inputInt();
    patientIndex = findPatientIndexByPatientNum(input, patient, max); 

    if (patientIndex != -1) {

	printf("\n");
	displayPatientData(&patient[patientIndex], FMT_FORM);
	printf("\n");

	printf("Are you sure you want to remove this patient record? (y/n): ");
	scanf(" %c", &choice);

	if (choice == 'n' || choice == 'N') {
	    printf("Operation aborted.\n\n");
	    clearInputBuffer();
	}
	else {
	    patient[patientIndex].patientNumber = 0;
	    printf("Patient record has been removed!\n\n");
	    clearInputBuffer();
	}
    }
    else {
	printf("\nERROR: Patient record not found!\n\n");
	//clearInputBuffer();
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patient[], int max) {

    int patientIndex, input;
    printf("Search by patient number: ");
    input = inputInt();
    printf("\n");
    patientIndex = findPatientIndexByPatientNum(input, patient, max);
   
    if (patientIndex != -1) {
	displayPatientData(&patient[patientIndex], FMT_FORM);
    }

    else {
	printf("*** No records found ***\n");
    }
}




// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {

    int i, recordFlag = 1;
    char phoneNumber[PHONE_LEN + 1] = { 0 };


    printf("Search by phone number: ");
    inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
	if (!(strcmp(patient[i].phone.number, phoneNumber))) {
	    
	    displayPatientData(&patient[i], FMT_TABLE);
       
	    recordFlag = 0;
	}
    }

    if (recordFlag) {
	printf("\n*** No records found ***\n");
    }
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {

    int i = 0;

    int maxNum = patient[i].patientNumber;

    for (i = 1; i < max; i++) {
	if (patient[i].patientNumber > maxNum) {
	    maxNum = patient[i].patientNumber;
	}
    }

   // nextNum = maxNum + 1;
    return maxNum + 1;
}



// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {

    int i;
   

    for (i = 0; i < max; i++) {
	if (patient[i].patientNumber == patientNumber) {
	    return i;
	}
    }
 
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);

}



// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {

    int selection;

    // display selection menu to user
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(0, 4);
    printf("\n");

    switch (selection)
    {

    case 1:// contact via cellphone
	strncpy(phone->description, "CELL", PHONE_DESC_LEN);
	break;

    case 2:// contact via home number
	strncpy(phone->description, "HOME", PHONE_DESC_LEN);
	break;

    case 3:// contact via work number
	strncpy(phone->description, "WORK", PHONE_DESC_LEN);
	break;

    case 4:// contact number to be determent(TDB)
	strncpy(phone->description, "TBD", PHONE_DESC_LEN);
	*phone->number = 0;
	break;
	// ***coding an error was not defined in pdf.
    default:
	printf("Error:\n");
	break;
    }
    if (selection != 4) {// if contact method was not TDB, prompt user for number input.
	printf("Contact: %s\n", phone->description);
	printf("Number : ");
	inputCString(phone->number, PHONE_LEN, PHONE_LEN);
	printf("\n");
    }

}
