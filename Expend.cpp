#include "Expend.h"

void Expend::representExpend(){
    string dateToPresentToUser = SupportingMethods::convertNumberToDateRepresentation(getDate());
    cout << dateToPresentToUser << "  " << getAmount() << "  " << getDescription() << endl;
}

double Expend::getAmount(){
    return amount;
}

string Expend::getDescription(){
    return description;
}

long int Expend::getDate(){
    return date;
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

void Expend::setDate(long int newDate){
    date = newDate;
}
