#include <iostream>
#include "UserManager.h"
#include "MenuInterface.h"
#include "UsersBudgetManager.h"

using namespace std;

class Wallet{
    UserManager userManager;
    UsersBudgetManager *usersBudgetManager;

public:
    Wallet(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers){
        usersBudgetManager = NULL;
    }

    ~Wallet(){
        delete usersBudgetManager;
        usersBudgetManager = NULL;
    }
    void registerUser();
    void signInUser();
    void lanchProgram();

};
