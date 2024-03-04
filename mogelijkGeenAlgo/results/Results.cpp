//
// Created by flits on 3/4/24.
//

#include "Results.h"
#include "htmlRequest.h"

#include <string>
#include <iostream>

Results::Results() {

}

Results::~Results() {

}

int Results::results(int year) {
    htmlRequest request;
    std::string url = "http://ergast.com/api/f1/" + std::to_string(year) + "/results.json";
    std::string response = request.getRequest(url);
    std::cout << "Response: " << response << std::endl;
    return 0;
}
