//
// Created by Kasper on 26/02/2024.
//

#ifndef WEEK2DEEL2_DRIVERINFO_H
#define WEEK2DEEL2_DRIVERINFO_H

#include <string>
#include <map>
#include <vector>

class driverinfo {
public:
    driverinfo();
    ~driverinfo();
    int driver();
private:
    void getTeam(std::string driver);
    static std::string correctJson(const std::string& input);
    int driverImage(std::string driver);

private:
    std::map<std::string, std::vector<std::string>> teams;
};


#endif //WEEK2DEEL2_DRIVERINFO_H
