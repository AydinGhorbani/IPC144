/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Aydin Ghorbani
Student ID#: 124170226
Email      : aghorbani@senecacollege.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_YEAR 2012
#define MIN_YEAR 2022

int main(void)
{
const int JAN = 1;
const int DEC = 12;
int Year = 0 , Month = 0;


printf("General Well-being Log\n"
       "======================\n");
do
{
  printf("Set the year and month for the well-being log (YYYY MM): ");
  scanf("%d %d", &Year , &Month);
  if (MAX_YEAR > Year || Year > MIN_YEAR)
  {
    printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
  }
 if (Month < JAN || Month > DEC)
  {
    printf("   ERROR: Jan.(1) - Dec.(12)\n");
  }
  

} while ((Year < MAX_YEAR || Year > MIN_YEAR) || (Month < JAN || Month > DEC));

    printf("\n");
    printf("*** Log date set! ***\n\n");
    printf("Log starting date: %d-" , Year);

switch (Month)
{
    case 1:
    printf("JAN");
    break;
    case 2:
     printf("FEB");
     break;
     case 3:
     printf("MAR");
     break;
     case 4:
     printf("APR");
     break;
     case 5:
     printf("MAY");
     break;
     case 6:
     printf("JUN");
     break;
     case 7:
     printf("JUL");
     break;
     case 8:
     printf("AUG");
     break;
     case 9:
     printf("SEP");
     break;
     case 10:
     printf("OCT");
     break;
     case 11:
     printf("NOV");
     break;
     case 12:
     printf("DEC");
     break;

   
}
printf("-01\n");

//printf("%02d\n, days++")

    return 0;
}