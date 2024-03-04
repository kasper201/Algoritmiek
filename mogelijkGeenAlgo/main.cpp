#include <iostream>
#include "Driver info/driverinfo.h" // MN OGEN AAAAA WAAROM HEB IK HIER EEN SPATIE IN DE DIR GEDAAN??!?!?!?!
#include "Circuit/CircuitInfo.h"
#include "results/Results.h"

#include <fstream>
#include <sstream>

int getAmountOfRaces(int year) {
    std::string url = "https://ergast.com/api/f1/" + std::to_string(year) + ".json";
    htmlRequest request;
    std::string response = request.getRequest(url);
    CorrectJson correctJson;
    std::string correctedJson = correctJson.correctJson(response);
    std::ofstream fileSave("tempAmountOfRaces.json", std::ios::trunc);
    fileSave << correctedJson;
    fileSave.close();
    std::ifstream file("tempAmountOfRaces.json");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();
    std::istringstream stream(data);
    std::string token;
    int amountOfRaces = 0;
    while(stream) {
        stream >> token;
        if(token == "\"rounds\":") {
            stream >> amountOfRaces;
            break;
        }
    }
    return amountOfRaces;
}

int main() {
    driverinfo driverinfo;
    CircuitInfo circuitInfo;
    Results results;
    //driverinfo.driver();
    //circuitInfo.circuit();
    results.results(2023, 9);
    return 0;
}