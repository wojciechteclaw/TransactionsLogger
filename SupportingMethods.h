#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class SupportingMethods
{
public:
    static string convertIntToString(int);
    static string loadLine();
    static char loadCharacter();
    static string changeFirstLetterToCapitalAndRestToLowercase(string);
    static int convertStringToInt(string);
    static string getNumber(string, int);
};
#endif
