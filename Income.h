#ifndef INCOME_H
#define INCOME_H
#include <iostream>


using namespace std;

class Income{
    double amount;
    string description;
    long int incomeDate;
public:
    double getAmount();
    string getDescription();
    long int getIncomeDate();

    void setAmount(double);
    void setDescription(string);
    void setIncomeDate(long int);
};
#endif
