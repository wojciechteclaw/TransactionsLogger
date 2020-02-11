#include "UserManager.h"

void UserManager::registerUser(){
    User user = getNewUserData();
    users.push_back(user);
    userFile.appendUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
}

void UserManager::signInUser(){
    if (users.empty()){
        cout << "Brak uzytkownikow w bazie danych" << endl;
        return ;
    }
    string login, password;
    cout << endl << "Podaj login: ";
    cin >> login;
    for (int i = 0; i < users.size(); i++){
        if (login == users[i].getLogin()){
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                cin >> password;
                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    signInUserId = users[i].getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            signInUserId = 0;
            return ;
        }
    }
}

User UserManager::getNewUserData(){
    User user;
    int newUserId = getLastUserId() + 1;
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
    } while (checkIfLoginExists(login) == true);
    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setId(newUserId);
    user.setLogin(login);
    user.setPassword(password);
    return user;
}

bool UserManager::checkIfLoginExists(string login){
    for (int i = 0; i < users.size(); i++){
        if (users[i].getLogin() == login){
            return true;
        }
    }
    return false;
}

void UserManager::loadAllUsersFromFile(){
    users = userFile.loadUsersFromFile();
    lastUserId = getLastUserId();
}

int UserManager::getSignInUserId(){
    return signInUserId;
}

int UserManager::getLastUserId(){
    if (users.empty()){
        return 0;
    }
    else
    {
        return users.back().getId();
    }
}
