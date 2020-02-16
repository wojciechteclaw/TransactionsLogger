#ifndef EXPEND_H
#define EXPEND_H
#include <iostream>

using namespace std;

class Expend{
    double amount;
    string description;
    long int expendDate;
    int id;
    int userId;

public:
    double getAmount();
    string getDescription();
    long int getExpendDate();
    int getId();
    int getUserId();

    void setAmount(double);
    void setDescription(string);
    void setExpendDate(long int);
    void setId(int);
    void setUserId(int);
};

#endif
