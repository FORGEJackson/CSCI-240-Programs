/***************************************************************
CSCI 240         Program 8	     Fall 2018

Programmer: Antario Mama, Josh Jackson

Section: 1

Date Due: 11/20/18

Purpose: implement and use the methods for a class called Die.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class Die {
	private:
		static const int NUMSIDES;
		int intValue;
	public:
		Die();
		void Roll();
		int getValue();
		string Draw(int);
};

//Declare constant for Die Class
const int Die::NUMSIDES = 6;

//Declare Constants
const int CRAPS_WIN = 11;

const int CRAPS_LOSE1 = 2;
const int CRAPS_LOSE2 = 3;
const int CRAPS_LOSE3 = 12;

const int CRAPS_ALT = 7;


int main() {
	//Initializes random number
	srand(35);
//	srand(time(0));
	
	//Declare Variables and Create Objects
	int intPoint,
		intTotal;
	char chaContinue;
	Die objDice1,
		objDice2;
		
	//Game
	do {
		//Roll each die
		objDice1.Roll();
		objDice2.Roll();
			
		//Sum the dice values
		intTotal = objDice1.getValue() + objDice2.getValue();
		
		cout << "Player rolled: " /*<< objDice1.getValue() << " + " << objDice2.getValue() << " = "*/ << intTotal << endl;
	
		//Draw each dice
		for (int i = 1; i <= 5; i++) {
			cout << objDice1.Draw(i) << "\t" << objDice2.Draw(i) << endl;
		}
		
		cout << endl;
		
/*
		if Total = 7 or 11, player wins
		
		else if Total = 2 3 or 12, player loses
		
		else 
			loop until player gets their original number or 7
			
			if player get their original number, player wins
			else
			if player gets 7, player loses
*/

		if ( intTotal == CRAPS_ALT || intTotal == CRAPS_WIN) {
			cout << "You won!" << endl;
		}
		else if ( intTotal == CRAPS_LOSE1 || intTotal == CRAPS_LOSE2 || intTotal == CRAPS_LOSE3) {
			cout << "Craps! You lost!" << endl;
		}
		else {
			intPoint = intTotal;
			
			cout << "The point is " << intPoint << endl << endl;
			
			do {
				objDice1.Roll();
				objDice2.Roll();
				intTotal = objDice1.getValue() + objDice2.getValue();
		
				cout << "Player rolled: " /*<< objDice1.getValue() << " + " << objDice2.getValue() << " = "*/ << intTotal << endl;
				
				//Draw each dice
				for (int i = 1; i <= 5; i++) {
					cout << objDice1.Draw(i) << "\t" << objDice2.Draw(i) << endl;
				}
				
				cout << endl;
				
			} while (intTotal != intPoint && intTotal != CRAPS_ALT);
			
			if (intTotal == intPoint) {
				cout << "You rolled your point! You won!" << endl;
			}
			else {
				cout << "You seven'd out and lost!" << endl;
			}
		}
		
		//Repeats game
		cout << endl << "Enter (y) to continue: ";
		cin >> chaContinue;
		cout << endl << endl;
		
	} while (tolower(chaContinue) == 'y');
	
	return 0;
}

Die::Die() {
/*
method: 	Die
use:		Creates and rolls the die
arguments: 	None
returns:	Nothing
notes:		Constructor
*/
	Die::Roll();
}

void Die::Roll() {
/*
method:		Roll
use:		Rolls the die
arguments:	None
returns:	Nothing
*/
	intValue = (rand() % NUMSIDES) + 1;
}

int Die::getValue() {
/*
method:		getValue
use:		Returns die value
arguments:	None
returns:	Die value
*/
	return intValue;
}

string Die::Draw(int intLineNumber) {
/*
method:		Draw
use:		Draws one line of a die
arguments:	Which line to draw
returns:	String containing line to draw
notes:		Uses line number and die value to select line to draw
*/
	string strLineDrawn;
	
	if (intLineNumber == 1 || intLineNumber == 5) {
		strLineDrawn = " ----- ";
	}
	else if (intLineNumber == 2) {
		if (intValue == 1) {
			strLineDrawn = "|     |";
		}
		else if (intValue == 2 || intValue == 3) {
			strLineDrawn = "| O   |";
		}
		else {
			strLineDrawn = "| O O |";
		}
	}
	else if (intLineNumber == 3) {
		if (intValue == 1 || intValue == 3 || intValue == 5) {
			strLineDrawn = "|  O  |";
		}
		else if (intValue == 6) {
			strLineDrawn = "| O O |";
		}
		else {
			strLineDrawn = "|     |";
		}
	}
	else if (intLineNumber == 4) {
		if (intValue == 1) {
			strLineDrawn = "|     |";
		}
		else if (intValue == 2 || intValue == 3) {
			strLineDrawn = "|   O |";
		}
		else {
			strLineDrawn = "| O O |";
		}
	}
	
	return strLineDrawn;
}
