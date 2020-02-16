#include "UserFile.h"

bool UserFile::checkIfFileContainsUsers(){
    CMarkup xml;
    xml.Load(fileName);
    xml.ResetPos();
    if (xml.FindElem("listOfUsers")){
        xml.IntoElem();
        if (xml.FindElem("user")){
            return true;
        }
    }
    return false;
}

void UserFile::appendUserToFile(User userToAppend){
    CMarkup xml;
    xml.Load(fileName);
    xml.ResetPos();
    if (checkIfFileContainsUsers()){
        xml.FindElem("listOfUsers");
        xml.IntoElem();
    }
    else {
        xml.AddElem("listOfUsers");
        xml.IntoElem();
    }
    xml.AddElem("user");
    xml.AddAttrib("id", userToAppend.getId());
    xml.AddAttrib("login", userToAppend.getLogin());
    xml.AddAttrib("password", userToAppend.getPassword());
    xml.Save(fileName);
}

vector<User> UserFile::loadUsersFromFile(){
    CMarkup xml;
    vector <User> allUsers;
    xml.Load(fileName);
    xml.ResetPos();
    if (checkIfFileContainsUsers()){
        xml.FindElem("listOfUsers");
        xml.IntoElem();
        while (xml.FindElem("user")){
                User tempUser;
                tempUser.setId(SupportingMethods::convertStringToInt(xml.GetAttrib("id")));
                tempUser.setLogin(xml.GetAttrib("login"));
                tempUser.setPassword(xml.GetAttrib("password"));
                allUsers.push_back(tempUser);
        }
    }
    return allUsers;
}

void UserFile::updatePassword(int idNumber, string newPassword){
    string idToUpdate = SupportingMethods::convertIntToString(idNumber);
    CMarkup xml;
    xml.Load(fileName);
    xml.ResetPos();
    xml.FindElem("listOfUsers");
    xml.IntoElem();
    while (xml.FindElem("user")){
        if (xml.GetAttrib("id") == idToUpdate){
            xml.AddAttrib("password", newPassword);
        }
    xml.Save(fileName);
    }
}
