// Program 2
// Gardner, Jason
// Calculate Sales Taxes for a Given Sales Figure (Page 126, Exercise 10)
// September 17, 2019
// Provided Test Data: $30,000 in Monthly Sales

// Preprocessor Directives.
#include <iostream>   // Input/Output Stream - Console Input/Output (cin/cout)

// These aren't necessary, but Flowgorithm added them.
#include <sstream>    // String Stream
#include <string>     //String
#include <cstdlib>    //C Standard Library
#include <cmath>      //C Math


using namespace std;

// Global Constants
const float countyTaxRate = 0.02;
const float stateTaxRate = 0.04;

// Headers
// Type Conversion - Flowgorithm
string toString(double);
int toInt(string);
double toDouble(string);
// Functions - Preconstruction
// returnValueType functionName(inputValueType inputVariable);
double calcCountyTax(double sales);
double calcStateTax(double sales);
void displayOutputs(double sales, double ctTax, double stTax);
double getMonthlySales();

int main() {

	// Declare Variables
	double monthlySales, countyTax, stateTax;

	// Initialize Variables
	// Call getMonthlySales() and set monthlySales to the user input from there.
	monthlySales = getMonthlySales();

	// Send monthlySales to calcCountyTax to get countyTax back.
	countyTax = calcCountyTax(monthlySales);

	// Send monthlySales to calcStateTax to get stateTax back.
	stateTax = calcStateTax(monthlySales);

	// Send monthlySales, countyTax, and stateTax to displayOutputs to... DISPLAY OUTPUTS.
	// The instructor data outputs these figures inside the functions as they are entered, with displayTaxes as a final function.
	// Ideally, I would have liked to have input, calculation (in this case, tax rate could have been passed to a single tax calculator), and output.
	displayOutputs(monthlySales, countyTax, stateTax);
	return 0;
}

double calcCountyTax(double sales) {

	// Declare Variables
	double totalCountyTax;

	// Initialize Variables
	totalCountyTax = sales * countyTaxRate;

	// Return Variable

	return totalCountyTax;
}

double calcStateTax(double sales) {

	// Declare Variables
	double totalStateTax;

	// Initialize Variables
	totalStateTax = sales * stateTaxRate;

	// Return Variable

	return totalStateTax;
}

void displayOutputs(double sales, double ctTax, double stTax) {
	// Declare Variables
	double totalTaxCollected;

	// Initialize Variables
	totalTaxCollected = ctTax + stTax;

	// Display Requested Output
	cout << "Total sales were $" << sales << "." << endl;
	cout << "County taxes were $" << ctTax << "." << endl;
	cout << "State taxes were $" << stTax << "." << endl;
	cout << "Total taxes were $" << totalTaxCollected << ".";
}

double getMonthlySales() {
	// Declare Variables
	double totalSales;

	// Request User Input
	cout << "Please input total sales for the month as a dollar amount (ex: 30000.00):";
	cin >> totalSales;

	// Return Variable

	return totalSales;
}

// Type Conversion - Flowgorithm (Functions)
// The following implements type conversion functions.
string toString(double value) { //int also
	stringstream temp;
	temp << value;
	return temp.str();
}

int toInt(string text) {
	return atoi(text.c_str());
}

double toDouble(string text) {
	return atof(text.c_str());
}
