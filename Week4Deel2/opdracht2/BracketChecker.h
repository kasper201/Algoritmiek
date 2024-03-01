//
// Created by flits on 3/1/24.
//

#ifndef WEEK2DEEL2_BRACKETCHECKER_H
#define WEEK2DEEL2_BRACKETCHECKER_H

#include "Stack.h"
#include <string>

class BracketChecker {
public:
    BracketChecker(std::string input);
    virtual ~BracketChecker();
    bool check();
private:
    std::string input;
};


#endif //WEEK2DEEL2_BRACKETCHECKER_H
