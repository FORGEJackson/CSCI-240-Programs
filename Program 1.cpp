/***************************************************************
CSCI 240         Program 1     Fall 2018

Programmer: Josh Jackson

Section: 1

Date Due: 9/7/18

Purpose: This program calculates the number of singles and total
         number of bases for a baseball player.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// Declare Variables
	int intHits, intSingles, intDoubles, intTriples, intHomeRuns, intTotal;
	
	//Allow User to input Data
	cout << "Enter number of hits: ";
	cin >> intHits;
	cout << "Enter number of doubles: ";
	cin >> intDoubles;
	cout << "Enter number of triples: ";
	cin >> intTriples;
	cout << "Enter number of home runs: ";
	cin >> intHomeRuns;
	
	//Calculate number of Singles and Total Bases
	intSingles = intHits - (intDoubles + intTriples + intHomeRuns);
	intTotal = intSingles + (2*intDoubles) + (3*intTriples) + (4*intHomeRuns);
	
	//Output
	cout << "Singles: " << intSingles << "	Doubles: " << intDoubles << "	Triples: " << intTriples << "	Home Runs: " << intHomeRuns << endl << "Total Bases: " << intTotal; 
	
	return 0;
}
