/***************************************************************
CSCI 240         Program 6	     Fall 2018

Programmer: Antario Mama, Josh Jackson

Section: 1

Date Due: 10/26/18

Purpose: Decode messages from "A Christmas Story"
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;
	
char funUpperToLower(char);
char funLowerToUpper(char);
char funPunctToDigit(char);
char funDigitToPunct(char);
char funOther(char);

int main() {
	
	//Open file and declare variables
	ifstream fInput;		
	char chaCurrent;
	int intCharacters = 0,
		intAlphaChar = 0,
		intDigit = 0,
		intPunct = 0,
		intOther = 0;
	
	fInput.open("encoded_quotes.txt");
	
	//Read file and select functions
	if (!fInput.fail()) {	//Checks if the file opened properly
		while (fInput) {
			fInput >> chaCurrent;
			
			if (fInput.eof()) {	//Stops loop at end of file
				break;
			}
			
			intCharacters++;
			
			if (isalpha(chaCurrent)) {	//Checks for upper or lower alphabetic characters
				intAlphaChar++;
				isupper(chaCurrent) ? chaCurrent = funUpperToLower(chaCurrent) : chaCurrent = funLowerToUpper(chaCurrent);
			}
			else if (ispunct(chaCurrent)) {	//Checks for punctuation
				intDigit++;
				chaCurrent = funPunctToDigit(chaCurrent);
			}
			else if (isdigit(chaCurrent)) {	//Checks for digits
				intPunct++;
				chaCurrent = funDigitToPunct(chaCurrent);
			}
			else if (chaCurrent == 20 || chaCurrent == 22) {	//Checks for ACII 20 and 22
				intOther++;
				chaCurrent = funOther(chaCurrent);
			}											//If a character is unexpected don't change it
			
			cout << chaCurrent;
		}
		
		//Output for extra credit #1
		cout << endl << endl << "The file contains " << intCharacters << " characters." << endl;
		
		cout << "\tAlphabetic:\t" << setw(5) << right << intAlphaChar << endl
			 << "\tDigit:\t\t" << setw(5) << right << intDigit << endl
			 << "\tPunctuation:\t" << setw(5) << right << intPunct << endl
			 << "\tWhitespace:\t" << setw(5) << right << intOther << endl;
	}
	else {
		cout << "File failed to open";
		exit(-1);
	}
	
	fInput.close();
	
	//Output for extra credit #2
	cout << endl << endl << "A Christmas Story";
	
	return 0;
}

char funUpperToLower(char character) {
/***************************************************************
Function: funUpperToLower

Use: Decodes upper case letters to their lower case equivalent

Arguments: one character variable containing an upper case letter

Returns: one decoded lower case letter
***************************************************************/
	if (character == 'A') {
		character = 'z';
	}
	else {
		character = tolower(character) - 1;
	}
	
	return character;
}

char funLowerToUpper(char character) {
/***************************************************************
Function: funLowerToUpper

Use: Decodes lower case letters to their upper case equivalent

Arguments: one character variable containing an lower case letter

Returns: one decoded upper case letter
***************************************************************/
	if (character == 'z') {
		character = 'A';
	}
	else {
		character = toupper(character) + 1;
	}
	
	return character;
}

char funPunctToDigit(char character) {
/***************************************************************
Function: funPunctToDigit

Use: Decodes punctuation characters to their digit equivalent

Arguments: one character variable containing a punctuation character

Returns: one decoded digit
***************************************************************/
	switch(character) {
		case ')':
			character = '0';
			break;
		case '!':
			character = '1';
			break;
		case '@':
			character = '2';
			break;
		case '#':
			character = '3';
			break;
		case '$':
			character = '4';
			break;
		case '%':
			character = '5';
			break;
		case '^':
			character = '6';
			break;
		case '&':
			character = '7';
			break;
		case '*':
			character = '8';
			break;
		case '(':
			character = '9';
			break;
	}
	
	return character;
}

char funDigitToPunct(char character) {
/***************************************************************
Function: funDigitToPunct

Use: Decodes digits to their punctuation equivalent

Arguments: one character variable containing a digit

Returns: one decoded punctuation character
***************************************************************/
	switch (character) {
		case '9':
			character = ',';
			break;
		case '8':
			character = '\"';
			break;
		case '7':
			character = '!';
			break;
		case '6':
			character = ';';
			break;
		case '5':
			character = '?';
			break;
		case '4':
			character = '\'';
			break;
		case '3':
			character = '(';
			break;
		case '2':
			character = ')';
			break;
		case '1':
			character = '.';
			break;
		case '0':
			character = '-';
			break;
	}
		
		return character;
}

char funOther (char character) {
/***************************************************************
Function: funUpperToLower

Use: Decodes ascii values 22 & 20

Arguments: one character variable containing ascii 22 or ascii 20

Returns: a space or a newline character
***************************************************************/
	if (character == 22) {
		character = ' ';
	}
	else {
		character = '\n';
	}
	
	return character;
}
