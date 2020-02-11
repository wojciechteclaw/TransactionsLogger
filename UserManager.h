#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "UserFile.h"
#include "SupportingMethods.h"
#include <iostream>

using namespace std;

class UserManager{
    int signInUserId;
    vector <User> users;
    UserFile userFile;
    int lastUserId;
    User getNewUserData();
    bool checkIfLoginExists(string);
    int getLastUserId();

public:
    UserManager(string nameOfFileWithUsers) : userFile(nameOfFileWithUsers){
        signInUserId = 0;
    }
    void registerUser();
    void signInUser();
    int getSignInUserId();
    void loadAllUsersFromFile();
    void changeSignedInUserPassword();
    void logOut();
};

#endif
