#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Headers
string toString(double);
int toInt(string);
double toDouble(string);

int main() {
	// // It's fun to have syntax errors in Flowchart software.
	// // Guess I'll learn how it wants us to input array values later, as input into an array is squirrely.
	// //  Attempt #1 declared the array, and inputted intArray[0], intArray[1], intArray[2].  Big nope.
	// // Commas are okay for declaration, but not input.
	// // Declare some inputs
	int intInput0, intInput1, intInput2;
	// AFTER RUN NOTE:  WHILE LARGE INTEGERS WILL PROCESS, THEY WILL ROLL OVER TO NEGATIVE RESULTS.
	// OTHER FUNCTIONS ARE FINE, BUT intProduct IS PROBLEMATICAL.
	// intAverage SHOULD BE NOTED AS WELL, AS ONLY THE SPECIFIC TEST CASE CAME OUT WITH A INTEGER.

	// // Acquire some inputs
	// // Look, they start at 0, so it's a pretend array?
	// //  You can't iterate over them, so, nope.
	cout << "Enter THREE INTEGERS.  Press Enter/Return After Each." << endl;
	// AFTER RUN NOTE: CRLF==ENDL!  STRING ISSUES (FOR ME) ARE IN FLOWGARITHM, BUT APPEARS TO WORK FINE IN C++ (std:string)
	cin >> intInput0;
	cin >> intInput1;
	cin >> intInput2;

	// // Declare some variables to hold output values
	int intSum, intAverage, intProduct, intMin, intMax;

	// // Do the simple math and store to sum, average, and product variables.
	intSum = intInput0 + intInput1 + intInput2;
	intAverage = (double)intSum / 3;
	intProduct = intInput0 * intInput1 * intInput2;

	// // Initialize maximum and minimum values
	// // Counter (n/i) WAS initialized in loop, but, array thing.
	// // Come back and repair this after figuring out how to do this.
	// // for (n=0, n<=2, n++) if {intInput[n](compare)intMin/Max{intInput=intMin/Max}}
	intMax = intInput0;
	intMin = intInput0;

	// // While tempting, don't initialize to each other for economy.
	// // Remember reading about them genuinely linking to a value in memory, so if you garbage collected something "unused" they'd suddenly be valueless?  That thing.  Probably.
	// // Maybe that was Java, but it seems like something C would do.  Manual garbage collection.
	// // This section is why we were looping.  But it's two times each here.  So, it's okay.
	// //  Very linear at the moment.
	if (intMax < intInput1) {
		intMax = intInput1;
	}
	if (intMax < intInput2) {
		intMax = intInput2;
	}

	// //Now write it all again, but backwards.  And twice.
	// //  Not the biggest fan of how intInput looks (t+I blurs together), but I'm going to pretend it works for the rest of my life, because I've committed to it.
	if (intMin > intInput1) {
		intMin = intInput1;
	}
	if (intMin > intInput2) {
		intMin = intInput2;
	}

	// // Another issue here I'm unfamiliar with the solution for in C++.  Figure out how to put strings together, because outputting "Aard"+"vark" isn't workable (here) and this is frustrating.
	// // Decided it wouldn't kill me to try to manually construct a string here until I figure out how this is connected in Flowgorithm.
	// Look up after completing how cout is called, because should be able to construct strings.
	cout << "Three Input Integers were: " << endl;
	cout << intInput0 << endl;
	cout << intInput1 << endl;
	cout << intInput2 << endl;
	cout << "Sum is: ";
	cout << intSum << endl;
	cout << "Average is: ";
	cout << intAverage << endl;
	cout << "Product is: ";
	cout << intProduct << endl;
	cout << "Maximum Value is: ";
	cout << intMax << endl;
	cout << "Minimum Value is: ";
	cout << intMin << endl;
	return 0;
}

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
