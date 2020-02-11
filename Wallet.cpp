#include "Wallet.h"

void Wallet::registerUser(){
    userManager.registerUser();
}

void Wallet::signInUser(){
    userManager.signInUser();
}

void Wallet::lanchProgram(){
    MenuInterface menuInterface;
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
                cout << "Dodaj przychod" << endl;
                break;
            case '2':
                cout << "Dodaj wydatek" << endl;
                break;
            case '3':
                cout << "Bilans z biezacego miesiaca" << endl;
                break;
            case '4':
                cout << "Bilans z poprzedniego miesiaca" << endl;
                break;
            case '5':
                cout << "Bilans z wybranego okresu" << endl;
                break;
            case '6':
                userManager.changeSignedInUserPassword();
                break;
            case '9':
                userManager.logOut();
            }
            }
        }
    }
