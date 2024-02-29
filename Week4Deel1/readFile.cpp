//
// Created by Kasper on 29/02/2024.
//

#include "readFile.h"
#include "validator.h"

#include <iostream>
#include <fstream>

readFile::readFile()= default;

readFile::~readFile() = default;

void readFile::read(Stack &stack) {
    validator validator;
    std::ifstream file;
    std::string fileLocation;
    std::cout << "Enter absolute path: ";
    std::cin >> fileLocation;
    std::cout << std::endl;
    file.open(fileLocation);
    if (!file) {
        std::cout << "File not found" << std::endl;
    } else {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            if(!validator.setXml(stack, line))
                return;
        }
    }
    file.close();
}
