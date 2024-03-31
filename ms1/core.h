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

// default. to clear the buffer.
void clearInputBuffer(void);
// default
void suspend(void);
// to get a valid integer from the keyboard.
int inputInt(void);
// to get and validate a positive int value.
int inputIntPositive(void);
// to validate the promitted range.
int inputIntRange(int lowerBound , int upperBound);
// to validate the entered character matches any of the characters in the received C string argument.
char inputCharOption(const char validChar[]);
// to obtain user input for a C string value with a length
void inputCString(char* cString , int minString , int maxString);
// to display validated and calculated data
void displayFormattedPhone(const char* string);