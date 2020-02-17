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

void UsersBudgetManager::generateReportFromDateToDate(long int beginningOfPeriod, long int endOfPeriod){
    vector <Income> localListOfIncomes = transactions -> incomes;
    vector <Expend> localListOfExpends = transactions -> expends;
    for (int i = 0; localListOfIncomes.size(); i++){
        long int date = localListOfIncomes[i].getDate();
        if (beginningOfPeriod < date && date < endOfPeriod)
            transactions->representIncome(localListOfIncomes[i]);
    }
    for (int i = 0; localListOfExpends.size(); i++){
        long int date = localListOfExpends[i].getDate();
        if (beginningOfPeriod < date && date < endOfPeriod)
            transactions->representExpend(localListOfExpends[i]);
    }
}

void UsersBudgetManager::generateReportFromCustomDate(){
    while (true){
        long int beginingOfPeriod, endOfPeriod;
        cout << "Podaj date od ktorej chcesz wyswietlic tranzakcje w raporcie: ";
        string beginningOfPeriodAsString = SupportingMethods::loadLine();
        beginingOfPeriod = transactions -> getDateFromString(beginningOfPeriodAsString);
        cout << "Podaj date do ktorej chcesz wyswietlic tranzakcje w raporcie: ";
        string endOfPeriodAsString = SupportingMethods::loadLine();
         endOfPeriod = transactions -> getDateFromString(endOfPeriodAsString);
         if (endOfPeriod > beginingOfPeriod && endOfPeriod != 0 && beginingOfPeriod != 0){
            generateReportFromDateToDate(beginingOfPeriod, endOfPeriod);
            SupportingMethods::convertNumberToDateRepresentation(endOfPeriod);
            break;
         }
         else{
            cout << "nie spoko" << endl;
         }
    }
}
