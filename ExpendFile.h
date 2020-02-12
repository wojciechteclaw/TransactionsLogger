#ifndef EXPENDFILE_H
#define EXPENDFILE_H
#include <iostream>
#include <vector>
#include "Expend.h"

using namespace std;

class ExpendFile{

public:
    void addExpendToFile();
    vector<Expend> loadAllUserExpends(int);
    bool doesFileContainsExpends();
    int getLastExpendId();
};

#endif
