/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Aydin Ghorrbani
Student ID#: 124170226
Email      : aghobani8@mysenaca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define MAX_GRAMS 64
#define CONVERSION_RATE 2.20462
#define KG_TO_G 1000.0

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    double weight;
    int cal;
};

struct ReportData
{
    int sku;
    double price;
    int cal;
    double weightLb;
    double weightKg;
    int weightG;
    double totalServ;
    double costPerServ;
    double costCalPerServ;
    
};



// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intNum);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doubleNum);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int Num);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int itemNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int disSku ,const int disCal,const double* disPrice,const double* disWeight);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lb , double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lb , int* grams);

// 10. convert lbs: kg / g
void convertLbs(const double* lb , double* kg , int* grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeG , const int totalGrams , double* finalResult);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* servNum , double* costPerServ);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price , const double* totalCal , double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo allInfo);



// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void ReportData(const struct ReportData raw , const int cheap);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo cheapestFood);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
