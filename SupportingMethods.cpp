#include "SupportingMethods.h"

double SupportingMethods::convertStringToDouble(string stringToConvert){
        double amountToReturn;
        stringstream iss (stringToConvert);
        iss >> amountToReturn;
        return amountToReturn;
}

string SupportingMethods::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SupportingMethods::loadLine(){
    string input;
    getline(cin, input);
    return input;
}

string SupportingMethods::convertDoubleToString(double number){
    ostringstream strs;
    strs << number;
    return strs.str();
}

char SupportingMethods::loadCharacter(){
    string input;
    char character  = {0};

    while (true)
    {
        cin >> input;

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    cin.ignore();
    return character;
}

string SupportingMethods::changeFirstLetterToCapitalAndRestToLowercase(string text){
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int SupportingMethods::convertStringToInt(string string_number){
    int number;
    istringstream iss(string_number);
    iss >> number;

    return number;
}

string SupportingMethods::getNumber(string text, int characterPosition){
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

string SupportingMethods::convertNumberToDateRepresentation(long int number){
    string stringToConvert = convertIntToString(number);
    string year, month, day;
    year = stringToConvert.substr(0, 4);
    month = stringToConvert.substr(4, 2);
    day = stringToConvert.substr(6, 2);
    string finalStringtoReturn = year + "-" + month + "-" + day;
    return finalStringtoReturn;
}
