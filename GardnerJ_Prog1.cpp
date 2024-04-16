// Program 1
// Gardner, Jason
// Calculate Stock Purchase/Sales Metrics (Chapter 2, Exercise 10)
// September 10, 2019
// No additional assumptions necessary.
// Declare Variables

// These are included libraries.
#include <iostream>   // Input/Output Stream
#include <sstream>    // String Stream
#include <string>     //String
#include <cstdlib>    //C Standard Library
#include <cmath>      //C Math

using namespace std;

// Type Conversion - Flowgorithm
// Headers
string toString(double);
int toInt(string);
double toDouble(string);

int main() {
	double stockShares, stockPurchasePrice, stockCommissionPercentage, stockSellPrice, stockAmountInvested, stockAmountReturn, stockCommissionBuy, stockCommissionSell, stockProfitLoss;

	// In the past, I would do camelCase with the variable type.  realShares, realPurchasePrice, etc.  This still makes sense to me but doesn't seem to be implemented in practice.
	// This remains an issue to me, because, while in a real situation, stockShares aren't integers, in this case, they are.  I like variables with typing.
	// Initialize/Assign Variables
	// Given Purchase Information (Shares 1000, Price 32.87, Commission 2%)
	stockShares = 1000;
	stockCommissionPercentage = 0.02;
	stockPurchasePrice = 32.87;

	// Number of shares times the price for the total paid.
	stockAmountInvested = stockShares * stockPurchasePrice;

	// Paid comission is 2% of the total invested.
	stockCommissionBuy = stockAmountInvested * stockCommissionPercentage;

	// Given Sale Information (Shares 1000, Price 33.92, Commission 2%)
	// stockShares and stockCommissionPercentage REMAINED THE SAME
	stockSellPrice = 33.92;

	// Number of shares times the price for the total return.
	stockAmountReturn = stockShares * stockSellPrice;

	// Again, paid commission is 2% of the total return.
	stockCommissionSell = stockAmountReturn * stockCommissionPercentage;

	// Profit would be the return, minus what was invested in the first place.  Commission needs to come out too.
	// Key that problem states these profits INCLUDE deduction of commissions on both ends!
	stockProfitLoss = stockAmountReturn - stockAmountInvested - (stockCommissionBuy + stockCommissionSell);

	// Output!  String construction here is done via & in Flowgorithm and << delimiting in code for the strings of text between quotations and output variables stockAmountInvested, stockCommissionBuy, stockAmountReturn, stockCommissionSell, and stockProfitLoss.
	cout << "Joe paid $" << stockAmountInvested << " for the 1000 shares in Acme Software Inc. at $32.87. His commission on this purchase was $" << stockCommissionBuy << ". He later sold 1000 shares in Acme Software Inc. at $33.92 for a return of $" << stockAmountReturn << ".  His paid commission on this sale was $" << stockCommissionSell << ". His profit/loss from this transaction was $" << stockProfitLoss << ".";
	return 0;
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
