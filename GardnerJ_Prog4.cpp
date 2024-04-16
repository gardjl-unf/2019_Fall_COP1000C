// Program 4
// Gardner, Jason
// October 27, 2019
// Calculate Penny-based Logarithmic Income (Page 237, Exercise 9)
// Test Data: 5 Days

//Preprocessor Directives
#include <iostream>    // Input/Output Stream - Console Input/Output (cin/cout)
#include <sstream>     // String Stream
#include <string>      //String
#include <cstdlib>     //C Standard Library
#include <cmath>       //C Math [pow(x,exponent)]

// IO Manipulation Libary on top of what comes from Flowgorithm.
#include <iomanip> //Uncomment from Flowgorithm

// Global Constant in C++, locally in doublePennies for Flowgorithm
const int dollarConversionFactor = 100; //Uncomment from Flowgorithm

// Global Constants for #include <iomanip> formatting
// No “magic numbers”
// Flowgorithm CAN NOT approximate these.
const int dayWidth = 8; //Uncomment from Flowgorithm
const int incomeWidth = 50; //Uncomment from Flowgorithm
// Global Constant to Set Decimal Display to 2 for Money
const int dollarDecimal = 2; //Uncomment from Flowgorithm

using namespace std;

// Headers
// Functions - Preconstruction
// returnValueType functionName(inputValueType inputVariable)
// Type Conversion - Flowgorithm
string toString(double);
int toInt(string);
double toDouble(string);
// My Functions - Non-Flowgorithm
double doublePennies(double doublingDays);
double getDays();
void showSalary(double showDays, double showIncome);

int main() {
	// Declare Variable(s)
	double workingDays;
	double incomeTotal;

	// Sentinel to control main program loop.  Added task so implementation non-ideal
	int sadnessSentinel;

	// Initialize Variable(s)
	sadnessSentinel = 0;
	while (sadnessSentinel != -1) {

		// Acquire number of days worked via function
		workingDays = getDays();

		// Do algorithmic penny math via function
		incomeTotal = doublePennies(workingDays);

		// Call the result function for cash-money
		showSalary(workingDays, incomeTotal);

		// Ask user for sentinel value to end loop (-1) or continue (any number).
		cout << "Please enter any number to run the calculation again (-1 to Quit): ";
		cin >> sadnessSentinel;
	}
	return 0;
}

double doublePennies(double doublingDays) {
	// This particular function varies with the inclusions in written Psuedocode and Source Code.
	// Flowgorithm can't compensate for language-specific libraries or output formatting necessary for this problem.

	// Declare Variable(s)
	double totalDollars;
	int loopCounter;
	double tableIncome;

	// Initialize Variable(s)
	totalDollars = 0;

	// Problem: "Display a Table showing what the salary was for each day,"

	cout << left << setw(dayWidth) << "Day"; //Uncomment from Flowgorithm
	cout << right << setw(incomeWidth) << "Daily Income(USD)" << endl; //Uncomment from Flowgorithm

	//Flowgorithm can't do the following, which will remove scientific notation and display the amounts in currency notation.
	cout << fixed << setprecision(dollarDecimal); //Uncomment from Flowgorithm
	// FOR loop for each day
	for (loopCounter = 1; loopCounter <= doublingDays; loopCounter++) {

		// loopCounter was initialized at 0 to calculate number of pennies from day 1 (2^0).  For this reason, as days progress they will be loopCounter+1.
		// Algorithm for daily pennies is x=2^(y) where y is the loopCounter value.
		// Loop variables set to real values for output
		tableIncome = pow(2, loopCounter - 1) / dollarConversionFactor;

		// Build Table Content (Row)

		cout << left << setw(incomeWidth) << loopCounter; //Uncomment from Flowgorithm
		cout << right << setw(incomeWidth) << "$" << tableIncome << endl; //Uncomment from Flowgorithm
		// Add Current Loop Income to Running Total/Accumulator
		totalDollars = totalDollars + tableIncome;
	}

	// Return totalDollars

	return totalDollars;
}

double getDays() {
	// Declare Variable(s)
	// An integer allows between -2,147,483,647 and 2,147,483,647.
	// However, “Real” used because <iomanip> expressed case-sensitivity in the loop and I doubt templates are in a fundamentals class.
	double inputDays;

	// Ask (nicely) for inputDays
	cout << "Please enter number of days worked: ";

	// Acquire inputDays
	cin >> inputDays;

	// Return inputDays
	return inputDays;
}

void showSalary(double showDays, double showIncome) {
	// Problem: "The output should be displayed in a dollar amount, not the number of pennies."
	// Provide requested output
	cout << "Total pay at the end of " << showDays << " day(s) was $" << showIncome << "." << endl;
}

// Type Conversion - Flowgorithm
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