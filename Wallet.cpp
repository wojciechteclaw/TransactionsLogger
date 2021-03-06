#include "Wallet.h"

void Wallet::registerUser(){
    userManager.registerUser();
}

void Wallet::signInUser(){
    userManager.signInUser();
    if (userManager.getSignInUserId() != 0){
        usersBudgetManager = new UsersBudgetManager(userManager.getSignInUserId());
    }
}

void Wallet::lanchProgram(){
    MenuInterface menuInterface;
    userManager.loadAllUsersFromFile();
    while (true)
    {
        if (userManager.getSignInUserId() == 0)
        {
            char choice = menuInterface.choiceFromMainMenu();
            switch (choice)
            {
            case '1':
                registerUser();
                break;
            case '2':
                signInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                break;
            }
            system("pause");
        }
        else{
            char signedInUserChoice = menuInterface.choiceFromSignInUserMenu();
            switch (signedInUserChoice){
            case '1':
                usersBudgetManager -> addIncome();
                break;
            case '2':
                usersBudgetManager -> addExpend();
                break;
            case '3':
                usersBudgetManager -> generateReportFromCurrentMonth();
                break;
            case '4':
                usersBudgetManager -> generateReportFromPreviousMonth();
                break;
            case '5':
                usersBudgetManager -> generateReportFromCustomDate();
                break;
            case '6':
                userManager.changeSignedInUserPassword();
                break;
            case '9':
                userManager.logOut();
            }
            system("pause");
            }
        }
    }
