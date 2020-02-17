#ifndef EXPEND_H
#define EXPEND_H
#include <iostream>
#include "SupportingMethods.h"

using namespace std;

class Expend{
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
    void setId(int);
    void setUserId(int);
    void representExpend();
};

#endif
