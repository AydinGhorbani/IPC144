/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Aydin Ghorbani
Student ID#: 124170226
Email      : aghorbani8@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{

int apple =-1 , orange =-1   , pears =-1 , tommato =-1  , cabbange = -1 ;
int aswer = 0;
int difftence =0 , flag =0 ;
int productcuntter = 0;


do
{
printf("Grocery Shopping\n"
       "================\n");

     while (apple <= -1)
     {
       printf("How many APPLES do you need? : ");
       scanf("%d" , &apple);
       if (apple < 0)
       {
          printf("ERROR: Value must be 0 or more.\n");
       }
     }
     

     while (orange <= -1)
     {
        printf("\nHow many ORANGES do you need? : ");
        scanf("%d" , &orange);

        if (orange < 0)
        {
            printf("ERROR: Value must be 0 or more.");
        }
         
     }

          while (pears <= -1)
     {
        printf("\nHow many PEARS do you need? : ");
        scanf("%d" , &pears);

        if (pears < 0)
        {
        printf("ERROR: Value must be 0 or more.");
        }

     }

          while (tommato <= -1)
     {
        printf("\nHow many TOMATOES do you need? : ");
        scanf("%d" , &tommato);

        if (tommato < 0)
        {
           printf("ERROR: Value must be 0 or more.");
        }
     }

          while (cabbange <= -1)
     {
        printf("\nHow many CABBAGES do you need? : ");
        scanf("%d" , &cabbange);

        if (cabbange < 0)
        {        
        printf("ERROR: Value must be 0 or more.");
        }

     }
    

   if (aswer != -1)
   {
    printf("\n--------------------------\n"
           "Time to pick the products!\n"
           "--------------------------\n\n");
   }       
 
 if (apple != 0)
 {
    
 
 
     do
     {
       
     printf("Pick some APPLES... how many did you pick? : ");
     scanf("%d" , &productcuntter);

     if (productcuntter > apple)
     {
        difftence = apple - difftence;
        printf("You picked too many... only %d more APPLE(S) are needed.\n" , difftence);
        
     }
     else if (productcuntter <= 0)
     {
       printf("ERROR: You must pick at least 1!\n");
     }

     else if(((0 < productcuntter) && (apple < productcuntter)) || (flag != 0))
     {
        flag = productcuntter + flag;
        printf("Great, that's the apples done!\n\n");
     }

      else if (((productcuntter > 0) && (apple < productcuntter)) || (flag == 0))
     {
        difftence= productcuntter ;
        flag = productcuntter + flag;
        printf("Looks like we still need some APPLES...\n");

     }


     
     }while (flag != apple);

 }
    
     
 difftence =0 , flag =0 ;
 productcuntter = 0;

 if (orange != 0)
 {

     do
     {
       
     printf("Pick some ORANGES... how many did you pick? : ");
     scanf("%d" , &productcuntter);

     if (productcuntter > orange)
     {
        difftence = orange - difftence;
        printf("You picked too many... only %d more ORANGE(S) are needed.\n" , difftence);
        
     }
     else if (productcuntter <= 0)
     {
       printf("ERROR: You must pick at least 1!\n");
     }

     else if(((0 < productcuntter) && (orange < productcuntter)) || (flag != 0))
     {
        flag = productcuntter + flag;
        printf("Great, that's the oranges done!\n\n");
     }

      else if (((productcuntter > 0) && (orange < productcuntter)) || (flag == 0))
     {
        difftence= productcuntter ;
        flag = productcuntter + flag;
        printf("Looks like we still need some ORANGES...\n");

     }
       }while (flag != orange);
 }

 difftence =0 , flag =0 ;
 productcuntter = 0;

if (pears != 0)
{


     do
     {
       
     printf("Pick some PEARS... how many did you pick? : ");
     scanf("%d" , &productcuntter);

     if (productcuntter > pears)
     {
        difftence = pears - difftence;
        printf("You picked too many... only %d more PEAR(S) are needed.\n" , difftence);
        
     }
     else if (productcuntter <= 0)
     {
       printf("ERROR: You must pick at least 1!\n");
     }

     else if(((0 < productcuntter) && (pears < productcuntter)) || (flag != 0))
     {
        flag = productcuntter + flag;
        printf("Great, that's the pears done!\n\n");
     }

      else if (((productcuntter > 0) && (pears < productcuntter)) || (flag == 0))
     {
        difftence= productcuntter ;
        flag = productcuntter + flag;
        printf("Looks like we still need some PEARS...\n");

     }


     
     }while (flag != pears);

}

 difftence =0 , flag =0 ;
 productcuntter = 0;

 if (tommato != 0)
 {
    

 

     do
     {
       
     printf("Pick some TOMATOES... how many did you pick? : ");
     scanf("%d" , &productcuntter);

     if (productcuntter > tommato)
     {
        difftence = tommato - difftence;
        printf("You picked too many... only %d more TOMATO(ES) are needed.\n" , difftence);
        
     }
     else if (productcuntter <= 0)
     {
       printf("ERROR: You must pick at least 1!\n");
     }

     else if(((0 < productcuntter) && (tommato < productcuntter)) || (flag != 0))
     {
        flag = productcuntter + flag;
        printf("Great, that's the tomatoes done!\n");
     }

      else if (((productcuntter > 0) && (pears < productcuntter)) || (flag == 0))
     {
        difftence= productcuntter ;
        flag = productcuntter + flag;
        printf("Looks like we still need some TOMATOES...\n");

     }
       }while (flag != tommato);

 }


 difftence =0 , flag =0 ;
 productcuntter = 0;

 if (cabbange != 0)
 {
    
 
 

     do
     {
       
     printf("Pick some CABBAGES... how many did you pick? : ");
     scanf("%d" , &productcuntter);

     if (productcuntter > cabbange)
     {
        difftence = cabbange - difftence;
        printf("You picked too many... only %d more CABBAGE(S) are needed.\n" , difftence);
        
     }
     else if (productcuntter <= 0)
     {
       printf("ERROR: You must pick at least 1!\n");
     }

     else if(((0 < productcuntter) && (cabbange < productcuntter)) || (flag != 0))
     {
        flag = productcuntter + flag;
        printf("Great, that's the cabbages done!\n");
     }

      else if (((productcuntter > 0) && (cabbange < productcuntter)) || (flag == 0))
     {
        difftence= productcuntter ;
        flag = productcuntter + flag;
        printf("Looks like we still need some CABBAGES...\n");

     }
       }while (flag != cabbange);

 }

 printf("\nAll the items are picked!\n\n");

 apple =-1 , orange =-1   , pears =-1 , tommato =-1  , cabbange = -1 ;
 printf("Do another shopping? (0=NO): ");
 scanf("%d" , &aswer);
 printf("\n");

     
     

}while (aswer != 0);


 printf("Your tasks are done for today - enjoy your free time!\n");



 
    return 0;
}