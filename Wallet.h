#include <iostream>
#include "UserManager.h"
#include "MenuInterface.h"

using namespace std;

class Wallet{
    UserManager userManager;
    //Menadzer wydatkow

public:
    Wallet(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers){
        userManager.loadAllUsersFromFile();
    }
    void registerUser();
    void signInUser();
    void lanchProgram();

};
