#include <iostream>
#include <fstream>
#include<string>
#include<regex>
using namespace std;

class loginManger {

    int encrypt(int p_letter){
        return p_letter + 3;
    }
    int decrypt (int p_letter){
        return p_letter - 3;
    };


public:
    loginManger() {
        accessGranted = 0;
    }

    void login() {
        cout << "please enter your username and password" << endl << " username" << endl;
        cin >> usernameAttempt;
        username = getFile("user.data");
        if (usernameAttempt == username) {
            cout << " password : ";
            cin >> passwordAttempt;
            password = getFile("passwords.data");
            if (passwordAttempt == password) {
                cout <<"hello "<< username<< " you are successfully logged in \n\n\n\n\n\n";
                cin.get();
            } else {
                cout << " wrong username or password , please try again\n\n\n\n\n" << endl;
                login();
            }
        }
    }

    void saveFile(string p_line, const char* p_fileName)
    {
        fstream file;
        file.open(p_fileName, ios::out);
        for (int i = 0; i < p_line.length(); i++)
        {
            file << encrypt(p_line[i]);
            file << "\n";
        }
        file<< "0";
        file.close();
    }

    string getFile(const char* p_fileName) {
        string line;
        fstream file;
        int eChar;
        file.open(p_fileName, ios::in);
        while (1) {
           file>> eChar;
            if (eChar == 0) {
                file.close();
                return line;
            }
            line += (char)decrypt(eChar);
        }
    }

private:
        string password ;
        string username ;
        string usernameAttempt;
        string passwordAttempt;
        bool accessGranted;
    };
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
           app.saveFile("myname" , "user.data");
           app.saveFile("lol233", "passwords.data");
           app.login();
           cin.get();
       }
       else if (choice ==2) {
           //  registration();
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
 void passCheck (){

}
void username_check(){

}
void email_check(){

}