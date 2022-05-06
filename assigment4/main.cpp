#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;

class loginManger {
public:
    loginManger() {
        accessGranted = 0;
    }

    void login() {
        cout << "please enter your username and password" << endl << " username" << endl;
        cin >> usernameAttempt;

        int userId = checkFile(usernameAttempt, "user.data");
        if (userId != 0) {
            cout << " password : ";
            cin >> passwordAttempt;

            int pswid = checkFile(passwordAttempt, "passwords.data");
            if (userId == pswid) {
                cout << "hello " << usernameAttempt << " you are successfully logged in \n\n\n\n\n\n";
                login();

            } else {
                cout << " wrong username or password , please try again\n\n\n\n\n" << endl;
                int main();
            }
        }
    }

    void addUser(const string username, const string password) {
        if (checkFile(username, "user.data") != 0) {
            cout << " that username is not available" << endl;
            return;
        }
        int id = 1 + getlastID();
        saveFile(username, "user.data", id);
        saveFile(password, "passwords.data", id);
    }

    int getlastID() {
        fstream file;
        file.open("user.data", ios::in);
        file.seekg(0, ios::end);
        if (file.tellg() == -1)
            return 0;
        string s;
        for (int i = -1; s.find("#") == string::npos; i--) {
            file.seekg(i, ios::end);
            file >> s;
        }
        file.close();
        s.erase(0, 4);
        int id;
        istringstream(s) >> id;
        return id;
    }

    int checkFile(string attempt, const char *p_fileName) {
        string line;
        fstream file;
        string currentChar;
        long long eChar;
        file.open(p_fileName, ios::in);
        while (1) {
            file >> currentChar;
            if (currentChar.find("#ID:") != string::npos) {

                if (attempt == line) {
                    file.close();
                    currentChar.erase(0, 4);
                    int id;
                    istringstream(currentChar) >> id;
                    return id;
                } else {
                    line.erase(line.begin(), line.end());
                }
            } else {
                istringstream(currentChar) >> eChar;
                line += (char) decrypt(eChar);
                currentChar = "";
            }
            if (file.peek() == EOF) {
                file.close();
                return 0;
            }
        }
    }
    void saveFile(string p_line, const char *p_fileName, int i1) {
        fstream file;
        file.open(p_fileName, ios::app);
        file.seekg(0, ios::end);
        if (file.tellg() != 0) {
            file << "\n";
        }
        file.seekg(0, ios::beg);

        for (int i = 0; i < p_line.length(); i++) {
            file << encrypt(p_line[i]);
            file << "\n";
        }
        int id;
        file << "#ID:" << id;
        file.close();
    }
    long long encrypt(int p_letter) {
        return p_letter + 3;
    }

    int decrypt(long long p_letter) {
        return p_letter - 3;
    }
private:
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
           app.login();
           cin.get();
       }
       else if (choice ==2) {
           //  registration();
           loginManger app;
           cout<<"please enter a username";
           string uN;
           cin>>uN;
           app.addUser(uN,"user.data");
           cout<< "please enter a password";
           string pS;
           cin >> pS;
           app.addUser(uN,"passwords.data");
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