#ifndef EXPENDFILE_H
#define EXPENDFILE_H
#include <iostream>
#include <vector>
#include "Expend.h"
#include "Markup.h"
#include "SupportingMethods.h"

using namespace std;

class ExpendFile{
    string fileName;
    int lastIdOfExpend;

public:
    ExpendFile(){
        fileName = "expends.xml";
    }
    void addExpendToFile(Expend);
    vector<Expend> loadAllUserExpends(int);
    bool doesFileContainsExpends();
    int getLastExpendId();
};

#endif
