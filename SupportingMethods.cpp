#include "SupportingMethods.h"

string SupportingMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SupportingMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char SupportingMethods::loadCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string SupportingMethods::changeFirstLetterToCapitalAndRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int SupportingMethods::convertStringToInt(string string_number)
{
    int number;
    istringstream iss(string_number);
    iss >> number;

    return number;
}

string SupportingMethods::getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}
