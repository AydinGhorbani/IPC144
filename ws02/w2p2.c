/*/////////////////////////////////////////////////////////////////////////
			  Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double SmallPrice = 0 , MediumPrice = 0 , LargePrice = 0;
    int PatSubTotal , SalSubTotal = 0, TomSubTotal =0;
    int QtyPat = 0 , QtySal = 0 , QtyTom = 0;
    int  PatTax = 0, SalTax = 0 , TomTax = 0;
    int toonie = 0 , loonie = 0 , quarter = 0 , dim = 0 , nickle = 0 , cent = 0;
    int balance = 0 , coinQty = 0;
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
    scanf("%d" , &QtyPat);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d" , &QtyTom);
    printf("\n");
     printf("Sally's shirt size is '%c'\n", salSize); 
    printf("Number of shirts Sally is buying: ");
    scanf("%d" , &QtySal);
    printf("\n");
    
     PatSubTotal =(int)(((QtyPat * SmallPrice) + 0.005) * 100.0);
    PatTax = (TAX * PatSubTotal) + 0.5;

     SalSubTotal= (int)(((QtySal * MediumPrice) + 0.005) *100.0);
    SalTax = (TAX * SalSubTotal) + 0.5;

    TomSubTotal =(int)(((QtyTom * LargePrice) + 0.005) * 100.0);
    TomTax = (TAX * TomSubTotal) + 0.5;
   
    

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n"
	   "-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n" ,patSize , SmallPrice, QtyPat ,PatSubTotal/100.0 , PatTax/100.0 , (PatTax + PatSubTotal)/100.0);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n" ,salSize , MediumPrice, QtySal, SalSubTotal/100.0 , SalTax/100.0 , (SalSubTotal +SalTax)/100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n" ,tomSize , LargePrice ,QtyTom ,TomSubTotal/100.0 , TomTax/100.0 , (TomTax+TomSubTotal)/100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", (TomSubTotal+SalSubTotal+PatSubTotal)/100.0 , (PatTax+SalTax+TomTax)/100.0 , (PatTax+SalTax+TomTax+TomSubTotal+SalSubTotal+PatSubTotal)/100.0);

    printf("Daily retail sales represented by coins\n"
	   "=======================================\n\n");
    
    printf("Sales EXCLUDING tax\n"
	   "Coin     Qty   Balance\n"
	   "-------- --- ---------\n");
    int total=(PatSubTotal+SalSubTotal+TomSubTotal);
    balance = total;
    printf("%22.4lf\n" ,balance/100.0);

    balance = total % 200;
    coinQty = total / 200;
    printf("Toonies  %3d %9.4lf\n" , coinQty , balance / 100.0);

    loonie = balance / 100;
    balance = balance % 100;
    printf("Loonies    %d    %.4lf\n", loonie, balance / 100.0);

    quarter = balance / 25;
    balance = balance % 25;
    printf("Quarters   %d    %.4lf\n", quarter, balance / 100.0);

    dim = balance / 10;
    balance = balance % 10;
    printf("Dimes      %d    %.4lf\n", dim, balance / 100.0);

    nickle = balance / 5;
    balance = balance % 5;
    printf("Nickels    %d    %.4lf\n", nickle, balance / 100.0);

    cent = balance;
    balance = balance % 1;
    printf("Pennies    %d    %.4lf\n\n", cent, balance / 100.0);
    printf("Average cost/shirt: $%.4lf\n\n",(total+0.005)/100.0/13);

    
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    balance = PatSubTotal + TomSubTotal + SalSubTotal + SalTax + PatTax + TomTax;
    printf("              %8.4lf\n", balance / 100.0);
    toonie = balance / 200;
    balance = balance % 200;
    printf("Toonies  %d    %.4lf\n", toonie, balance / 100.0);
    loonie = balance / 100;
    balance = balance % 100;
    printf("Loonies    %d    %.4lf\n", loonie, balance / 100.0);
    quarter = balance / 25;
    balance = balance % 25;
    printf("Quarters   %d    %.4lf\n", quarter, balance / 100.0);
    dim = balance / 10;
    balance = balance % 10;
    printf("Dimes      %d    %.4lf\n", dim, balance / 100.0);
    nickle = balance / 5;
    balance = balance % 5;
    printf("Nickels    %d    %.4lf\n", nickle, balance / 100.0);
    cent = balance;
    balance = balance % 1;
    printf("Pennies    %d    %.4lf\n\n", cent, balance / 100.0);
    printf("Average cost/shirt: $%.4lf\n\n", (PatSubTotal + TomSubTotal + SalSubTotal + SalTax + PatTax + TomTax+ 0.005) / 100.0 / 13);
return 0;
}
