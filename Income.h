#ifndef INCOME_H
#define INCOME_H
#include <vector>
#include <iostream>
#include "SupportingMethods.h"


using namespace std;

class Income{
    double amount;
    string description;
    long int date;
    int id;
    int userId;

public:
    double getAmount();
    string getDescription();
    long int getDate();
    int getId();
    int getUserId();

    void setAmount(double);
    void setDescription(string);
    void setDate(long int);
    void setUserId(int);
    void setId(int);
    void representIncome();
};
#endif
