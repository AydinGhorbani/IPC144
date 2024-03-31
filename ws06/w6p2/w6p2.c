/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Aydin Ghorbani
Student ID#: 124170227
Email      : aghorbani8@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ITEMS 10
#define MIN_ITEMS 1

int main(void)                                             //int finder is for finding
{                                                          // 'y' in the array
int i = 0 , itemCount = 0 , selection = 1 , year = 0 , month = 0 , finder = 1 , filetrPriority = 0;   
const double MIN_INCOME = 500.00 , MAX_INCOME = 400000.00 , MIN_COST = 100.0 ;   
double income = 0.0 , totalCosts = 0.0 , costByPrty = 0.0;

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
 printf("                      $%11.2lf\n", totalCosts);

}
}

while (selection != 0)
{
 printf("\nHow do you want to forecast your wish list?\n"
        " 1. All items (no filter)\n"
        " 2. By priority\n"
        " 0. Quit/Exit\n");
 printf("Selection: ");
 scanf("%d" ,&selection);

 if (selection >= 3 || selection < 0)
 {
    printf("\nERROR: Invalid menu selection.\n");
 }
 
    if (selection == 1)
    {
    year= totalCosts/income/12;
    month = (((totalCosts/income))/12 - year) *12 + 0.5;
    printf("\n====================================================\n"
           "Filter:   All items\n");
    printf("Amount:   $%1.2lf\n", totalCosts);
    printf("Forecast: %d years, %d months\n",year , month);
    i = 0;
       while (financed[i] != '\0') 
       {
        if (priority[i] == filetrPriority || financed[i] == 'y') 
        {
            finder = 1;
        }
        i++;
       }

    if (finder == 1) 
    {
        printf("NOTE: Financing options are available on some items.\n"
               "      You can likely reduce the estimated months.");
        i = 0;
    }
        printf("\n====================================================\n");
        year = 0 , month = 0 ;
    }
 
    if (selection == 2)
    {

        printf("\nWhat priority do you want to filter by? [1-3]: ");
        scanf("%d" , &filetrPriority);
         
        if (filetrPriority == 1)
        {
            printf("\n====================================================\n"
                   "Filter:   by priority (1)\n");
            for ( i = 0; i < MAX_ITEMS; i++)
            {
                if (priority[i] == 1)
                {
                    costByPrty += itemCost[i]; 
                }
                    
            }

            year= costByPrty/income/12;
            month = (((costByPrty/income))/12 - year) *12 + 0.5;

            printf("Amount:   $%.2lf\n", costByPrty);
            printf("Forecast: %d years, %d months\n",year , month);
             i = 0;
             while (financed[i] != '\0') 
            {
                if (priority[i] == filetrPriority || financed[i] == 'y') 
                {
                finder = 1;
                }
                i++;
            }

        if (finder == 1) 
        {
        printf("NOTE: Financing options are available on some items.\n"
               "      You can likely reduce the estimated months.");
        i = 0;
        }

            printf("\n====================================================\n");
            year = 0 , month = 0  , costByPrty = 0.0;

        }



         if (filetrPriority == 2)
        {
            printf("\n====================================================\n"
                   "Filter:   by priority (2)\n");
            for ( i = 0; i < MAX_ITEMS; i++)
            {
                if (priority[i] == 2)
                {
                    costByPrty += itemCost[i]; 
                }
                    
            }

            year= costByPrty/income/12;
            month = ((((costByPrty/income))/12 - year)+.05) *12 + 0.5;

            printf("Amount:   $%.2lf\n", costByPrty);
            printf("Forecast: %d years, %d months",year , month);
             i = 0;
             while (financed[i] != '\0') 
            {
                if (priority[i] == filetrPriority || financed[i] == 'y') 
                {
                finder = 1;
                }
                i++;
            }

        if (finder != 1) 
        {
        printf("NOTE: Financing options are available on some items.\n"
               "      You can likely reduce the estimated months.");
        i = 0;
        }


            printf("\n====================================================\n");
            year = 0 , month = 0 , costByPrty = 0.0;

        }

                   

        if (filetrPriority == 3)
        {
            printf("\n====================================================\n"
                   "Filter:   by priority (3)\n");
            for ( i = 0; i < MAX_ITEMS; i++)
            {
                if (priority[i] == 3)
                {
                    costByPrty += itemCost[i]; 
                }
                    
            }

            year= costByPrty/income/12;
            month = (((costByPrty/income))/12 - year) *12 + 0.5;

            printf("Amount:   $%.2lf\n", costByPrty);
            printf("Forecast: %d years, %d months\n",year , month);

             i = 0;
             while (financed[i] != '\0') 
            {
                if (priority[i] == filetrPriority || financed[i] == 'y') 
                {
                finder = 1;
                }
                i++;
            }

        if (finder == 1) 
        {
        printf("NOTE: Financing options are available on some items.\n"
               "      You can likely reduce the estimated months.");
        i = 0;
        }


            printf("\n====================================================\n");
            year = 0 , month = 0 , costByPrty = 0.0;  
        }
             

    }
         
}

printf("\nBest of luck in all your future endeavours!\n");
    




    return 0;
}