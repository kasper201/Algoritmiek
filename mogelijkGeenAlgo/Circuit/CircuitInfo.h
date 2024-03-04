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
    std::string findInHtml(std::string html);
    std::string findCircuitLength(int circuitNr, int year);
    std::string getRequest(const std::string &url);
    std::string correctCircuit(const std::string& input);
    int circuitImage(std::string circuitC); // corrected circuit
private:
    std::string getF1CircuitName(int circuitNr, int year);
    static std::string correctJson(const std::string& input);
};


#endif //WEEK2DEEL2_CIRCUITINFO_H
