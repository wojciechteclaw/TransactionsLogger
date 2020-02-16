#include "Transactions.h"

long int Transactions::getDate(){
    long int date = 0;
    cout << "Czy transakcja dotyczy dzisiejszego dnia? Jesli tak wcisnij 't' i zatwierdz przyciskiem ENTER." << endl;
    char answer;
    answer = SupportingMethods::loadCharacter();
    if (answer == 't'){
            return getCurrentDate();
    }
    else{
        string dateToConver;
        do{
            cout << "Podaj date przychodu w formacie rrrr-mm-dd:" << endl;
            dateToConver = SupportingMethods::loadLine();
            date = getDateFromString(dateToConver);
        }while (date == 0);
        return date;
    }
}

void Transactions::addIncome(){
    Income newIncome;
    cout << "DODAJ PRZYCHOD" << endl;
    long int date = getDate();
    double incomeAmount;
    string descreption, answer;
    cout << "Podaj opis przychodu: " << endl;
    descreption = SupportingMethods::loadLine();
    incomeAmount = getAmount();
    newIncome.setAmount(incomeAmount);
    newIncome.setDescription(descreption);
    newIncome.setDate(date);
    newIncome.setUserId(SIGNEDINUSERID);
    newIncome.setId(incomeFile.getLastIncomeId() + 1);
    incomes.push_back(newIncome);
    incomeFile.addIncomeToFile(newIncome);
}

void Transactions::addExpend(){
    Expend newExpend;
    cout << "DODAJ WYDATEK" << endl;
    long int date = getDate();
    double incomeAmount;
    string descreption, answer;
    cout << "Podaj opis wydatku: " << endl;
    descreption = SupportingMethods::loadLine();
    incomeAmount = getAmount();
    newExpend.setAmount(incomeAmount);
    newExpend.setDescription(descreption);
    newExpend.setDate(date);
    newExpend.setUserId(SIGNEDINUSERID);
    newExpend.setId(expendFile.getLastExpendId() + 1);
    expends.push_back(newExpend);
    expendFile.addExpendToFile(newExpend);
}

long int Transactions::getCurrentDate(){
    time_t currentTime;
    struct tm * dateTime;
    int day, month, year;
    char dateElement[ 9 ];
    time( & currentTime );
    dateTime = localtime( & currentTime );
    strftime( dateElement, 9, "%Y%m%d", dateTime );
    long int dateToReturn = atoi(dateElement);
}

int Transactions::getNumberOfDaysInMonth(int month, int year){
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    else if (month == 2){
        if (year % 4 == 0) return 29;
        else return 28;
    }
    else return 0;
}

bool Transactions::checkIfDateIsCorrect(int year, int month, int day, string dateAsString){
    long int dateToCheck = atoi(dateAsString.c_str());
    if (year >= 2000 && dateToCheck <= getCurrentDate()){
            if (month >= 1 && month <= 12){
                int numberOfDaysInMonth = getNumberOfDaysInMonth(month, year);
                if (day >= 1 && day <= numberOfDaysInMonth){
                    return true;
                }
            }
    }
    return false;
}

long int Transactions::getDateFromString(string enteredDate){
    string year, month, day, dateElement;
    int elementsOfDate = 1;
    int dashLocation = 0;
    for (int i = 0; i < 3; i ++){
        dashLocation = enteredDate.find("-");
        dateElement = enteredDate.substr(0, dashLocation);
        enteredDate.erase(0, dashLocation + 1);
        switch (elementsOfDate){
        case 1:
            year = dateElement;
            break;
        case 2:
            month = dateElement;
            break;
        case 3:
            day = enteredDate;
        }
        elementsOfDate ++;
    }
    string dateString = year + month + day;
    if (checkIfDateIsCorrect(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()), dateString)) return atoi(dateString.c_str());
    else return 0;
}

string Transactions::replaceCommaInString(string stringToReplace){
    int indexOfComma = -1;
    indexOfComma = stringToReplace.find(",");
    if (indexOfComma != -1){
        return stringToReplace.replace(indexOfComma, 1, ".");
    }
    else{
        return stringToReplace;
    }
}

double Transactions::getAmount(){
        cout << "Podaj kwote: " << endl;
        string inputAmount = SupportingMethods::loadLine();
        string inputAmountWithProperComma = replaceCommaInString(inputAmount);
        double amountToReturn = SupportingMethods::convertStringToDouble(inputAmountWithProperComma);
        return amountToReturn;
}
