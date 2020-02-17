#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include "SupportingMethods.h"

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
    static string convertDoubleToString(double);
    static double convertStringToDouble(string);
    static string convertNumberToDateRepresentation(long int);
};
#endif
