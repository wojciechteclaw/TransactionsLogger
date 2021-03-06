#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include "Income.h"
#include "IncomeFile.h"
#include "Expend.h"
#include "ExpendFile.h"
#include "SupportingMethods.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>


using namespace std;

class Transactions{

    IncomeFile incomeFile;
    ExpendFile expendFile;
    const int SIGNEDINUSERID;
    vector <Income> loadIncomes();
    vector <Expend> loadExpenses();
    void loadUserBudget();
    bool checkIfDateIsCorrect(int, int, int, string);
    int getNumberOfDaysInMonth(int, int);
    double getAmount();
    string replaceCommaInString(string);
    long int getDate();

public:
    Transactions(int signedInUserId) :SIGNEDINUSERID(signedInUserId) {
        incomes = incomeFile.loadAllUserExpends(SIGNEDINUSERID);
        expends = expendFile.loadAllUserExpends(SIGNEDINUSERID);
    };
    void addIncome();
    void addExpend();
    long int getCurrentDate();
    long int getDateFromString(string);
    vector <Income> incomes;
    vector <Expend> expends;
    void representIncome(Income);
    void representExpend(Expend);
    long int getPreviousMonthStartDay();
    long int getPreviousMonthEndDay();



};

#endif
