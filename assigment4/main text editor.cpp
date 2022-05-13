#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include "textEditor.h"
#include "main text editor.h"

using namespace std;



int main()
{
	char fileName[100];
	int choice = 0;
	bool con = true;
	fstream yourFile;
	cout << "----------- WILLCOME TO R-M-S Text Editor :) -----------\n\n\n\n";
	cout << "Please enter the name of the file: ";
	cin >> fileName;

	yourFile.open(fileName);
	if (yourFile.fail()) {
		cout << "This is a new file. I created it for you :)\n\n\n";
		fstream yourFile;
		yourFile.open(fileName, ios::app | ios::in);




	}
	else {
		cout << "The file is already exist.\n\n\n";
		yourFile.close();

	}




	string newtext;

	while (con == true) {
		textEditor f1;
		f1.displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;


		if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9 || choice == 10 || choice == 11 || choice == 12 || choice == 13 || choice == 14 || choice == 15 || choice == 16) {


			switch (choice) {
			case 1: {

				yourFile.open(fileName, ios::app);


				system("cls");
				cout << "Enter the new text:";

				while (newtext == "") {
					getline(cin, newtext);
					yourFile << newtext << "\n";

				}
				yourFile.close();
				system("cls");
				cout << "file has been updated succeessfully!\n\n";

				break;



			}
			case 2: {

				fstream yourFile;
				yourFile.open(fileName, ios::in);
				string textt;
				system("cls");
				getline(yourFile, textt);
				while (yourFile) {
					cout << textt << "\n";
					getline(yourFile, textt);
					cout << "\n\n\n\n";

				}
				yourFile.close();
				break;
			}

			case 3: {
				ofstream yourFile(fileName);
				system("cls");

				cout << "The file is empty now!\n\n";
				break;
			}

			case 4: {

				char c;
				string temp1;
				string temp = fileName;
				ifstream fin;
				ofstream fout;
				fin.open(temp.c_str(), ios::binary);
				temp = temp + " Encrypted file";
				fout.open(temp.c_str(), ios::binary);

				while (!fin.eof()) {

					fin >> noskipws >> c;
					int tempo = (c + 1);
					fout << (char)tempo;
				}
				fin.close();
				fout.close();

				system("cls");
				cout << "New encrypted file has been updated succeessfully!\n\n";

				break;
			}
			case 5: {

				char c;
				string temp = fileName;
				ifstream fin;
				ofstream fout;
				fin.open(temp.c_str(), ios::binary);
				temp = temp + " Decrypted file";
				fout.open(temp.c_str(), ios::binary);


				while (!fin.eof()) {

					fin >> noskipws >> c;
					int tempo = (c - 1);
					fout << (char)tempo;
				}
				fin.close();
				fout.close();

				system("cls");
				cout << "New decrypted file has been updated succeessfully!\n\n";

				break;
			}
			case 6: {

				char file2[100], ch;

				fstream yourFile, fileTwo;
				cout << "Enter the name of the file that you want to merge with: ";
				cin >> file2;
				yourFile.open(fileName, ios::app);
				fileTwo.open(file2, ios::in);

				if (!fileTwo) {

					cout << "An error has occurred while opening file! ";
				}
				else {
					while (fileTwo >> noskipws >> ch) {
						yourFile << ch;
					}
					yourFile.close();
					fileTwo.close();

					system("cls");
					cout << "Files have merged successfully.\n\n\n";
					break;
				}
			}
			case 7: {
				fstream yourFile;
				yourFile.open(fileName, ios::in);
				char ch;
				int word = 0;
				yourFile.seekg(0, ios::beg);

				while (yourFile) {
					yourFile.get(ch);
					if (ch == ' ' || ch == '\n')
						word++;
				}
				yourFile.close();
				system("cls");
				cout << "File words = " << word << '\n\n\n\n';


			}

			}//switch bracket




		}// if statement for checking choice  
		else {

			cout << "Wrong input, please choose between the menu !";
		}

	}//while bracket


}// main bracket

