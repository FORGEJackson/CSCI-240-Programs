/***************************************************************
CSCI 240         Program 9	     Fall 2018

Programmer: Antario Mama, Josh Jackson

Section: 1

Date Due: 11/30/18

Purpose: 
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

const int WIDTH = 3;
const int HEIGHT = 3;

class magicSquare {
	private:
		int square[WIDTH][HEIGHT];
	public:
		magicSquare();
		void fillSquare(string);
		void printSquare();
		bool isMagic();
};
	
int main() {
	magicSquare square1;
	
	square1.fillSquare("loshu_puzzle1.txt");
	
	square1.printSquare();
}

magicSquare::magicSquare() {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			square[i][j] = 0;
		}
	}
}

void magicSquare::fillSquare(string strFileName) {
	//Open File, Use file to fill array, Close File
	ifstream fInput;
	int intCurrent;
	
	fInput.open(strFileName.c_str());
	
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			fInput >> intCurrent;
			square[i][j] = intCurrent;
		}
	}
}

void magicSquare::printSquare() {	
	for (int i = 0; i < WIDTH; i++) {
		cout << "+---+---+---+" << endl << "|";
		
		for (int j = 0; j < HEIGHT; j++) {
			cout << " " << square[i][j] << " "<< "|";
		}
		
		cout << endl;
	}
	
	cout << "+---+---+---+" << endl;
}

bool magicSquare::isMagic() {
	bool magic = true;
	int intCurrentValue = 1;
	int row1 = 0,
		row2 = 0,
		row3 = 0,
		col1 = 0,
		col2 = 0,
		col3 = 0,
		dia1 = 0,
		dia2 = 0;
	
	while (magic && intCurrentValue <= 9) {
		magic = false;
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				if (square[i][j] == intCurrentValue) {
					magic = true;
				}
			}
		}
		
		intCurrentValue++;
	}
	
	if (magic) {
		for (int i = 0; i < WIDTH; i++) {
			row1 += square[0][i];
			row2 += square[1][i];
			row3 += square[2][i];
			col1 += square[i][0];
			col2 += square[i][1];
			col3 += square[i][2];
			dia1 += square[i][i];
			dia2 += square[2-i][i];
		}
		
		if (row1 == row2 && row2 == row3 && row3 == col1 && col1 == col2 && col2 == col3 && col3 == dia1 && dia1 == dia2) {
			magic = true;
		}
		else {
			magic = false;
		}
	}
	
	return magic;
}
