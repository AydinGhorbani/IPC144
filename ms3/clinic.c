/*/////////////////////////////////////////////////////////////////////////
			Assignment 1 - Milestone 3
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

#include <stdio.h>
#include <string.h>
#include <ctype.h>           //this library is used in inputPhoneData function to call toupper() function.


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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
	printf("<ALL>\n\n");
	printf("Date       Time  Pat.# Name            Phone#\n"
	       "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
	printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
	printf("Time  Pat.# Name            Phone#\n"
	       "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
			 const struct Appointment* appoint,
			 int includeDateField)
{
    if (includeDateField)
    {
	printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
	       appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
	   patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
	    menuPatient(data->patients, data->maxPatient);
	    break;
	case 2:
	    menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
	printf("Appointment Management\n"
	       "==============================\n"
	       "1) VIEW   ALL Appointments\n"
	       "2) VIEW   Appointments by DATE\n"
	       "3) ADD    Appointment\n"
	       "4) REMOVE Appointment\n"
	       "------------------------------\n"
	       "0) Previous menu\n"
	       "------------------------------\n"
	       "Selection: ");
	selection = inputIntRange(0, 4);
	putchar('\n');
	switch (selection)
	{
	case 1:
	    viewAllAppointments(data);  // ToDo: You will need to create this function!
	    suspend();
	    break;
	case 2:
	    viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
	    suspend();
	    break;
	case 3:
	    addAppointment(data->appointments, data->maxAppointments,
			   data->patients, data->maxPatient);  // ToDo: You will need to create this function!
	    suspend();
	    break;
	case 4:
	    removeAppointment(data->appointments, data->maxAppointments,
			      data->patients, data->maxPatient);  // ToDo: You will need to create this function!
	    suspend();
	    break;
	}
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max) {

    int selection = 0 , i =0 ;

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

	if (selection == 1) {
	    searchPatientByPatientNumber(&patient[i], max);
	    printf("\n");
	    suspend();
	} else if (selection == 2) {
	    searchPatientByPhoneNumber(&patient[i], max);
	    printf("\n");
	    suspend();
	}

    } while (selection != 0);
}



// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i = 0, flag = 0, index = 0;
    for (i = 0; i < max + 1 && flag == 0; i++)
    {
	if (patient[i].patientNumber == 0)
	{
	    flag++;
	}
	index = i;
    }

    if (i == max + 1)
    {
	printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
	patient[index].patientNumber = nextPatientNumber(patient, max) + 1;
	inputPatient(&patient[index]);
	printf("*** New patient record added ***\n\n");
	flag++;
    }

}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {

    int patientIndex = 0, input = 0;
    printf("Enter the patient number: ");
    input = inputInt();

    patientIndex = findPatientIndexByPatientNum(input, patient, max);
    if (patientIndex != -1) {
	printf("\n");
	menuPatientEdit(&patient[patientIndex]);
    }
    else {
	printf("ERROR: Patient record not found!\n\n");
    }
}



// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int userInput = 0, i = 0;
    char option;
    printf("Enter the patient number: ");
    userInput = inputInt();
    printf("\n");
    int index = findPatientIndexByPatientNum(userInput, patient, max);
    if (index != -1)
    {
	i = index;
	displayPatientData(&patient[i], FMT_FORM);
	putchar('\n');
	printf("Are you sure you want to remove this patient record? (y/n): ");
	option = inputCharOption("yn");
	if (option == 'y')
	{
	    patient[i].patientNumber = 0;
	    strcpy(patient[i].name, "");
	    strcpy(patient[i].phone.description, "");
	    strcpy(patient[i].phone.number, "");
	    printf("Patient record has been removed!\n\n");
	}
	else if (option == 'n')
	{
	    printf("Operation aborted.\n\n");
	}
	clearInputBuffer();
    }
    else
    {
	printf("ERROR: Patient record not found!\n\n");
    }
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i = 0, j = 0;
    
   struct ClinicData sorted = {0};
    sorted = *data;
    
    displayScheduleTableHeader(&data->appointments->date, 1);
    
    sort(&sorted);
    
    for (i=0;sorted.appointments[i].patientNumber!=0;i++)
    {
	for (j=0; sorted.patients[j].patientNumber != 0;j++) {
	    if (sorted.appointments[i].patientNumber == sorted.patients[j].patientNumber) {
		displayScheduleData(&sorted.patients[j], &sorted.appointments[i], 1);
	    }
	    
	}
	
    }
    printf("\n");
}


// View appointment schedule for the user input date
// Todo:
int viewAppointmentSchedule(struct ClinicData* data)
{
    
    int i =0 ,j = 0;
    struct Date tempDate = { 0 };
    struct ClinicData sorted = { 0 };
    
    sorted = *data;
    inputDate(&tempDate);
    

    sort(&sorted);
    
    printf("\n");
    
    displayScheduleTableHeader(&tempDate,0);
    for (i = 0; sorted.appointments[i].patientNumber != 0; i++)
    {
	
	if (sorted.appointments[i].date.year== tempDate.year && sorted.appointments[i].date.month== tempDate.month && sorted.appointments[i].date.day == tempDate.day)
	{
	    for (j = 0; sorted.appointments[j].patientNumber != 0; j++) {
	    if (sorted.appointments[i].patientNumber == sorted.patients[j].patientNumber)
	    {
		    displayScheduleData(&sorted.patients[j], &sorted.appointments[i], 0);
	    }
	    }
	}
    }
    printf("\n");
    return 0;
}


// Add an appointment record to the appointment array
// Todo:
int addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    struct Appointment temp = { 0 };
    int valid = 0, i = 0;
    printf("Patient Number: ");
    temp.patientNumber = inputIntPositive();

    while (!valid) {
	inputDate(&temp.date);
	do {
	    printf("Hour (0-23)  : ");
	    temp.time.hour = inputIntRange(0, 23);
	    printf("Minute (0-59): ");
	    temp.time.min = inputIntRange(0, 59);
	    if ((temp.time.min != 0 && temp.time.min != 30) || temp.time.hour < 10 || temp.time.hour>14 ||(temp.time.hour == 14 && temp.time.min > 0))
	    {
		printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
	    }
	    else
	    {
		valid = 1;
	    }
	} while (!valid);
	
	for (i = 0; appointments[i].patientNumber != 0; i++)
	{
	    if (temp.date.year == appointments[i].date.year && temp.date.month == appointments[i].date.month &&
		temp.date.day == appointments[i].date.day && temp.time.hour == appointments[i].time.hour && temp.time.min == appointments[i].time.min)
	    {
		valid = 0;
		printf("\nERROR: Appointment timeslot is not available!\n\n");
		break;
	    }
	}
    }

    appointments[i] = temp;
    printf("\n*** Appointment scheduled! ***\n\n");
    return 0;
}

// Remove an appointment record from the appointment array

//break is used in this function.
// i could find no uder way to do.
int removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatients)
{
    int valid = 0, patientIndex = 0, appointmentIndex = 0 , i= 0;
    struct Appointment temp = { 0 };
    struct Date date = { 0 };
    
    printf("Patient Number: ");
    temp.patientNumber = inputIntPositive();
    
    // Find the patient index
    while (patients[patientIndex].patientNumber != 0 && !valid) {
	if (patients[patientIndex].patientNumber == temp.patientNumber) {
	    valid = 1;
	    break;
	}
	patientIndex++;
    }

    if (!valid) {
	printf("ERROR: Patient record not found!\n\n");
	clearInputBuffer();
	return 0;
    }

    // Get the appointment date and time
    do {
	inputDate(&date);
	valid = 0;
	appointmentIndex = 0;
	
	while (appointmentIndex < maxAppointments && appointments[appointmentIndex].patientNumber != 0 && !valid) {
	    if (appointments[appointmentIndex].patientNumber == temp.patientNumber &&
		appointments[appointmentIndex].date.year == date.year &&
		appointments[appointmentIndex].date.month == date.month &&
		appointments[appointmentIndex].date.day == date.day) {
		valid = 1;
		break;
	    }
	    appointmentIndex++;
	}
	
	if (!valid) {
	    printf("ERROR: Appointment timeslot is not available!\n\n");
	}
    } while (!valid);

    // Confirm appointment removal
    printf("\n");
    displayPatientData(&patients[patientIndex], FMT_FORM);
    printf("Are you sure you want to remove this appointment (y,n): ");
    char confirmation = getchar();
    clearInputBuffer();
    
    if (confirmation == 'n') {
	printf("\nAppointment not removed.\n\n");
	return 0;
    }
    
    // Shift remaining appointments down
    for (i = appointmentIndex; i < maxAppointments - 1; i++) {
	appointments[i] = appointments[i + 1];
    }
    appointments[maxAppointments - 1].patientNumber = 0;
    
    printf("\nAppointment record has been removed!\n\n");
    return 1;
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int userInput = 0, index = 0;
    printf("Search by patient number: ");
    userInput = inputInt();
    index = findPatientIndexByPatientNum(userInput, patient, max);
printf("\n");
    if (index != -1)
    {
	displayPatientData(&patient[index], FMT_FORM);
    }
    else
    {
	printf("*** No records found ***\n");
    }
}



// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int  i = 0, findCounter = 0;
    char userInput[100] = { 0 };
    printf("Search by phone number: ");
    inputCString(userInput, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
	if (!strcmp(userInput, patient[i].phone.number))
	{
	    displayPatientData(&patient[i], FMT_TABLE);
	    findCounter++;
	}
    }
    if (findCounter == 0)
    {
	printf("\n*** No records found ***");
    }

}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, maxNum = 0;
    for (i = 0; i < max; i++)
    {
	if (maxNum < patient[i].patientNumber)
	{
	    maxNum = patient[i].patientNumber;
	}
    }
    return maxNum;
}


// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
	"------------------\n");
    printf("Number: %-.5d\n", patient->patientNumber);

    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int i;
    const char* descriptions[] = {"Cell", "Home", "Work", "TBD"};
    const int numDescriptions = sizeof(descriptions) / sizeof(char*);
    
    printf("Phone Information\n"
	   "-----------------\n"
	   "How will the patient like to be contacted?\n");
    
    for (i = 0; i < numDescriptions; i++)
    {
	printf("%d. %s\n", i+1, descriptions[i]);
    }
    printf("Selection: ");
    int selection = inputIntRange( 1, numDescriptions);
    printf("\n");
    if (selection < numDescriptions)
    {
	char descriptionUpperCase[strlen(descriptions[selection-1])+1];
	strcpy(descriptionUpperCase, descriptions[selection-1]);
	for(i=0; descriptionUpperCase[i]; i++){
	    descriptionUpperCase[i] = toupper(descriptionUpperCase[i]);
	}
	strcpy(phone->description, descriptionUpperCase);
	printf("Contact: %s\nNumber : ", phone->description);
	inputCString(phone->number, PHONE_LEN ,PHONE_LEN);
    }
    else
    {
	strcpy(phone->description, descriptions[selection-1]);
	strcpy(phone->number, "");
    }
    
    printf("\n");
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0 ,result = 0;
    FILE* fp = fopen(datafile, "r");
    if (fp == NULL) {
	return 0;
    }
    result = fscanf(fp, "%d|%15[^|]|%4[^|]|%10[^\n]\n", &patients[i].patientNumber,
			patients[i].name, patients[i].phone.description, patients[i].phone.number);
    while (result != EOF && i < max) {
	i++;
	result = fscanf(fp, "%d|%15[^|]|%4[^|]|%10[^\n]\n", &patients[i].patientNumber,
			patients[i].name, patients[i].phone.description, patients[i].phone.number);
    }
    fclose(fp);
    return i;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int counter = 0, i= 0;
    FILE* fp = fopen(datafile, "r");
    if (fp == NULL) {
	return counter;
    }
    while (counter < max && fscanf(fp, "%d,%d,%d,%d,%d,%d\n", &appoints[counter].patientNumber,
				     &appoints[counter].date.year, &appoints[counter].date.month,
				     &appoints[counter].date.day, &appoints[counter].time.hour,
				     &appoints[counter].time.min) == 6) {
	counter++;
    }
    for (i = counter; i < max; i++) {
	appoints[i].patientNumber = 0;
    }
    fclose(fp);
    return counter;
}


// Compare dates and times to sort appointments
void sort(struct ClinicData* sorted)
{
    int i, j;
    struct Appointment temp;
    for (i = 0; sorted->appointments[i].patientNumber != 0; i++)
    {
	for (j = 0; sorted->appointments[j + 1].patientNumber != 0; j++)
	{
	    // Compare dates and time
	    if ((sorted->appointments[j].date.year > sorted->appointments[j + 1].date.year) ||
		(sorted->appointments[j].date.year == sorted->appointments[j + 1].date.year && sorted->appointments[j].date.month > sorted->appointments[j + 1].date.month) ||
		(sorted->appointments[j].date.year == sorted->appointments[j + 1].date.year && sorted->appointments[j].date.month == sorted->appointments[j + 1].date.month && sorted->appointments[j].date.day > sorted->appointments[j + 1].date.day) ||
		(sorted->appointments[j].date.year == sorted->appointments[j + 1].date.year && sorted->appointments[j].date.month == sorted->appointments[j + 1].date.month && sorted->appointments[j].date.day == sorted->appointments[j + 1].date.day && sorted->appointments[j].time.hour > sorted->appointments[j + 1].time.hour) ||
		(sorted->appointments[j].date.year == sorted->appointments[j + 1].date.year && sorted->appointments[j].date.month == sorted->appointments[j + 1].date.month && sorted->appointments[j].date.day == sorted->appointments[j + 1].date.day && sorted->appointments[j].time.hour == sorted->appointments[j + 1].time.hour && sorted->appointments[j].time.min > sorted->appointments[j + 1].time.min))
	    {
		temp = sorted->appointments[j];
		sorted->appointments[j] = sorted->appointments[j + 1];
		sorted->appointments[j + 1] = temp;
	    }
	}
    }
}

//
//    *     *       *     *
//  *         *   *         *
//*             *             *
//*                           *
//*    professor Ian Tipson   *
//  *                        *
//    *    Thank You for   *
//      *   Teaching Us  *
//        *      C!    *
//          *        *
//            *    *
//               *
//
