#include "driverinfo.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

driverinfo::driverinfo()
{

}

driverinfo::~driverinfo()
{
}

int driverinfo::driver() {
    // Specify the path to your JSON file
    std::string filePath = "C:\\Users\\Kasper\\Downloads\\Agoritmiek\\.idea\\httpRequests\\2024-02-26T141655.200.json";

    // Read JSON data from file
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonData = buffer.str();

    // Parse JSON
    std::istringstream stream(jsonData);
    std::vector<std::string> givenNames, familyNames, nationalities, permanentNumbers, fullNames;
    while (stream) {
        std::string token;
        stream >> token;
        if (token == "\"givenName\":") {
            std::string givenName;
            stream >> std::quoted(givenName);
            givenNames.push_back(givenName);
        } else if (token == "\"familyName\":") {
            std::string familyName;
            stream >> std::quoted(familyName);
            familyNames.push_back(familyName);
        } else if (token == "\"nationality\":") {
            std::string nationality;
            stream >> std::quoted(nationality);
            nationalities.push_back(nationality);
        } else if(token == "\"permanentNumber\":") {
            std::string permanentNumber;
            stream >> std::quoted(permanentNumber);
            permanentNumbers.push_back(permanentNumber);
        }
    }

    // Print names and nationalities
    for (size_t i = 0; i < givenNames.size(); ++i) {
        fullNames.push_back(givenNames[i] + " " + familyNames[i]);
        std::cout << i << " - Nationality: " << nationalities[i] << " full name: " << fullNames[i] << " Permanent number: " << permanentNumbers[i] << std::endl;
    }

    return 0;
}