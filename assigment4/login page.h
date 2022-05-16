class LoginManager
{
public:

    LoginManager()
    {
        accessGranted = 0;
    }
private:
    string userNameAttempt;
    string passwordAttempt;
    bool accessGranted;
};
