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
            cout << "Hello signedIn" << endl;

        /*
            char wybor = menuInterface.wyborZMenuZalogowanegoUzytkownika();
            switch (wybor)
            {
            case '1':
                adresMenadzer.dodajAdresata();
                cout<< 1 << endl; //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '2':
                adresMenadzer.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                cout<< 3 << endl; //wyszukajAdresatowPoNazwisku(adresaci);
                break;
                */
            }
        }
    }
