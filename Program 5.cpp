/***************************************************************
CSCI 240         Program 5	     Fall 2018

Programmer: Antario Mama, Josh Jackson

Section: 1

Date Due: 10/12/18

Purpose: Generate 10 random values using a for, while, and do while loop
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN = 50;		//Minimum value to be generated
const int RANGE = 51;	//Range of Values, Ex. 50 to 100 = 51
const int NUMCOUNT = 10;	//Number of values to generate

//Create PUBLIC variables so every function can use them
	//Create temporary counters for each loop
	int	int100Count = 0,
		int90sCount = 0,
		int80sCount = 0,
		int70sCount = 0,
		int60sCount = 0,
		int50sCount = 0;
	//Create permanent counters
	int	int100CountP = 0,
		int90sCountP = 0,
		int80sCountP = 0,
		int70sCountP = 0,
		int60sCountP = 0,
		int50sCountP = 0;

int clearTemp();		//Resets temporary counters to 0
int incrementTemp(int);	//Increments temporary counters
int saveTemp();			//Saves temporary counters to permanent counters
int outputTemp();		//Outputs temporary counters

int main() {
	//Initialize random numbers
	srand(1);
		
	//Stores current random number
	int intCurrent;
		
	int i;
	
	//FOR LOOP
	cout << "Set 1" << endl;
	for (i = 1; i <= NUMCOUNT; i++) {
		intCurrent = (rand() % RANGE) + MIN;	//Generates a random number from 50 to 100
		
		incrementTemp(intCurrent);		
		
		cout << setw(6) << intCurrent;		
	}
	outputTemp();
	saveTemp();
	clearTemp();
	
	cout << endl << endl << endl;
	
	//WHILE LOOP
	i = 1;
	while (i <= NUMCOUNT) {
		intCurrent = (rand() % RANGE) + MIN;	//Generates a random number from 50 to 100
		
		incrementTemp(intCurrent);		
		
		cout << setw(6) << intCurrent;
		
		i++;
	}
	outputTemp();
	saveTemp();
	clearTemp();
	
	cout << endl << endl << endl;
	
	//DO WHILE LOOP
	i = 1;
	do {
		intCurrent = (rand() % RANGE) + MIN;	//Generates a random number from 50 to 100
		
		incrementTemp(intCurrent);		
		
		cout << setw(6) << intCurrent;
		
		i++;
	} while (i <= NUMCOUNT);
	outputTemp();
	saveTemp();
	clearTemp();
	
	cout << endl << endl << endl;
	
	//EXTRA CREDIT OUTPUT
	cout << "Overall Counts" << endl;
	cout << "100 count :" << setw(4) << int100CountP << "  ";
	for (i = 1; i <= int100CountP; i++) {	//For loop outputs a * for each count of 100
		cout << "*";
	}
	cout << endl << "90s count :" << setw(4) << int90sCountP << "  ";
	for (i = 1; i <= int90sCountP; i++) {
		cout << "*";
	}
	cout << endl << "80s count :" << setw(4) << int80sCountP << "  ";
	for (i = 1; i <= int80sCountP; i++) {
		cout << "*";
	}
	cout << endl << "70s count :" << setw(4) << int70sCountP << "  ";
	for (i = 1; i <= int70sCountP; i++) {
		cout << "*";
	}
	cout << endl << "60s count :" << setw(4) << int60sCountP << "  ";
	for (i = 1; i <= int60sCountP; i++) {
		cout << "*";
	}
	cout << endl << "50s count :" << setw(4) << int50sCountP << "  ";
	for (i = 1; i <= int50sCountP; i++) {
		cout << "*";
	}
	
	return 0;
}

//Clears temporary counter values
int clearTemp() {
	int100Count = 0;
	int90sCount = 0;
	int80sCount = 0;
	int70sCount = 0;
	int60sCount = 0;
	int50sCount = 0;
	
	return 0;
}

//Increments temporary counter values
int incrementTemp(int intCurrent) {
	if (intCurrent < 60) {
		int50sCount++;
	}
	else if (intCurrent < 70) {
		int60sCount++;
	}
	else if (intCurrent < 80) {
		int70sCount++;
	}
	else if (intCurrent < 90) {
		int80sCount++;
	}
	else if (intCurrent < 100) {
		int90sCount++;
	}
	else {
		int100Count++;
	}
	
	return 0;
}

//Saves temporary counter values as permanent values
int saveTemp() {
	int100CountP += int100Count,
	int90sCountP += int90sCount,
	int80sCountP += int80sCount,
	int70sCountP += int70sCount,
	int60sCountP += int60sCount,
	int50sCountP += int50sCount;
	
	return 0;
}

//Outputs temporary counter values
int outputTemp() {
	cout << endl << "100 count:" << setw(3) << int100Count 
		 << "   90s count:" << setw(3) << int90sCount 
		 << "   80s count:" << setw(3) << int80sCount 
		 << "   70s count:" << setw(3) << int70sCount 
		 << "   60s count:" << setw(3) << int60sCount 
		 << "   50s count:" << setw(3) << int50sCount;
	
	return 0;
}
