#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;

class loginManger{
private:
        string usernameAttempt;
        string passwordAttempt;
        bool accessGranted;
  
  
public:
  void login();
  void addUser(string username, string password);
  int getlastID();
  void regist();
  int checkFile(string attempt, const char *p_fileName);
  void saveFile(string p_line, const char *p_fileName, int i1);
  long long encrypt(int p_letter);
  int decrypt(long long p_letter);
  loginManger();
}
