// Program 3
// Gardner, Jason
// Calculate BMI (Page 177, Exercise 10)
// Height Test Data 68”

// Global Constants
const int BMI_FACTOR = 703;
const float MASS_LOWER_LIMIT = 18.5;
const float MASS_UPPER_LIMIT = 25.0;

//Preprocessor Directives
#include <iostream>    // Input/Output Stream - Console Input/Output (cin/cout)
#include <sstream>     // String Stream
#include <string>      //String
#include <cstdlib>     //C Standard Library
#include <cmath>       //C Math (pow [Powers] used in this program)

//Namespace
using namespace std;

// Headers
// Functions - Preconstruction
// returnValueType functionName(inputValueType inputVariable)
// Type Conversion - Flowgorithm
string toString(double);
int toInt(string);
double toDouble(string);
// My Functions - Non-Flowgorithm
double getHeight();
double getWeight();
double setMass(double localVarWeight, double localVarHeight);
string setOverUnder(double localVarMass);
void showBMI(double localVarMass, string localVarHealth);

int main() {
	// Declare Variable(s)
	double bMI, weight, height;
	string healthStatus;

	// Assign Variables
	// Acquire Weight/Height via Inputs in the Functions
	weight = getWeight();
	height = getHeight();

	// Calculate BMI in the Function
	bMI = setMass(weight, height);

	// Turn BMI into an Adjective in the Function
	healthStatus = setOverUnder(bMI);

	// Call Output Function
	showBMI(bMI, healthStatus);
	return 0;
}

double getHeight() {
	// Declare Variable(s)
	double totalHeight;

	// Ask for height in glorious imperialist inches
	cout << "Please enter height in inches (in.): ";
	cin >> totalHeight;

	// Return totalHeight to Main

	return totalHeight;
}

double getWeight() {
	// Declare Variable(s)
	double totalWeight;

	// Ask for height in glorious imperialist pounds
	cout << "Please enter weight in pounds (lbs.): ";
	cin >> totalWeight;

	// Return totalWeight to Main

	return totalWeight;
}

double setMass(double localVarWeight, double localVarHeight) {
	// Declare Variable(s)
	double totalMass;

	// BMI Calculation:
	// "(weight times 703)divided by height squared"
	totalMass = localVarWeight * BMI_FACTOR / pow(localVarHeight, 2);

	// Return totalMass to Main

	return totalMass;
}

string setOverUnder(double localVarMass) {
	// Declare Variable(s)
	// Below is rewritten a bit to not use nested if statements and instead use an if-elseif-else structure!
	string wellBeing;

	if (localVarMass < MASS_LOWER_LIMIT) {

		// If mass>max OVERWEIGHT
		wellBeing = "underweight";
	}
	else if (localVarMass > MASS_UPPER_LIMIT) {

		// else if mass<min UNDERWEIGHT
		wellBeing = "overweight";
		}
	else {

		// else OPTIMAL
		wellBeing = "optimal";
	}

	// Return wellBeing to Main

	return wellBeing;
}

void showBMI(double localVarMass, string localVarHealth) {
	// Display requested outputs
	cout << "BMI is " << localVarMass << " which is " << localVarHealth << ".";
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
