/*/////////////////////////////////////////////////////////////////////////
			Assignment 1 - Milestone 1
Full Name  : Aydin Ghorbani
Student ID#: 124170226
Email      : aghorbani8@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS_

#include <stdio.h>



// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    char newLine = 'x';
    int value = 0;
    int valid = 0;

    while (!valid)
    {
	scanf("%d%c" , &value , &newLine);
	if (newLine == '\n')
	{
	    valid = 1;
	    return value;
	}
	else
	{
	    clearInputBuffer();
	    printf("Error! Input a whole number: ");
	}
	
	
    }
    return 0;
}

int inputIntPositive(void){

    int value = '0';
    int valid = 0;

    while (!valid)
    {
	scanf("%d" , &value);
	if (value > 0)
	{
	    valid = 1;
	    return value;
	}
	else if(value <= 0)
	{
	    clearInputBuffer();
	    printf("ERROR! Value must be > 0: ");
	}
	
	
    }
  return 0;
}

int inputIntRange(int lowerBound , int upperBound)
{
    int result = 0;
    int valid = 0;
    
    while(!valid)
    {
	result = inputInt();
	
	if(lowerBound > result || upperBound < result)
	{
	    printf("ERROR! Value must be between %d and %d inclusive: " , lowerBound , upperBound);
	}
	else
	{
	    valid = 1;
	    return result;
	}

    }
return 0;
}

char inputCharOption(const char validChar[])
{
    int i;
    int valid = 0;
    char singleChar = 'a';

    while (!valid)
    {
	scanf("%c" , &singleChar);

	for ( i = 0; validChar[i] != '\0' ; i++)
	{
	    if (validChar[i] == singleChar)
	    {
		valid = 1;
	    }
	}
	if (valid)
	{
	    return singleChar;
	}
	else
	{
	    clearInputBuffer();
	    printf("ERROR: Character must be one of [qwErty]: ");
	}
    }
    return 0;
}

void inputCString(char* cString , int minString , int maxString)
{

    int i , valid = 0 ; 
    char userString[30] = {0};

    while (!valid)
    { 
    clearInputBuffer();
    scanf("%[^\n]" , userString);

    for (i = 0; userString[i] != '\0'; i++)
    {
	;
    }
 
    if(minString == maxString)
    {
	if(i == minString)
	{
	    valid = 1;
	    for (i = 0; userString[i] != '\0' ; i++) 
	    {
	    cString[i] = userString[i];
	    }
	}
	else
	{
	    printf("ERROR: String length must be exactly %d chars: ", minString);
	}
	
    } 
    else if(minString <= i && maxString >= i)
    {
	    for (i = 0; userString[i] != '\0' ; i++) 
	    {
	    cString[i] = userString[i];
	    }
	valid = 1;
    }
    else if(i < minString)
    {
	printf("ERROR: String length must be between %d and %d chars: ", minString , maxString);
    }
    else 
    {
	printf("ERROR: String length must be no more than %d chars: ", maxString);
    }
    }
}
void displayFormattedPhone(const char *string)
{
    int i, valid = 1;
    if (string == NULL)
    {
    valid = 0;
    printf("(___)___-____");
    }
    else
    {
    for (i = 0; string[i] != '\0' && valid; i++)
    {
	// ASCII table => 48 = 0 , 57 = 9
	if (string[i] < 48 || string[i] > 57)
	{
	    valid = 0;
	}
    }
    if (i == 10 && valid)
    {
	printf("(%c%c%c)%c%c%c-%c%c%c%c", string[0], string[1], string[2], string[3], string[4], 
	string[5], string[6], string[7], string[8], string[9]);
    }
    else
    {
	printf("(___)___-____");
    }
    }
}
