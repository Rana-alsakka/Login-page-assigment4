#include <iostream>
#include <fstream>
#include<string>
using namespace std;

class loginManger {

    string getFile(const char* login_file) {
        string line;
        fstream file;
        file.open(login_file , ios::in);
        if (file.is_open()) {
            getline(file, line);
        }
        file.close();
        return line;
    }
    void saveFile(string p_text, const char*);
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
                cout <<"hello "<< username<< " you are successfully logged in";
                cin.get();
            } else {
                cout << " wrong username or password , please try again\n\n\n\n\n" << endl;
                login();
            }
        }
    }

private:
        string password = "a";
        string username = "a";
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
           loginManger loginMangerObj;
           loginMangerObj.login();
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