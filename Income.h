#ifndef INCOME_H
#define INCOME_H
#include <iostream>


using namespace std;

class Income{
    double amount;
    string description;
    long int incomeDate;
    int id;
    int userId;

public:
    double getAmount();
    string getDescription();
    long int getIncomeDate();
    int getId();
    int getUserId();

    void setAmount(double);
    void setDescription(string);
    void setIncomeDate(long int);
    void setUserId(int);
    void setId(int);
};
#endif
