#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include "Income.h"
#include "IncomeFile.h"
#include "Expend.h"
#include "ExpendFile.h"
#include "SupportingMethods.h"
#include <iostream>
#include <vector>

using namespace std;

class Transactions{
    //incomes vector
    //expends: vector
    //incomefile
    //expendFile
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
};

#endif
