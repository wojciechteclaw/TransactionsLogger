#include "ExpendFile.h"

bool ExpendFile::doesFileContainsExpends(){
    CMarkup xml;
    xml.Load(fileName);
    xml.ResetPos();
    if (xml.FindElem("listOfExpends")){
        xml.IntoElem();
        if (xml.FindElem("expend")){
            return true;
        }
    }
    return false;
}

void ExpendFile::addExpendToFile(Expend newExpend){
    CMarkup xml;
    xml.Load(fileName);
    xml.ResetPos();
    if (doesFileContainsExpends()){
        xml.FindElem("listOfExpends");
        xml.IntoElem();
    }
    else{
        xml.AddElem("listOfExpends");
        xml.IntoElem();
    }
    string amountAsString;
    xml.AddElem("expend");
    xml.AddAttrib("id", newExpend.getId());
    xml.AddAttrib("userId", newExpend.getUserId());
    xml.AddAttrib("date", newExpend.getDate());
    amountAsString = SupportingMethods::convertDoubleToString(newExpend.getAmount());
    xml.AddAttrib("amount", amountAsString);
    xml.AddAttrib("description", newExpend.getDescription());
    xml.Save(fileName);
    lastIdOfExpend = newExpend.getId();
}

vector<Expend> ExpendFile::loadAllUserExpends(int signedInUserId){
    CMarkup xml;
    vector <Expend> expends;
    xml.Load(fileName);
    xml.ResetPos();
    if (doesFileContainsExpends()){
        xml.FindElem("listOfExpends");
        xml.IntoElem();
        while (xml.FindElem("expend")){
                if (signedInUserId == SupportingMethods::convertStringToInt(xml.GetAttrib("userId"))){
                    Expend temporaryExpend;
                    temporaryExpend.setAmount(SupportingMethods::convertStringToDouble(xml.GetAttrib("amount")));
                    temporaryExpend.setDescription(xml.GetAttrib("description"));
                    temporaryExpend.setId(SupportingMethods::convertStringToInt(xml.GetAttrib("id")));
                    temporaryExpend.setUserId(SupportingMethods::convertStringToInt(xml.GetAttrib("userId")));
                    temporaryExpend.setDate(SupportingMethods::convertStringToInt(xml.GetAttrib("date")));
                    expends.push_back(temporaryExpend);
                }
        }
        lastIdOfExpend = SupportingMethods::convertStringToInt(xml.GetAttrib("id"));
        return expends;
    }
    else {
        lastIdOfExpend = 0;
        return expends;
    }
}

int ExpendFile::getLastExpendId(){
    return lastIdOfExpend;
}
