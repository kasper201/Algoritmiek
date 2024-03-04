//
// Created by flits on 3/4/24.
//

#ifndef WEEK2DEEL2_RESULTS_H
#define WEEK2DEEL2_RESULTS_H
#include "htmlRequest.h"
#include "CorrectJson.h"

class Results {
public:
    Results();
    virtual ~Results();
    int results(int year);
private:
    htmlRequest request;
    CorrectJson correctJson;
};


#endif //WEEK2DEEL2_RESULTS_H
