#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "Markup.h"
#include "SupportingMethods.h"

using namespace std;

class UserFile{
    const string fileName;
    bool checkIfFileContainsUsers();

public:
    UserFile(string NAMEOFFILEWITHUSERS) : fileName(NAMEOFFILEWITHUSERS){ };
    void appendUserToFile(User);
    vector <User> loadUsersFromFile();
    void updatePassword(int, string);
};
#endif
