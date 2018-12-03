/***************************************************************
CSCI 240         Program 2     Fall 2018

Programmer: Josh Jackson

Section: 1

Date Due: 9/14/18

Purpose: This program calculates the number of singles and total
         number of bases for a baseball player. It also calculates
         slugging percentage.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// Declare Variables
	int intHits, intSingles, intDoubles, intTriples, intHomeRuns, intTotal, intAtBats;	//Program 2 requires all variables except slugging percentage to be integers
	float fltSlugPercent;
	
	//Allow User to input Data
	cout << "Enter number of hits: ";
	cin >> intHits;
	cout << "Enter number of doubles: ";
	cin >> intDoubles;
	cout << "Enter number of triples: ";
	cin >> intTriples;
	cout << "Enter number of home runs: ";
	cin >> intHomeRuns;
	cout << "Enter number of times at bat: ";
	cin >> intAtBats;
	
	//Calculate number of Singles and Total Bases
	intSingles = intHits - (intDoubles + intTriples + intHomeRuns);
	intTotal = intSingles + (2*intDoubles) + (3*intTriples) + (4*intHomeRuns);
	
	//Calculate Slugging Percentage
	fltSlugPercent = intTotal / (float)intAtBats;			//Typecasting:			(datatype)variable	makes a variable behave as the specified type for this instance
	
	//Output
	cout << fixed											//Fixed Flag:			 fixed				makes setprecision set the exact number of digits
		 << setprecision(3); 								//Set Decimal Precision: setprecision(n)	limits output to n places of precision (decimal does not count)
	
	cout << endl << endl
		 << "Singles: " << intSingles << "	Doubles: " << intDoubles << "	Triples: " << intTriples << "	Home Runs: " << intHomeRuns << endl << endl 
		 << "Total Bases: \t\t" << intTotal << endl
		 << "Slugging Percentage: \t" << fltSlugPercent;
	
	return 0;
}
