/*/////////////////////////////////////////////////////////////////////////
			  Workshop - #2 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double SmallPrice = 0;
    double MediumPrice = 0;
    double LargePrice = 0;
    double SubTotal = 0;
    double Total = 0;
    double TotalTax = 0;
    int Quantity = 0;

    printf("Set Shirt Prices\n"
	   "================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf" , &SmallPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf" , &MediumPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf" , &LargePrice);
    printf("\n");
    printf("Shirt Store Price List\n"
	   "======================\n");
    printf("SMALL  : $%.2lf\n", SmallPrice);
    printf("MEDIUM : $%.2lf\n", MediumPrice);
    printf("LARGE  : $%.2lf\n", LargePrice);
    printf("\n");          
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &Quantity);
    printf("\n");

    SubTotal = (SmallPrice * Quantity);
    TotalTax = (SubTotal * TAX * 100 + 0.16);
    Total = ((TotalTax / 100) + SubTotal);

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n" , Quantity);
    printf("Sub-total: $%.4lf\n" , SubTotal);
    printf("Taxes    : $%8.4lf\n" , TotalTax / 100 );
    printf("Total    : $%.4lf\n" , Total);


    return 0;
}
