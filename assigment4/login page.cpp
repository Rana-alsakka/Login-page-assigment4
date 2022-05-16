#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<regex>
#include"login page.h"
#include<conio.h>
void login() {
        int x = 1;
        while (x < 3) {  // login attempts
            cout << "please enter your username and password" << endl << " username" << endl;
            cin >> userNameAttempt;

            int usrID = checkFile(userNameAttempt, "users.dat"); //check for username
            if (usrID != 0) { //if found
                cout << "Password:";

                char passwordAttempt[16] = { 0 };
                int i;
                for (i = 0; i < 16;i++) {
                    passwordAttempt[i] = _getch(); _putch('*');

                }

                cin >> passwordAttempt;
                int pwdID = checkFile(passwordAttempt, "pswds.dat");
                if (usrID == pwdID) { // check if the password belongs to this username
                    cout << "hello " << userNameAttempt << " you are successfully logged in!" << endl;
                    x = 0;
                    break;
                } else {
                    cout << "wrong username please try again" << endl;
                    x++;

                    if (x > 3) {
                        cout
                                << "you've reached the maximum limit for attempting password , you are denied to access the system"
                                << endl;
                        break;
                    } else {
                        x++;
                        cout << x;
                    }
                }
            } else {
                cout << "wrong password please try again" << endl;
            }
        }
    } 
    //-----------------------------for adding users and saving them-----------------------------------
    void saveFile()
    {
        string username ;
        string password;
        string number;
        string email;
        string pass2;
        cout << "please enter a username" << endl;
        cin >> username;
        userFormat(username);
        cout << "please enter your email"<< endl;
        cin >> email;
        validEmail(email);
        fstream EData;
        EData.open("emails.dat", ios::app);
        EData<< "\n"<<email;
        EData.close();
        cout << "please enter your phone number"<<endl;
        cin >> number;
        phoneValidation(number);
        fstream num;
        num.open("numbers.dat", ios::app);
        num<< "\n"<<number;
        num.close();
        if(checkFile(username, "users.dat") != 0) // checking if username available
        {
            cout << "That username is not availble." << endl;
            return;}

        int id = 1 + getLastID();  // saving to file with new id
        fstream file;
        file.open("users.dat", ios::app);
        file.seekg(0, ios::end);

        if(file.tellg() != 0)
            file << "\n";

        file.seekg(0, ios::beg);

        for(int i = 0; i < username.length(); i++)
        {
            file << encrypt(username[i]); // loop for encrypting username
            file << "\n";
        }
        file << "#ID:" << id;
        file.close();
        cout << "please enter a password" << endl;
        cout << " *passwords must be 8 characters long & have at least one uppercase character and a number "<<endl;

        int i;
        for (i = 0; i < 16;i++) {
            password[i] = _getch(); _putch('*');

        }
        cin >> password;
        cout << "please renter a password" << endl;
        cin >> pass2;
        int x;
        for (x = 0; i < 16;x++) {
            pass2 = _getch(); _putch('*');

        }



        if (password == pass2) { // if password confirmation matches
            checkPass(password);  // check for strong password
            int id =   getLastID();
            fstream file;
            file.open("pswds.dat", ios::app);
            file.seekg(0, ios::end);

            if(file.tellg() != 0)
                file << "\n";

            file.seekg(0, ios::beg);

            for(int i = 0; i < password.length(); i++)
            {
                file << encrypt(password[i]); // loop for encrypting password
                file << "\n"; // saving it line by line
            }

            file << "#ID:" << id; //saving id with passwords data
            file.close();
            cout << "you are successfully registered\n\n\n";
            login();
        } else {
            cout << "passwords didn't match please try again" << endl;
            saveFile();
        }

    }

    //------------------------saving users and passwords information with id-----------------------------------
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

//-----------------------------checking data files-----------------------------------
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
//-----------------------------change password-----------------------------------
    void change() {
        string newpass;
        string newpass2;
        cout << " please enter your old password";
        cin >> passwordAttempt;
        int usrID = checkFile(userNameAttempt, "users.dat");
        int pwdID = checkFile(passwordAttempt, "pswds.dat");
        if (usrID == pwdID) {
            cout << "please enter your new password";


            int i;
            for (i = 0; i < 16;i++) {
                newpass[i] = _getch(); _putch('*');

            }

            cin >> newpass;
            cout << "please renter a password" << endl;

            newpass2[16] = { 0 };
            int u;
            for (u = 0; i < 16;i++) {
                newpass2[u] = _getch(); _putch('*');

            }



            cin >> newpass2;
            if (newpass2 == newpass) { // check if passwords match
                checkPass(newpass); // check for strong password
                if (newpass == passwordAttempt ){
                    cout << "you can't use an old password"<< endl; //check for old password
                    change();
                    return;
                }
                int id = pwdID;     // to save to the same id for the user not new one
                fstream file;
                file.open("pswds.dat", ios::app);
                file.seekg(0, ios::end);

                if(file.tellg() != 0)
                    file << "\n";

                file.seekg(0, ios::beg);



                for(int i = 0; i < newpass.length(); i++)
                {
                    file << encrypt(newpass[i]); // loop for encrypting password
                    file << "\n";
                }

                file << "#ID:" << id;
                file.close();
                cout<< " your password is successfully changed";
            }
            else {
                cout<< "passwords don't match please try again";
            }
        }}
//-----------------------------encryption and decryption-----------------------------------
    long long encrypt(int p_letter)
    {
        return powf(p_letter, 5) * 4 - 14;
    }
    int decrypt(long long p_letter)
    {
        return powf((p_letter + 14) / 4, 1/5.f);
    }

//-----------------------------checking for proper formats-----------------------------------

//-----------password------------------
    int checkPass(string pw) {
        bool upper_case = false;
        bool lower_case = false;
        bool number_case = false;
        bool special_char = false;


        std::regex upper_case_expression{"[A-Z]+"}; // upper case
        std::regex lower_case_expression{"[a-z]+"}; //for lower-case
        std::regex number_expression{"[0-9]+"}; //...
        std::regex special_char_expression{"[@!?]+"};

        bool done = false;

        do {

            if (pw.length() <= 8) { //check for password length
                std::cout << "Invalid password! Try again . . .\n\n";
                showmenue();
            } else {

                upper_case = std::regex_search(pw, upper_case_expression);
                lower_case = std::regex_search(pw, lower_case_expression);
                number_case = std::regex_search(pw, number_expression);
                special_char = std::regex_search(pw, special_char_expression);
                int sum_of_positive_results = upper_case + lower_case + number_case + special_char;

                if (sum_of_positive_results < 3) {
                    std::cout << "Invalid password! Try again . . .\n\n";
                    showmenue();
                } else {
                    done = true;
                }
            }

        } while (!done);

        return 0;
    }
    //----------checking for  Email----------------------
    int validEmail(string email) {
        if (regex_match(email, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)"))){
            return 0;
        }
        else {
            cout << "wrong email format\n";
            saveFile();
        }
    }
    // -------------checking for phone number-----
    int phoneValidation(string phone)
    {
        char start = '0';
        char start2= '1';

        if (phone.length() != 11)			//check for length
        {
            cout<< "wrong phonenumber format , missing numbers";
            showmenue();
        }

        for( int count = 0; count < phone.length(); count++ )	//loop to check each individual character
        {
            if (!isdigit(phone[count]))		//checks all characters in phone if they are not digits
            {
                cout<< "wrong phonenumber format , must be digits";
                showmenue();
            }
            if (count==0 && phone[count] != start || count==1 && phone[count] != start2)//if it doesn't start with 01
            {
                cout<< "wrong phonenumber format , must start with (01)";
                showmenue();
            }
            else{
                return 0;
            }}
        return 0;
    }
//-----------check username format--------
    int userFormat( string username){
        bool number_case = false;
        bool special_char = false;

        std::regex number_expression{"[0-9]+"}; //...
        std::regex special_char_expression{"[@!?]+"};

        bool done = false;

        do {

            if (username.length() <= 2) { //check for username length
                std::cout << "Invalid user(too short)! Try again . . .\n\n";
                showmenue();
            } else {

                number_case = std::regex_search(username, number_expression);
                special_char = std::regex_search(username, special_char_expression);
                int sum_of_positive_results = number_case + special_char;

                if (sum_of_positive_results > 0) {
                    std::cout << "Invalid username(username can't have numbers or special characters, please Try again \n\n";
                    showmenue();
                } else {
                    done = true;
                }
            }

        } while (!done);

        return 0;
    }

    void showmenue(){
        int choice;
        cout << " \t\t\t ------------------------login page------------------------\n";
        cout
                << "1.login" << endl
                << "2.register" << endl
                << "3.change password" << endl
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
            LoginManager app;
            app.login();
            app.change();

        }
        else if (choice ==4) {
            cout << " thank you ";
        }
        else
            cout << " \t\t\t please select from the options above";
    }
