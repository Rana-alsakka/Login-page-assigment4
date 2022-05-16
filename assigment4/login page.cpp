#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<regex>

using namespace std;
string username, password;


    void login() {
        cout << "please enter your username and password" << endl << " username" << endl;
        cin >> usernameAttempt;
        fstream lData;
        lData.open("users.txt" , ios::in);
        lData>>username;
        if (usernameAttempt==username) {
            cout<< "password";
            cin>> passwordAttempt;
            fstream plData;
            plData.open ("passwordsData.txt", ios::in);
            if (plData.is_open()){
                string username;
                while(getline(plData, password)){
                }
                plData.close();
            }
            cout<<username<<" you are successfully logged in!";
        }

        else {
            cout<<"error";
            return;
        }
        }


    string getFile(const char*p_fileName) {
        string line;
        fstream file;
        int eChar;
        file.open(p_fileName, ios::in);
        while(1)
        {
            file>> eChar;
            if (eChar == 0 )
            {
                file.close();
                cout << "error";
                return line;

            }
            line += char(eChar);
        }
    }

    void addUser() {
        string username, password;
        cout<< "please enter a username";
        cin >> username;
        cout<< "please enter a password";
        cin >> password;
        if (checkFile(username, "users.txt") != 0) {
            cout << " that username is not available" << endl;
            return;
        }
        else {
          ofstream uData;
          uData.open ("users.txt");
          uData<<username;
          ofstream pData;
          pData.open ("passwordsData.txt");
          pData<<password;
          cout<<"you are successfully registered";
        }
        int id = 1 + getlastID();
        saveFile(username, "user.txt");
        saveFile(password, "passwords.data");
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
                    cout << "error";
                    currentChar.erase(0, 4);
                    int id;
                    istringstream(currentChar) >> id;
                    return id;
                } else {
                    line.erase(line.begin(), line.end());
                }
            } else {
                istringstream(currentChar) >> eChar;
                line += (char)(eChar);
                currentChar = "";
            }
            if (file.peek() == EOF) {
                file.close();
                return 0;
            }
        }
    }
    void saveFile(string p_line, const char *p_fileName ) {
        cin>>p_line;
        int id;
        fstream file;
        file.open(p_fileName, ios::app);
        file.seekg(0, ios::end);
        if (file.tellg() != 0) {
            file << "\n";
        }
        file.seekg(0, ios::beg);

        for (int i = 0; i < p_line.length(); i++) {
            file << (p_line[i]);
            file << "\n";
        }
        file << "#ID:" << id;
        file.close();
    }
