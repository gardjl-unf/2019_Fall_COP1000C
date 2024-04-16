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

/*
Headers - Preconstruction
returnValueType functionName(inputValueType inputVariable)
*/
string decideWhoWins(int deciderComputer, string deciderPlayer);
int getComputersChoice();
string getPlayersChoice();

int main() {
	string continuePlaying;
	int computersChoice;
	string playersChoice;
	string winLoseDraw;

	// Initialize Variable(s)
	// enum ThrownHand { rock, paper, scissors };  // Globally Declared Enumerator for Possible Hand "Throws" in "Rock, Paper, Scissors" (rock, paper, scissors)
	// enum GameStatus { win, lose, draw }; // Globally Declared Enumerator for Possible Game States (win, lose, draw)
	srand(time(0)); //Seed random number generation for pseduorandom rand()
	continuePlaying = "y";

	// Menu to explain what the game is and the rules.
	cout << "Welcome to Perpetual Rock, Paper, Scissors!" << endl;
	cout << "Paper wraps rock.  Rock smashes scissors.  Scissors cut paper." << endl;

	// Loop to continue playing the game.
	// There is a bypass of the decision in the "draw" game state to rerun.
	while (continuePlaying != "n" || continuePlaying == "N") {

		// Set computersChoice via getComputersChoice
		computersChoice = getComputersChoice();

		// Set playersChoice via getPlayersChoice
		playersChoice = getPlayersChoice();

		// Set winLoseDraw via decideWhoWins
		winLoseDraw = decideWhoWins(computersChoice, playersChoice);

		// Decision Structure
		// If there is a win/loss, print result and ask to continue.
		// If there is a draw, print result and continue without asking.
		if (winLoseDraw != "draw") {

			// Result
			cout << "You " << winLoseDraw << "!" << endl;

			// Continue playing?
			cout << "Continue Playing (Enter 'n' to Exit)? ";
			cin >> continuePlaying;
		}
		else {

			// Result
			cout << "There was a draw!" << endl;
		}
	}
	return 0;
}

string decideWhoWins(int deciderComputer, string deciderPlayer) {
	// Declare Variable(s)
	string winningStatus;

	// Initialize Variable(s)
	// Repaired Flowgorithm's Decision to use a structure that ended "End If End If End If End If End If"
	if (deciderComputer == 1) {
		cout << "The computer chose rock." << endl;
		if (deciderPlayer == "scissors") {
			winningStatus = "lose";
		}
		else if (deciderPlayer == "paper") {
			winningStatus = "win";
		}
		else {
			winningStatus = "draw";
		}

	}
	else if (deciderComputer == 2) {
		cout << "The computer chose paper." << endl;
		if (deciderPlayer == "rock") {
			winningStatus = "lose";
		}
		else if (deciderPlayer == "scissors") {
			winningStatus = "win";
		}
		else {
			winningStatus = "draw";
		}
	}
	else if (deciderComputer == 3) {
		cout << "The computer chose scissors." << endl;
		if (deciderPlayer == "paper") {
			winningStatus = "lose";
		}
		else if (deciderPlayer == "rock") {
			winningStatus = "win";
		}
		else {
			winningStatus = "draw";
		}
	}

	// Return winningStatus
	return winningStatus;
}

int getComputersChoice() {
	// Declare Variable(s)
	int cChoice;

	// Initialize Variable(s)
	// Computer choice is random number between 1-3
	cChoice = 1 + rand() % 3;

	// Return cChoice
	return cChoice;
}

string getPlayersChoice() {
	// Declare Variable(s)
	string pChoice;

	// Initialize Variable(s)
	cout << "Please enter your choice ('rock' 'paper' or 'scissors'):";
	cin >> pChoice;

	// Return pChoice
	return pChoice;
}