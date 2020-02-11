#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <iostream>
#include <stdlib.h>
#include "SupportingMethods.h"


using namespace std;
class MenuInterface{

public:
    char choiceFromMainMenu();
    char choiceFromSignInUserMenu();
};
#endif
