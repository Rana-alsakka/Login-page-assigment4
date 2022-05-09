#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include "textEditor.h"

using namespace std;



int main()
{
	char fileName[100];
	int choice;
	fstream yourFile;
	cout << "----------- WILLCOME TO R-M-S Text Editor :) -----------\n\n\n\n";
	cout << "Please enter the name of the file: ";
	cin >> fileName;

	yourFile.open(fileName);
	if (yourFile.fail()) {
		cout << "This is a new file. I created it for you :)\n\n\n";
		textEditor f1;
		f1.displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		

		

	}  
	else {
		cout << "The file is already exist.\n\n\n";
		textEditor f1;
		f1.displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		yourFile.close();

	}
	if (choice == 1) {
		fstream yourFile;
		yourFile.open(fileName, ios::app);
		if (yourFile.is_open()) {

			string newtext;
			cout << "Enter the new text:";
			while (true) {

				if (getline(cin, newtext )) {
					yourFile << newtext << endl;
				}
				
			}
			yourFile.close();
		}
	}
	
}

