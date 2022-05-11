// fci - programming 1 - 2022 - assigment 4
// program name : login page
// author 1 : Rana ayman barakat alsakka id : 20210511
// author 2 : sahab mohammed abd el rahman id : 20210158
// author 3 : mohanad hesham id : 20210414
// teaching assistant : s5 - s6
// -------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

class LoginManager
{
public:

    LoginManager()
    {
        accessGranted = 0;
    }
    void login()
    {
        cout << "please enter your username and password" << endl << " username" << endl;
        cin >> userNameAttempt;

        int usrID = checkFile(userNameAttempt, "users.dat");
        if(usrID != 0)
        {
            cout << "Password:";
            cin >> passwordAttempt;

            int pwdID = checkFile(passwordAttempt, "pswds.dat");
            if(usrID == pwdID)
            {
                cout << "hello " << userNameAttempt << " you are successfully logged in!"<< endl;
                login();

            }
            else
            {
                cout << "wrong username please try again";
                login();
            }
        }
        else
        {
            cout << "wrong password please try again";
            login();
        }
    }


    int getLastID()
    {
        fstream file;
        file.open("users.dat", ios::in);
        file.seekg(0, ios::end);

        if(file.tellg() == -1)
            return 0;

        string s;

        for(int i = -1; s.find("#") == string::npos; i--)
        {
            file.seekg(i, ios::end);
            file >> s;
        }

        file.close();
        s.erase(0, 4);

        int id;
        istringstream(s) >> id;

        return id;
    }

    int checkFile(string attempt, const char* p_fileName)
    {
        string line;
        fstream file;

        string currentChar;
        long long eChar;

        file.open(p_fileName, ios::in);

        while(1)
        {
            file >> currentChar;
            if(currentChar.find("#ID:") != string::npos)
            {
                if(attempt == line)
                {
                    file.close();
                    currentChar.erase(0, 4);
                    int id;
                    istringstream(currentChar) >> id;
                    return id;
                }
                else
                {
                    line.erase(line.begin(), line.end());
                }
            }
            else
            {
                istringstream(currentChar) >> eChar;
                line += (char)decrypt(eChar);
                currentChar = "";
            }

            if(file.peek() == EOF)
            {
                file.close();
                return 0;
            }
        }
    }

    void saveFile()
    {

        string username ;
        string password;
        string pass2;
        cout << "please enter a username" << endl;
        cin >> username;
        if(checkFile(username, "users.dat") != 0)
        {
            cout << "That username is not availble." << endl;
            return;}

        int id = 1 + getLastID();
        fstream file;
        file.open("users.dat", ios::app);
        file.seekg(0, ios::end);

        if(file.tellg() != 0)
            file << "\n";

        file.seekg(0, ios::beg);

        for(int i = 0; i < username.length(); i++)
        {
            file << encrypt(username[i]);
            file << "\n";
        }

        file << "#ID:" << id;
        file.close();
        cout << "please enter a password" << endl;
        cin >> password;
        cout << "please renter a password" << endl;
        cin >> pass2;
        if (password == pass2) {
            int id =  getLastID();
            fstream file;
            file.open("pswds.dat", ios::app);
            file.seekg(0, ios::end);

            if(file.tellg() != 0)
                file << "\n";

            file.seekg(0, ios::beg);

            for(int i = 0; i < password.length(); i++)
            {
                file << encrypt(password[i]);
                file << "\n";
            }

            file << "#ID:" << id;
            file.close();
            cout << "you are successfully registered\n\n\n";
            login();
        } else {
            cout << "passwords didn't match please try again" << endl;
saveFile();
        }

    }

    long long encrypt(int p_letter)
    {
        return powf(p_letter, 5) * 4 - 14;
    }
    int decrypt(long long p_letter)
    {
        return powf((p_letter + 14) / 4, 1/5.f);
    }

private:
    string userNameAttempt;
    string passwordAttempt;
    bool accessGranted;
};

int main() {
    int choice;
    cout << " \t\t\t ------------------------login page------------------------\n";
    cout
            << "1.login" << endl
            << "2.register" << endl
            << "3.forgot password" << endl
            << "4.exit"<< endl;
    cin >> choice;
    if( choice == 1) {
        LoginManager app;
        app.login();
        cin.get();
    }
    else if (choice ==2) {
        //  registration();
        LoginManager loginMangerObj;
        loginMangerObj.saveFile();

    }
    else if (choice ==3) {
        //  change password();
    }
    else if (choice ==4) {
        cout << " thank you ";
    }
    else
        cout << " \t\t\t please select from the options above";
}
