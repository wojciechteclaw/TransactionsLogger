#include "Income.h"

void Income::representIncome(){
    string dateToPresentToUser = SupportingMethods::convertNumberToDateRepresentation(getDate());
    cout << dateToPresentToUser << "  " << getAmount() << "  " << getDescription() << endl;
}

double Income::getAmount(){
    return amount;
}

string Income::getDescription(){
    return description;
}

long int Income::getDate(){
    return date;
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

void Income::setDate(long int newDate){
    date = newDate;
}
