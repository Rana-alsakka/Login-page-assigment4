#include <iostream>
#include <fstream>
#include<string>
using namespace std;
void login();
void registration();
void forgot ();
int main() {
    int choice;
    cout << " \t\t\t ------------------------login page------------------------\n";
    cout
            << "1.login" << endl
            << "2.register" << endl
            << "3.forgot password" << endl
            << "4.exit"<< endl;
    cin >> choice;
    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << " thank you ";
            break;
        default:
            cout << " \t\t\t please select from the options above";
            main();

    }
}
void login() {

    int count;
    string userId, password, id, pass;
    cout << "please enter the username and password : " << endl;
    cout << "    USERNAME      ";
    cin >> userId;
    cout << "    PASSWORD     ";
    cin >> password;
    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
        }
    }
    input.close();
    if (count == 1) {
        cout << "      your login is succesfsull!      ";
        main();
    } else {
        cout << " \n login error \n inccorect username or password";
        main();
    }
}
void registration()
{
    string r_userid, r_id , r_pass;
    const char *r_password;
    cout<< "      Enter the username :";
    cin>>r_userid;
    cout <<"      Enter the password :";
    cin >> (unsigned char *) r_password;
    // --------------------------------------------------check for weak password-------
    if(strlen(r_password) < 8) {
        cout<< " \n weak password\n    password must be 8 characters long     "<< endl;
        registration();
    }
    else if (strlen(r_password) >= 8) {
        bool digit_yes = false;
        bool valid;
        int len = strlen(r_password);
        for (int count = 0; count < len; count++)
            if (isdigit(r_password[count]))
                digit_yes = true;
        if (!digit_yes) {
            valid = false;
            cout << " \n password must have at least one digit (0-9)" << endl;
            registration();
        }
    }

    else {
        ofstream f1("records.txt", ios::app);
        f1 << r_userid << "   " << r_password << endl;
        cout << "        Registration is successfull!       \n";
        main();
    }}
void forgot()
{
    int option;
    cout<<"\t please choose how you want to recover your password"<< endl;
    cout<< "1.phone number"<<endl<< "2. email"<<endl;
    cin>> option;
}
