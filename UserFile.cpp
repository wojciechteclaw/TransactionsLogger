#include "UserFile.h"

bool UserFile::checkIfFileContainsUsers(){
    CMarkup xml;
    string path = "users.xml";
    xml.Load(path);
    xml.ResetPos();
    if (xml.FindElem("ListOfUsers")){
        xml.IntoElem();
        if (xml.FindElem("user")){
            return true;
        }
    }
    return false;
}

void UserFile::appendUserToFile(User userToAppend){
    CMarkup xml;
    string path = "users.xml";
    xml.Load(path);
    xml.ResetPos();
    if (checkIfFileContainsUsers()){
        xml.FindElem("ListOfUsers");
        xml.IntoElem();
    }
    else {
        xml.AddElem("ListOfUsers");
        xml.IntoElem();
    }
    xml.AddElem("user");
    xml.AddAttrib("id", userToAppend.getId());
    xml.AddAttrib("login", userToAppend.getLogin());
    xml.AddAttrib("password", userToAppend.getPassword());
    xml.Save(path);
}

vector<User> UserFile::loadUsersFromFile(){
    CMarkup xml;
    vector <User> allUsers;
    string path = "users.xml";
    xml.Load(path);
    xml.ResetPos();
    if (checkIfFileContainsUsers()){
        xml.FindElem("ListOfUsers");
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

