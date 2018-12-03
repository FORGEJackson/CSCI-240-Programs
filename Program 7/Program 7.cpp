/***************************************************************
CSCI 240         Program 7	     Fall 2018

Programmer: Antario Mama, Josh Jackson

Section: 1

Date Due: 11/2/18

Purpose: Process a file of data that contains the winners of the 
		Stanley Cup between 1927 and 2018. It will allow the user 
		of the program to name a hockey team and learn how many 
		times that the team has won the Stanley Cup.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>

const int ARRAYSIZE = 100;

using namespace std;

int funBuildArray(string[]);
int funNumberWins(string[], int, string);
void funDisplayYears(string[], int, string);
void funDisplayTeams(string[], int);
	
int main() {
//Declare variables and arrays
	string	strWinnerList[ARRAYSIZE],
			strCurrentTeam;
			
	int intTeamCount = funBuildArray(strWinnerList),
		intWinCount;
	
//Get user input
	cout << "There are " << intTeamCount << " entries in the input file" << endl << "Team?\t"; 
	getline(cin, strCurrentTeam);
	
//Calculate number of wins
	intWinCount = funNumberWins(strWinnerList, intTeamCount, strCurrentTeam);
	
//Output
	if (strCurrentTeam == "Not Awarded") {
		cout << "The Stanley Cup was not awarded " << intWinCount << " time(s)";
	} else {
		cout << "The " << strCurrentTeam << " won " << intWinCount << " time(s)";
	}
	
	cout << endl << endl;
	
	funDisplayYears(strWinnerList, intTeamCount, strCurrentTeam);
	
	cout << endl << endl;
	
	funDisplayTeams(strWinnerList, intTeamCount);
	
	return 0;
}

int funBuildArray(string strBuildArray[ARRAYSIZE]) {
/***************************************************************
Function: funBuildArray

Use: Opens and reads a file, stores each line in an array

Arguments: One Array

Returns: Number of teams added to array
***************************************************************/

//Open file and Declare Variables
	fstream fInput;
	
	fInput.open("stanley_cup.txt");
	
	int intCount = 0;
	
//Put each line of the file into an array
	for (int i = 0; i < ARRAYSIZE; i++) {
		getline(fInput, strBuildArray[i]);
		
		if (strBuildArray[i] != "") {	//If string is not empty, increase counter by one
			intCount++;
		}
	}
	
//Close File
	fInput.close();
	
	return intCount;
}

int funNumberWins(string strTeamList[ARRAYSIZE], int intNumTeams, string strName) {
/***************************************************************
Function: funNumberWins

USe: Counts how many times a string appears in an array

Arguments: Array containing winning teams, Integer containing number of teams in the array, string with the team to check

Returns: Number of times a given team has won
***************************************************************/

//Declare Variables
	int intWinCount = 0;
	
//Count number of times a team is in the array
	for (int i = 0; i < intNumTeams; i++) {
		if (strTeamList[i] == strName) {
			intWinCount++;
		}
	}
	
	return intWinCount++;
}

void funDisplayYears(string strTeamList[ARRAYSIZE], int intNumTeams, string strName) {
/***************************************************************
Function funDisplayYears

Use: Displays each year a team won, 6 years per line

Arguments: Array containing winning teams, Integer containing number of teams in the array, string with the team to check

Returns: nothing
***************************************************************/

//Declare Variables
	int intNumCount = 0;
	
//Output each year a given team won
	for (int i = 0; i < intNumTeams; i++) {
		if (strTeamList[i] == strName) {
			
			cout << i + 1927 << "\t";	//Adds array index to starting year to get that index's year
			
			intNumCount++;
			
			if (intNumCount == 6) {		//Every 6th year also outputs a new line
				cout << endl;
				intNumCount = 0;
			}
			
		}
	}
}

void funDisplayTeams(string strTeamList[ARRAYSIZE], int intNumTeams) {
/***************************************************************
Function: funDisplayTeams

USe: Displays each year along with the team that won

Arguments: Array containing winning teams, Integer containing number of teams in the array

Returns: Nothing
***************************************************************/

//Output
	cout << "All of the teams that have won the Stanley Cup" << endl;
	
	for (int i = 0; i <= 46; i++) {
		cout << "-";
	}
	
	cout << endl;

	for (int i = 0; i < intNumTeams; i++) {
		cout << 1927 + i << "\t" << strTeamList[i] << endl;		//Adds array index to starting year to get that index's year
	}
}
