//
// Created by Kasper on 29/02/2024.
//

#ifndef WEEK2DEEL2_VALIDATOR_H
#define WEEK2DEEL2_VALIDATOR_H

#include "Stack.h"

#include <iostream>
#include <string>

class validator {
public:
    validator();
    virtual ~validator();
    bool validate(Stack& stack, std::string xml);
    bool setXml(Stack& stack, std::string xml);
private:
    bool first = true;
};


#endif //WEEK2DEEL2_VALIDATOR_H
