#ifndef INCOMEFILE_H
#define INCOMEFILE_H
#include <iostream>
#include <vector>
#include "Income.h"
#include "Markup.h"
#include "SupportingMethods.h"

using namespace std;

class IncomeFile{
    string fileName;
    int lastIdOfIncome;

public:
    IncomeFile(){
        fileName = "incomes.xml";
    }
    void addIncomeToFile(Income);
    vector<Income> loadAllUserExpends(int);
    bool doesFileContainsIncomes();
    int getLastIncomeId();
};

#endif
