#include "UsersBudgetManager.h"

void UsersBudgetManager::addIncome(){
    transactions -> addIncome();
}

void UsersBudgetManager::addExpend(){
    transactions -> addExpend();
}

long int UsersBudgetManager::getBeginingOfTheCurrentMonth(){
    long int beginingOfTheMonth, currentDate;
    int numberOfHundrets;
    currentDate = transactions -> getCurrentDate();
    numberOfHundrets = currentDate / 100;
    beginingOfTheMonth = numberOfHundrets*100 + 1;
    return beginingOfTheMonth;
}

void UsersBudgetManager::generateReportFromCurrentMonth(){
    long int beginingOfTheMonth = getBeginingOfTheCurrentMonth();

}

void UsersBudgetManager::generateReportFromPreviousMonth(){
    return ;
}

void UsersBudgetManager::generateReportFromCustomDate(){
    return ;
}
