#include "IncomeFile.h"

bool IncomeFile::doesFileContainsIncomes(){
    CMarkup xml;
    xml.Load(fileName);
    xml.ResetPos();
    if (xml.FindElem("listOfIncomes")){
        xml.IntoElem();
        if (xml.FindElem("income")){
            return true;
        }
    }
    return false;
}

void IncomeFile::addIncomeToFile(Income newIncome){
    CMarkup xml;
    xml.Load(fileName);
    xml.ResetPos();
    if (doesFileContainsIncomes()){
        xml.FindElem("listOfIncomes");
        xml.IntoElem();
    }
    else{
        xml.AddElem("listOfIncomes");
        xml.IntoElem();
    }
    string amountAsString;
    xml.AddElem("income");
    xml.AddAttrib("id", newIncome.getId());
    xml.AddAttrib("userId", newIncome.getUserId());
    xml.AddAttrib("date", newIncome.getIncomeDate());
    amountAsString = SupportingMethods::convertDoubleToString(newIncome.getAmount());
    xml.AddAttrib("amount", amountAsString);
    xml.AddAttrib("description", newIncome.getDescription());
    xml.Save(fileName);
    lastIdOfIncome = newIncome.getId();
}

vector<Income> IncomeFile::loadAllUserExpends(int signedInUserId){
    CMarkup xml;
    vector <Income> incomes;
    xml.Load(fileName);
    xml.ResetPos();
    if (doesFileContainsIncomes()){
        xml.FindElem("listOfIncomes");
        xml.IntoElem();
        while (xml.FindElem("income")){
                if (signedInUserId == SupportingMethods::convertStringToInt(xml.GetAttrib("userId"))){
                    Income temporaryIncome;
                    temporaryIncome.setAmount(SupportingMethods::convertStringToDouble(xml.GetAttrib("amount")));
                    temporaryIncome.setDescription(xml.GetAttrib("description"));
                    temporaryIncome.setId(SupportingMethods::convertStringToInt(xml.GetAttrib("id")));
                    temporaryIncome.setUserId(SupportingMethods::convertStringToInt(xml.GetAttrib("userId")));
                    temporaryIncome.setIncomeDate(SupportingMethods::convertStringToInt(xml.GetAttrib("date")));
                    incomes.push_back(temporaryIncome);
                }
        }
        lastIdOfIncome = SupportingMethods::convertStringToInt(xml.GetAttrib("id"));
        return incomes;
    }
    else{
        lastIdOfIncome = 0;
        return incomes;
    }
}

int IncomeFile::getLastIncomeId(){
    return lastIdOfIncome;
}
