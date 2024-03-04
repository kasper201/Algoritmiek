//
// Created by Kasper on 26/02/2024.
//

#ifndef WEEK2DEEL2_DRIVERINFO_H
#define WEEK2DEEL2_DRIVERINFO_H

#include "CorrectJson.h"
#include "htmlRequest.h"

#include <string>
#include <map>
#include <vector>

class driverinfo {
public:
    driverinfo();
    ~driverinfo();
    int driver(int year);
private:
    void getTeam(std::string driver);
    int driverImage(std::string driver);

private:
    std::map<std::string, std::vector<std::string>> teams;
    htmlRequest request;
    CorrectJson correctJson;
    int year;
};


#endif //WEEK2DEEL2_DRIVERINFO_H
