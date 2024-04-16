/*
Gardner, Jason
Project 5
Rock, Paper, Scissors(Page 281, Exercise 11)
October 30, 2019
*/

#include <iostream> // Console Input/Output
#include <cstdlib> // Random Number Generation
#include <ctime> // System Time

// Flowgorithm Code Removed in Non and Enumerated Builds.  No type conversions or math used.

using namespace std; // Namespace

enum ThrownHand { rock, paper, scissors };  // Globally Declared Enumerator for Possible Hand "Throws" in "Rock, Paper, Scissors" (rock, paper, scissors)
enum GameStatus { win, lose, draw }; // Globally Declared Enumerator for Possible Game States (win, lose, draw)

/*
Headers - Preconstruction
returnValueType functionName(inputValueType inputVariable)
Note: Suggestions in online resources that enums were properly utilized "enum GlobalType SpecificItem"
returnValueType functionName(inputValueType inputVariable)
*/
GameStatus decideWhoWins(ThrownHand deciderComputer, ThrownHand deciderPlayer);
ThrownHand getComputersChoice();
ThrownHand getPlayersChoice();

int main() {
	// Declare Variables
	string continuePlaying;
	ThrownHand computersHand;
	ThrownHand playersHand;
	GameStatus status;

	srand(time(0)); //Seed random number generation for pseduorandom rand()
	continuePlaying = "y";
	//  Not entirely necessary, but added a “Welcome” and “Overview” of the game here.
	//  Wanted the rules in here as a comment for troubleshooting and figured the user could see them.
	cout << "Welcome to Perpetual Rock, Paper, Scissors!" << endl;
	cout << "Paper wraps rock.  Rock smashes scissors.  Scissors cut paper." << endl;

	// Loop the Game until user enters "n" or "N" after non-draw round.
	while (continuePlaying != "n" || continuePlaying == "N") {
		// Set computersHand via getComputersChoice
		computersHand = getComputersChoice();
		// Set playersHand via getPlayersHand
		playersHand = getPlayersChoice();
		// Set status via decideWhoWins
		status = decideWhoWins(computersHand, playersHand);
		// Bypass Player Decision to Play Again for draw status
		if (status != draw) {
			switch (status) {
			case win:
				cout << "You win!" << endl;
				break;
			case lose:
				cout << "You lose!" << endl;
				break;
			};
			cout << "Continue Playing (Enter 'n' to Exit)? ";
			cin >> continuePlaying;
		}
		else {
			cout << "There was a draw!  Tie breaker!" << endl;
		}
	}
	return 0;
}

GameStatus decideWhoWins(ThrownHand deciderComputer, ThrownHand deciderPlayer) {
	// Declare Variable(s)
	GameStatus statusDecision;

	// Initialize Variable(s)
	// Decision Tree for Game Status.  Computer hand vs. player.
	switch (deciderComputer) {
	case rock:
		cout << "The computer chose rock." << endl;
		switch (deciderPlayer) {
		case scissors:
			statusDecision = lose;
			break;
		case paper:
			statusDecision = win;
			break;
		case rock:
			statusDecision = draw;
			break;
		}
		break;
	case paper:
		cout << "The computer chose paper." << endl;
		switch (deciderPlayer) {
		case rock:
			statusDecision = lose;
			break;
		case scissors:
			statusDecision = win;
			break;
		case paper:
			statusDecision = draw;
			break;
		}
		break;
	case scissors:
		cout << "The computer chose scissors." << endl;
		switch (deciderPlayer) {
		case paper:
			statusDecision = lose;
			break;
		case rock:
			statusDecision = win;
			break;
		case scissors:
			statusDecision = draw;
			break;
		}
		break;

	}
	// Return statusDecision
	return statusDecision;
}

ThrownHand getComputersChoice() {
	// Declare Variable(s)
	int cChoice;
	ThrownHand cHand;

	// Initialize Variable(s)
	cChoice = 1 + rand() % 3;

	// Integer to ThrownHand
	// Can be done via typecasting ThrownHand(1 + rand()%3)
	// More than one  use of these type conversions and a function would be useful!
	if (cChoice == 1) {
		cHand = rock;
	}
	else if (cChoice == 2) {
		cHand = paper;
	}
	else if (cChoice == 3) {
		cHand = scissors;
	}
	// Return cHand
	return cHand;
}

ThrownHand getPlayersChoice() {
	// Declare Variable(s)
	string pChoice;
	ThrownHand pHand;
	cout << "Please enter your choice ('rock' 'paper' or 'scissors'): ";
	cin >> pChoice;

	// String to ThrownHand
	if (pChoice == "rock") {
		pHand = rock;
	}
	else if (pChoice == "paper") {
		pHand = paper;
	}
	else if (pChoice == "scissors") {
		pHand = scissors;
	}
	// Return pHand
	return pHand;
}