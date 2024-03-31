/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : aydin ghorbani
Student ID#: 124170226
Email      : aghorbani@myseneca.ca
Section    : ZBB


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//


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
            printf("Error! ");
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

void inputCString(char* string, int min, int max)
{
	int counter, valid = 0, i = 0;
	char temp[100];

	while (!valid)
	{

		scanf("%[^\n]", temp);
		counter = 0;
		for (i = 0; temp[i] != '\0'; i++)
		{
			counter++;
		}
		if (min != max)
		{
			if (counter > min - 1 && counter < max + 1)
			{
				valid = 1;
			}
			else if (counter < min)
			{
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
			}
			else if (counter > max)
			{
				printf("ERROR: String length must be no more than %d chars: ", max);
			}

		}
		else if (counter > min - 1 && counter < max + 1)
		{
			if (counter == min)
			{
				valid = 1;
			}
		}
		else
		{
			printf("ERROR: String length must be exactly %d chars: ", min);
		}

		clearInputBuffer();
	}
	for (i = 0; temp[i] != '\0'; i++)
	{
		string[i] = temp[i];
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

