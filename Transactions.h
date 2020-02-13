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
    vector <Income> incomes;
    vector <Expend> expends;
    IncomeFile incomeFile;
    ExpendFile expendFile;
    int lastIncomeId;
    int lastExpendId;
    const int SIGNEDINUSERID;
    vector <Income> loadIncomes();
    vector <Expend> loadExpenses();
    void loadUserBudget();
    int getNumberOfDaysInMonth(int, int);

public:
    Transactions(int signedInUserId) :SIGNEDINUSERID(signedInUserId) {};
    void addIncome();
    void addExpend();
    long int getCurrentDate();
    bool checkIfDateIsCorrect(int, int, int, string);
    long int getDateFromString(string);
};

#endif
