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
    long int currentDay = transactions ->getCurrentDate();
    generateReportFromDateToDate(beginingOfTheMonth, currentDay);
}

void UsersBudgetManager::generateReportFromPreviousMonth(){
    long int beginningOfPreviousMonth =  transactions->getPreviousMonthStartDay();
    long int endOfPreviousMonth = transactions ->getPreviousMonthEndDay();
    generateReportFromDateToDate(beginningOfPreviousMonth, endOfPreviousMonth);
}

void UsersBudgetManager::generateReportFromDateToDate(long int beginningOfPeriod, long int endOfPeriod){
    vector <Income> localListOfIncomes = transactions -> incomes;
    vector <Expend> localListOfExpends = transactions -> expends;
    sort(localListOfIncomes.begin(), localListOfIncomes.end());
    sort(localListOfExpends.begin(), localListOfExpends.end());
    double expendFromPeriod = 0;
    double incomeFromPeriod = 0;
    cout << "Przychody:" << endl;
    for (int i = 0; i < localListOfIncomes.size(); i++){
        long int date = localListOfIncomes[i].getDate();
        if (beginningOfPeriod <= date && date <= endOfPeriod){
            localListOfIncomes[i].representIncome();
            incomeFromPeriod += localListOfIncomes[i].getAmount();
            }
    }
    cout << "Wydatki:" << endl;
    for (int i = 0; i < localListOfExpends.size(); i++){
        long int date = localListOfExpends[i].getDate();
        if (beginningOfPeriod <= date && date <= endOfPeriod){
            localListOfExpends[i].representExpend();
            expendFromPeriod += localListOfExpends[i].getAmount();
            }
    }
    cout << endl<< "W wybranym okresie wydano: " << expendFromPeriod << " Przychod wyniosl: " << incomeFromPeriod << endl << endl;
    cout << "Bilans w wybranym okresie: " << incomeFromPeriod - expendFromPeriod << endl;
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
