#ifndef USERSBUDGETMANAGER_H
#define USERSBUDGETMANAGER_H
#include "SupportingMethods.h"
#include "Transactions.h"
#include <iostream>

using namespace std;

class UsersBudgetManager{
    const int SIGNEDINUSERID;
    Transactions *transactions;
    long int getBeginingOfTheCurrentMonth();

public:
    UsersBudgetManager(int signedInUserId) : SIGNEDINUSERID(signedInUserId)
    {
        transactions = new Transactions(SIGNEDINUSERID);
    }
    ~UsersBudgetManager(){
        delete transactions;
        transactions = NULL;
    }
    void addIncome();
    void addExpend();
    void generateReportFromCurrentMonth();
    void generateReportFromPreviousMonth();
    void generateReportFromCustomDate();
};

#endif
