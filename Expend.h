#ifndef EXPEND_H
#define EXPEND_H
#include <iostream>

using namespace std;

class Expend{
    double amount;
    string description;
    long int expendDate;
public:
    double getAmount();
    string getDescription();
    long int getExpendDate();

    void setAmount(double);
    void setDescription(string);
    void setExpendDate(long int);
};

#endif
