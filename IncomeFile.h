#ifndef INCOMEFILE_H
#define INCOMEFILE_H
#include <iostream>
#include <vector>
#include "Income.h"

using namespace std;

class IncomeFile{

public:
    void addIncomeToFile();
    vector<Income> loadAllUserExpends(int);
    bool doesFileContainsIncomes();
    int getLastIncomeId();
};

#endif
