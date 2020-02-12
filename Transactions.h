#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <iostream>

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
