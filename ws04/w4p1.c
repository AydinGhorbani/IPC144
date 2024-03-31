/*/////////////////////////////////////////////////////////////////////////
			  Workshop - #4 (P1)
Full Name  :Aydin Ghorbani 
Student ID#:124170226 
Email      :aghorbani8@myseneca.ca 
Section    :ZBB 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
char looptype = 'a';
int loopNum = 0 ;
int i = 1;

printf("+----------------------+\n"
       "Loop application STARTED\n"
       "+----------------------+");
 







while (loopNum != 0 || looptype != 'Q')
{
 printf("\n\nD = do/while | W = while | F = for | Q = quit\n");
 printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
 scanf(" %c%d", &looptype , &loopNum);



  switch (looptype)
   { 
  
      case 'D': 
       if (loopNum <= 20 &&  3 <= loopNum )
    {
	printf("DO-WHILE: ");

	for (i = 0; i < loopNum;)
	{
	    printf("D");
	    i++;
	} 
    }
    else
    {
	printf("ERROR: The number of iterations must be between 3-20 inclusive!");
    }

     break;

     case 'W':
       if (loopNum <= 20 &&  3 <= loopNum )
    {
	printf("WHILE   : ");

	for (i = 0; i < loopNum;)
	{
	    printf("W");
	    i++;
	} 
    }
    else
    {
	printf("ERROR: The number of iterations must be between 3-20 inclusive!");
    }
 
     break;

      case 'F':
       if (loopNum <= 20 &&  3 <= loopNum )
    {
	printf("FOR     : ");

	for (i = 0; i < loopNum;)
	{
	    printf("F");
	    i++;
	} 
    }
    else
    {
	printf("ERROR: The number of iterations must be between 3-20 inclusive!");
    }
 

      break;


    case 'Q':
    if(loopNum == 0)
    {
		printf("\n");
	printf("+--------------------+\n"
	       "Loop application ENDED\n"
	       "+--------------------+\n");

    }
    else
    {
       printf("ERROR: To quit, the number of iterations should be 0!");
    }
	break;

       default:
       printf("ERROR: Invalid entered value(s)!");
    }   



}



    return 0;
}
