#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<regex>
#include "login page.h"
using namespace std;

int main() { int choice;
    cout << " \t\t\t ------------------------login page------------------------\n";
    cout
            << "1.login" << endl
            << "2.register" << endl
            << "3.forgot password" << endl
            << "4.exit"<< endl;
    cin >> choice;
       if( choice == 1) {
           loginManger app;
           app.login();
           cin.get();
       }
       else if (choice ==2) {
           //  registration();
           loginManger app;
           string username;
           app.saveFile(username,"user.data",3);
           string p_line;
           cin>> p_line;
           app.saveFile(p_line,"passwords.data", 2);

       }
       else if (choice ==3) {
           //  forgot();
       }
       else if (choice ==4) {
           cout << " thank you ";
            }
        else
            cout << " \t\t\t please select from the options above";
            main();
    }
