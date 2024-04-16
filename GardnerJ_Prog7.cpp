/* 
Gardner, Jason
Project 7
Employee Pay Calculator (Page 350, Exercise 8)
November 17, 2019
Input Assumptions (Validation): 0 < "Hours Worked" < 40 & 7 < "Pay Rate" < 100
*/

#include <iostream> // Console Input/Output

using namespace std; // Namespace

int main() {
	// Declare Variable(s)
	int empId[7] = { 56588, 45201, 78951, 87775, 84512, 13028, 75804 }; //Uncomment from Flowgorithm.  Delete "int empId[7]; line below this and seven assignment lines below "Initialize Variable(s)" comment.
	int hours[7];
	double payRate[7];
	double wages[7];
	int loopCounter;

	// Iterate across array for user inputs.
	for (loopCounter = 0; loopCounter <= 6; loopCounter++) {

		// Initialize array variables before use in input sanitation statements.
		hours[loopCounter] = -1;
		payRate[loopCounter] = -1;

		// 0<hours<40
		while (hours[loopCounter] > 40 || hours[loopCounter] < 0) {
			cout << "Please enter number of hours worked (between 0-40) for the employee with Employee ID: " << empId[loopCounter] << ":";
			cin >> hours[loopCounter];
		}

		// 7<payRate<100
		while (payRate[loopCounter] > 100 || payRate[loopCounter] < 7) {
			cout << "Please enter hourly pay rate (between $7.00 and $100.00) for the employee with Employee ID: " << empId[loopCounter] << ":";
			cin >> payRate[loopCounter];
		}

		// wages=hours*payRate
		wages[loopCounter] = hours[loopCounter] * payRate[loopCounter];
	}

	// Iterate across array for output
	for (loopCounter = 0; loopCounter <= 6; loopCounter++) {
		cout << "Employee with Employee ID: " << empId[loopCounter] << " total wages were: $" << wages[loopCounter] << "." << endl;
	}
	return 0;
}
