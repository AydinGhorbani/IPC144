/*/////////////////////////////////////////////////////////////////////////
			  Workshop - #6 (P1)
Full Name  : Aydin Ghorbani
Student ID#: 124170226
Email      : aghorbani8@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ITEMS 10
#define MIN_ITEMS 1


int main(void)
{
int i = 0 , itemCount = 0;
const double MIN_INCOME = 500.00 , MAX_INCOME = 400000.00 , MIN_COST = 100.0 ;
double income = 0.0 , totalCosts = 0.0;

char financed [MAX_ITEMS] = {0};
double itemCost [MAX_ITEMS] = {0.0};
int priority [MAX_ITEMS] = {0};



 printf("+--------------------------+\n"
	"+   Wish List Forecaster   |\n"
	"+--------------------------+\n");




 while (income < MIN_INCOME || income > MAX_INCOME)
 {
    printf("\nEnter your monthly NET income: $");
    scanf("%lf" , &income);

    if (income > MAX_INCOME)
    {
       printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
    }
    if (income < MIN_INCOME)
    {
	printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
    }

 }
 
 

 while (itemCount < MIN_ITEMS || itemCount > MAX_ITEMS)
 {
    printf("\nHow many wish list items do you want to forecast?: ");
    scanf("%d" , &itemCount);
    
    if (itemCount < MIN_ITEMS || itemCount > MAX_ITEMS)
    {
	printf("ERROR: List is restricted to between 1 and 10 items.\n");
    }
    
 }
for ( i = 1; i <= itemCount; i++)
{
     printf("\nItem-%d Details:" , i);
     do
     {
     printf("\n   Item cost: $");
     scanf("%lf", &itemCost[i]);
	 if (itemCost[i] < MIN_COST)
	  {
	    printf("      ERROR: Cost must be at least $100.00");
	  }
    
      }while (itemCost[i] < MIN_COST);

    
     while (priority [i] > 3 || priority [i] < 1)
     {
     printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
     scanf("%d" , &priority[i]);

	 if (priority[i] > 3 || priority[i] < 1)
	  {
	printf("      ERROR: Value must be between 1 and 3\n");
	  }
     }

     while (!(financed[i] == 'n' || financed[i] == 'y'))
    
     {
	printf("   Does this item have financing options? [y/n]: ");
	scanf(" %c" , &financed[i]);
	if (!(financed[i] == 'n' || financed[i] == 'y'))
	{
	    printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
	}
	
     }
   }

 printf("\nItem Priority Financed        Cost\n");
 printf("---- -------- -------- -----------\n");
 for (i = 1; i <= itemCount; i++)
 {
    printf("%3d  %5d    %5c    %11.2lf\n", i , priority[i],financed[i], itemCost[i]);
 }
 for (i = 1 ; i <= itemCount; i++)
 {
 totalCosts += itemCost[i];
 if (i == itemCount)
 {
 printf("---- -------- -------- -----------\n");
 printf("                      $%11.2lf\n\n", totalCosts);
 printf("Best of luck in all your future endeavours!\n");
}
}
    return 0;
}
