/*/////////////////////////////////////////////////////////////////////////
			  Workshop - #8 (P2)
Full Name  : AYDIN Ghorbani
Student ID#: 124170226
Email      : aghorbani8@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intNum){
	int flag = 1;
	int inputNum = 0;
	while (flag)
	{
		scanf("%d" , &inputNum);
		if (inputNum < 1 )
		{
			printf("ERROR: Enter a positive value: ");
		}
		else if(inputNum>1)
		{
			flag = 0;
			if (intNum !=NULL) {
				*intNum = inputNum;
			}
			
		}
    }
return inputNum;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doubleNum){
	int flag = 1;
	double inputNum = 0.0;
	while (flag)
	{
		scanf("%lf",&inputNum);
		if (inputNum <1)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
			if (doubleNum != NULL) 
			{
				*doubleNum = inputNum;
			}
			return inputNum;
			
		}
    }
	return 0;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int Num){
	printf("Cat Food Cost Analysis\n"
	"======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n"
	   "NOTE: A 'serving' is 64g\n\n" , Num);

}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int itemNum) {
	struct CatFoodInfo foodOfCat = {0};
		printf("Cat Food Product #%d\n"
			   "--------------------\n", itemNum);
		printf("SKU           : ");
		getIntPositive(&foodOfCat.sku);
		printf("PRICE         : $");
		getDoublePositive(&foodOfCat.price);
		printf("WEIGHT (LBS)  : ");
		getDoublePositive(&foodOfCat.weight);
		printf("CALORIES/SERV.: ");
		getIntPositive(&foodOfCat.cal);
		return foodOfCat;
}



// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int disSku ,const int disCal,const double* disWeight,const double* disPrice){
	printf("%07d %10.2lf %10.1lf %8d\n", disSku , *disPrice , *disWeight , disCal);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lb , double* kg){
	double result = 0.0;
    result = *lb / CONVERSION_RATE;
	    if (kg != NULL)
	    {
		*kg = result;
	    }
return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lb , int* grams){
	int result = 0;
	double kg = 0; 
    
	convertLbsKg(lb ,&kg);
	result = kg * KG_TO_G;
    if (grams != NULL)
	{
		*grams = result;
	}
return result;  
}

// 10. convert lbs: kg and g
void convertLbs(const double* lb , double* kg , int* grams){
	convertLbsG(lb , grams);
    convertLbsKg(lb , kg);
}
// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeG , const int totalGrams , double* finalResult){
	double result = 0.0;

	result = (double)totalGrams / servSizeG;
	if (finalResult != NULL)
	{
		result = *finalResult;
	}
	
return result;

}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* servNum , double* costPerServ){

	double result =0.0;
	result = *price / *servNum;
	if (costPerServ != NULL){
	*costPerServ = result;
	}
	return result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price , const double* totalCal , double* costPerCal){
	double result =0.0;
	result =  *price / *totalCal;
	if (costPerCal != NULL){
	*costPerCal = result;
	}
	return result;
}
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo allInfo){
    struct ReportData localStruct = { 0 };
	double temp = 0;
	localStruct.sku = allInfo.sku;
	localStruct.price = allInfo.price;
	localStruct.weightLb = allInfo.weight;
	localStruct.cal = allInfo.cal;

	localStruct.weightKg = convertLbsKg(&allInfo.weight , NULL);
    localStruct.weightG = convertLbsG(&allInfo.weight , NULL);
    localStruct.totalServ = calculateServings(MAX_GRAMS, localStruct.weightG , NULL);
	temp = localStruct.cal * localStruct.totalServ;
	localStruct.costPerServ = calculateCostPerServing(&localStruct.price , &localStruct.totalServ , NULL);
	localStruct.costCalPerServ = calculateCostPerCal(&localStruct.price , &temp , NULL);
	return localStruct;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", MAX_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void ReportData(const struct ReportData raw , const int cheap){
printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",raw.sku,raw.price,raw.weightLb
,raw.weightKg, raw.weightG, raw.cal, raw.totalServ , raw.costPerServ, raw.costCalPerServ);
	if (cheap != 0)
	{
		printf(" ***");
	}
	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo cheapestFood){
	printf("\nFinal Analysis\n"
		"--------------\n"
		"Based on the comparison data, the PURRR-fect economical option is:\n"
		"SKU:%07d Price: $%.2lf\n\n"
		"Happy shopping!\n", cheapestFood.sku, cheapestFood.price);
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo items[MAX_PRODUCTS] = { {0} };
	struct ReportData data[MAX_PRODUCTS] = { {0} };
	double cheap = 0;
	int cheapholder =0;
	int i = 0;
	openingMessage(MAX_PRODUCTS);
	for (i = 0; i < MAX_PRODUCTS; i++) {
		items[i] = getCatFoodInfo(i + 1);
		printf("\n");
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(items[i].sku, items[i].cal, &items[i].weight, &items[i].price);
	}
	printf("\n");
	displayReportHeader();
	for (i = 0; i < MAX_PRODUCTS; i++) 
	{
		data[i] = calculateReportData(items[i]);
		if (cheap == 0 || data[i].costPerServ < cheap)
		{
			cheap = data[i].costPerServ;
			cheapholder = i;
		}
		
	}
	for (i=0 ;i < MAX_PRODUCTS ; i++)
	{
		if (i == cheapholder) 
		{
			ReportData(data[i], 1);
		}
		else
		{
			ReportData(data[i], 0);
		}
		
	}
	displayFinalAnalysis(items[cheapholder]);
}

	

	

