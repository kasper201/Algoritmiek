//
// Created by flits on 3/4/24.
//

#include "Results.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Results::Results() {

}

Results::~Results() {

}

int Results::results(int year) {
    std::string url = "http://ergast.com/api/f1/" + std::to_string(year) + "/results.json";
    std::string response = request.getRequest(url);
    std::cout << "Response: " << response << std::endl;

    // Correct JSON for readability
    std::string correctedJson = correctJson.correctJson(response);

    std::ofstream fileSave("tempResults.json", std::ios::trunc);
    fileSave << correctedJson;
    fileSave.close();

    // Read JSON data from file
    std::ifstream file("tempResults.json");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();


    return 0;
}
