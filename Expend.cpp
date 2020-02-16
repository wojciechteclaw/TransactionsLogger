#include "Expend.h"

double Expend::getAmount(){
    return amount;
}

string Expend::getDescription(){
    return description;
}

long int Expend::getExpendDate(){
    return expendDate;
}

int Expend::getId(){
    return id;
}

int Expend::getUserId(){
    return userId;
}

void Expend::setAmount(double amountToSet){
    amount = amountToSet;
}

void Expend::setDescription(string desc){
    description = desc;
}

void Expend::setId(int newId){
    id = newId;
}

void Expend::setUserId(int newId){
    userId = newId;
}

void Expend::setExpendDate(long int newDate){
    expendDate = newDate;
}
