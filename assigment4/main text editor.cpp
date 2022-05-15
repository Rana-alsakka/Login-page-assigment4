// fci - programming 1 - 2022 - assigment 4
// program name : Text editor
// author 1 : Rana ayman barakat alsakka id : 20210511
// author 2 : sahab mohammed abd el rahman id : 20210158
// author 3 : mohanad hesham id : 20210414
// teaching assistant : s5 - s6
// -------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <Sstream>
#include <Iterator>
#include <Cctype>
#include <stdio.h>
#include "textEditor.h"
#include "main text editor.h"

using namespace std;



int main() {
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
					newtext = "";
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
					ifstream yourFile;
					string word;
					int count = 0;
					yourFile.open(fileName);
					while (!yourFile.eof())
					{
						yourFile >> word;
						count++;
					}
					system("cls");
					cout << "numbers of words in this file is " << count << endl;
					yourFile.close();
					break;

				}
				case 8: {
					char line[100];
					int i, len, count = 0;

					fstream yourFile;
					yourFile.open(fileName, ios::in);

					while (yourFile.eof() == 0) {
						yourFile.getline(line, sizeof(line));
						len = strlen(line);
						for (i = 0; i < len; ++i) {
							++count;

						}

					}
					yourFile.close();
					system("cls");
					cout << "No.of characters in the file are : " << count << "\n\n\n";
					break;
				}
				case 9: {
                       			 ifstream yourFile(fileName);
                        		int ltotal;
                     		        string text;
                    		        if (yourFile.is_open()) {
                            	        while (yourFile.peek() != EOF) {
                               	        getline(yourFile, text);
                             	        ltotal++;
                      	    				  }
                   						     }
                        			yourFile.close();
                      				  system("cls");
                   		     cout << "File lines = " << ltotal << "\n\n\n\n";

                   						     break;
                 							   }
				}
				case 10: {
					string input_file, wordToFind, line;
					while (1)
					{
						cin.ignore();
						int line_Number = 0, found = 0;
						cout << "\nWord to find: "; getline(cin, wordToFind); //getting the word
						ifstream file(fileName); // opening file input stream.
						if (file)
						{
							while (getline(file, line)) //reading file lines
							{
								line_Number++;
								int position = 0;
								for (int i = line.find(wordToFind); i < line.length(); i = i + position)
								{
									position = line.find(wordToFind, i);
									if (position != string::npos)
									{
										system("cls");
										cout << endl << wordToFind << " is at " << line_Number << ":" << position << endl; // print the position of word.
										found = 1;
										break;
									}
									else break;
								}
							}
							file.close();
							if (found == 0)
							{
								system("cls");
								cout << endl << wordToFind << " not in file" << endl;
							}
						}
						else
						{
							cout << endl << input_file << " not found" << endl; //file not available
						}
					}
					return 0; //exiting program.
				}
				case 11: {
					string input_file, wordToFind, line;
					while (1) {
						cin.ignore();
						int count = 0, line_Number = 0;
						cout << "\nWord to find: ";
						getline(cin, wordToFind); //getting the word
						ifstream file(fileName); // opening file input stream.
						if (file) {
							while (getline(file, line)) //reading file lines
							{
								line_Number++;
								int position = 0;
								for (int i = line.find(wordToFind); i < line.length(); i = i + position) {
									position = line.find(wordToFind, i);
									if (position != string::npos) {
										{count++; }
										system("cls");
										cout << " your word has been found " << count << " times" << "in " << line_Number << ":" << position << endl;
										break;
									}
									else break;
								}
							}
							file.close();

						}
					}
				}
				case 12: {
					ifstream yourFile;
					yourFile.open(fileName);
					stringstream textStream;
					textStream << yourFile.rdbuf();
					string text = textStream.str();
					yourFile.close();
					ofstream yourFile2;
					yourFile2.open(fileName, ios::trunc);
					for (int x = 0; x < text.length(); x++) {
						text[x] = toupper(text[x]);
					}
					yourFile2 << text;
					yourFile2.close();
					system("cls");
					cout << "file has been turned to uppercase successffully!\n\n";
					break;

				}
				case 13: {
					ifstream yourFile;
					yourFile.open(fileName);
					stringstream textStream;
					textStream << yourFile.rdbuf();
					string text = textStream.str();
					yourFile.close();
					ofstream yourFile2;
					yourFile2.open(fileName, ios::trunc);
					for (int x = 0; x < text.length(); x++) {
						text[x] = tolower(text[x]);
					}
					yourFile2 << text;
					yourFile2.close();
					system("cls");
					cout << "file has been turned to lowercase successffully!\n\n";
					break;

				}
				case 14: {
					ifstream yourFile;
					yourFile.open(fileName);
					stringstream textStream;
					textStream << yourFile.rdbuf();
					string text = textStream.str();
					yourFile.close();
					ofstream yourFile2;
					yourFile2.open(fileName, ios::trunc);
					while (text != "0") {
						for (int x = 0; x < text.length(); x++) {
							if (x == 0) {
								text[x] = toupper(text[x]);
							}
							else if (text[x - 1] == ' ') {
								text[x] = toupper(text[x]);
							}
						}
						yourFile2 << text;
						yourFile2.close();
						system("cls");
						cout << "file has been turned succeessfully!\n\n";
						break;
					}
				}
				case 15: {
					system("cls");
					cout << "File has been saved successfully.";
					break;
				}

				case 16: {
					con = false;
				}




				}
			}//switch bracket




		}// if statement for checking choice  


	}//while bracket


}// main bracket

