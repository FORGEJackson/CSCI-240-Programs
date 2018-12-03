/***************************************************************
CSCI 240         Program 3     Fall 2018

Programmer: Antario Mama, Josh Jackson

Section: 1

Date Due: 9/21/18

Purpose: calculate a single monthly bill for a customer
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//Declare Variables
	char chaPackage;
	int intMinutes, intExcessMinutesA = 0, intExcessMinutesB = 0;
	double dblPriceA, dblPriceB, dblPriceC;
	
	//User Input 
	cout << "Which package do you have (A, B, or C)? ";
	cin >> chaPackage;
	
	cout << "How many minutes were used this month? ";
	cin >> intMinutes;
	
	//Price Calculation
	if (intMinutes > 300) {
		intExcessMinutesA = intMinutes - 300;
	}
	dblPriceA = 29.99 + (.32 * intExcessMinutesA);
	
	if (intMinutes > 800) { 
		intExcessMinutesB = intMinutes - 750;
	}
	dblPriceB = 49.99 + (.28 * intExcessMinutesB);
	
	dblPriceC = 59.99;
	
	//Output
	cout << fixed << setprecision(2);
	
	if (chaPackage == 'A') {
		cout << "The bill is $" << dblPriceA << endl << endl;
		
		if (dblPriceA > dblPriceB) {
			cout << "Package B would have cost $" << dblPriceB << " and saved you $" << dblPriceA - dblPriceB << endl;
		}
		if (dblPriceA > dblPriceC) {
			cout << "Package C would have cost $" << dblPriceC << " and saved you $" << dblPriceA - dblPriceC;
		}
	}
	else {
		if (chaPackage == 'B') {
			cout << "The bill is $" << dblPriceB << endl << endl;
			
			if (dblPriceB > dblPriceA) {
				cout << "Package A would have cost $" << dblPriceA << " and saved you $" << dblPriceB - dblPriceA << endl;
			}
			if (dblPriceB > dblPriceC) {
				cout << "Package C would have cost $" << dblPriceC << " and saved you $" << dblPriceB - dblPriceC;
			}
		}
		else {
			cout << "The bill is $" << dblPriceC << endl << endl;
			
			if (dblPriceC > dblPriceA) {
				cout << "Package A would have cost $" << dblPriceA << " and saved you $" << dblPriceC - dblPriceA << endl;
			}
			if (dblPriceC > dblPriceB) {
				cout << "Package B would have cost $" << dblPriceB << " and saved you $" << dblPriceC - dblPriceB;
			}
		}
	}
		
	return 0;
}
