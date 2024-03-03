//
// Created by flits on 3/3/24.
//

#ifndef WEEK2DEEL2_CIRCUITINFO_H
#define WEEK2DEEL2_CIRCUITINFO_H
#include <string>

class CircuitInfo {
public:
    CircuitInfo();
    ~CircuitInfo();
    int circuit();
    std::string getRequest(const std::string &url);
    std::string correctCircuit(const std::string& input);
    int getCircuit(std::string circuit);
    int circuitImage(std::string circuitC); // corrected circuit
};


#endif //WEEK2DEEL2_CIRCUITINFO_H
