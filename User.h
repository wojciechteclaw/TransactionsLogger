#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User{
    int id;
    string login;
    string password;

public:
    void setId(int);
    void setLogin(string);
    void setPassword(string);
    int getId();
    string getLogin();
    string getPassword();
};
#endif
