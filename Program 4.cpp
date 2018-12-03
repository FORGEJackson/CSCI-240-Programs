/***************************************************************
CSCI 240         Program 4	     Fall 2018

Programmer: Antario Mama, Josh Jackson

Section: 1

Date Due: 9/28/18

Purpose: Simluate a game of Craps
		 1st roll: 7, 11 wins; 2, 3, 12 loses
		 next rolls: repeating 1st roll wins; 7 loses
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//Declare Constants
const int CRAPS_WIN = 11;

const int CRAPS_LOSE1 = 2;
const int CRAPS_LOSE2 = 3;
const int CRAPS_LOSE3 = 12;

const int CRAPS_ALT = 7;

int main() {
	//Declare Variables
	int intPoint, intDice1, intDice2, intTotal;
	char chaContinue;
	
	//Loop to repeat game
	
		srand(22);		//Testing only
//		srand(time());	//This allows actual gameplay

		//Game
	do {
		intDice1 = (rand() % 6) + 1;
		intDice2 = (rand() % 6) + 1;
		intTotal = intDice1 + intDice2;
		
		cout << "Player rolled: " << intDice1 << " + " << intDice2 << " = " << intTotal << endl << endl;
	
/*
		if Total = 7 or 11, player wins
		
		else if Total = 2 3 or 12, player loses
		
		else 
			loop until player gets their original number or 7
			
			if player get their original number, player wins
			else
			if player gets 7, player loses
*/
		if ( intTotal == 7 || intTotal == 11) {
			cout << "You won!" << endl;
		}
		else if ( intTotal == 2 || intTotal == 3 || intTotal == 12) {
			cout<< "Craps! You lost!";
		}
		else {
			intPoint = intTotal;
			
			do {
				intDice1 = (rand() % 6) + 1;
				intDice2 = (rand() % 6) + 1;
				intTotal = intDice1 + intDice2;
		
				cout << "Player rolled: " << intDice1 << " + " << intDice2 << " = " << intTotal << endl;
			} while (intTotal != intPoint && intTotal != CRAPS_ALT);
			
			if (intTotal == intPoint) {
				cout << endl << "You rolled your point! You won!";
			}
			else {
				cout << endl << "You seven'd out and lost!";
			}
		}
		
		//Repeats game
		cout << endl << "Enter (y) to continue: ";
		cin >> chaContinue;
		cout << endl << endl;
		
	} while (chaContinue == 'y' || chaContinue == 'Y');

	return 0;
}
