#include "Income.h"

double Income::getAmount(){
    return amount;
}

string Income::getDescription(){
    return description;
}

long int Income::getIncomeDate(){
    return incomeDate;
}

int Income::getId(){
    return id;
}

int Income::getUserId(){
    return userId;
}

void Income::setAmount(double amountToSet){
    amount = amountToSet;
}

void Income::setDescription(string desc){
    description = desc;
}

void Income::setId(int newId){
    id = newId;
}

void Income::setUserId(int newId){
    userId = newId;
}

void Income::setIncomeDate(long int newDate){
    incomeDate = newDate;
}
