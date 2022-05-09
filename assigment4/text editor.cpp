#include <iostream>
#include <cctype>
#include <cstring>
#include "textEditor.h"

using namespace std;

void textEditor::displayMenu()
{
	cout << "1. Add new text to the end of the file \n" <<
		"2. Display the content of the file\n" <<
		"3. Empty the file\n" <<
		"4. Encrypt the file content\n" <<
		"5. Decrypt the file content\n" <<
		"6. Merge another file\n" <<
		"7. Count the number of words in the file\n" <<
		"8. Count the number of characters in the file\n" <<
		"9. Count the number of lines in the file\n" <<
		"10. Search for a word in the file\n" <<
		"11. Count the number of times a word exists in the file\n" <<
		"12. Turn the file content to upper case\n" <<
		"13. Turn the file content to lower case\n" <<
		"14. Turn file content to 1st caps(1st char of each word is capital)\n" <<
		"15. Save\n" <<
		"16. Exit\n";
}

void textEditor::addText()
{
	
}

textEditor::textEditor()
{
	cout << "choose between the menu.\n\n\n";
}

