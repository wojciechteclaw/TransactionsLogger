#include "Transactions.h"

void Transactions::addIncome(){
    cout << "add income" << endl;
}

void Transactions::addExpend(){
    cout << "add expend" << endl;
    cout << "Podaj date:" << endl;
    while (true){
        string date;
        cin >> date;
        cout << getDateFromString(date) << endl;
    }

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
    string year, month, day;
    string dateElement;
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
    if (checkIfDateIsCorrect(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()), dateString)){

        return atoi(dateString.c_str());
    }
    else return 0;
}


/*




/*
int lastIncomeId;
    int lastExpendId;
    const int SIGNEDINUSERID;
    void loadIncomes();
    void loadExpenses();
    void loadUserBudget();
public:
    Transactions(int signedInUserId) :SIGNEDINUSERID(signedInUserId) {};
    void addIncome();
    void addExpend();
    bool checkIfDateIsCorrect(string);
    int getCurrentDate();


    */
