//
// Created by flits on 3/1/24.
//
#include "BracketChecker.h"

#include <iostream>
#include <fstream>

#define inputString "I(){}W{}[]"

std::string enterString() {
    std::ifstream file;

    std::cout << "Use file, use default or enter string? (f/d/s): ";
    std::string choice;
    std::cin >> choice;
    if (choice == "f" || choice == "F") {
        std::cout << "Enter absolute path: ";
        std::cin >> choice;
        file.open(choice);
        if (!file) {
            std::cout << "File not found" << std::endl;
            return enterString();
        } else {
                std::string line;
                std::string result;
                while (std::getline(file, line)) {
                    result += line;
                }
                return result;
            }
    } else if (choice == "d" || choice == "D") {
        return inputString;
    } else {
        std::cout << "Enter string: ";
        std::cin >> choice;
        return choice;
    }
}

// is dit niet gewoon opdracht 1 van week 4 deel 1 maar dan met haakjes ipv xml?
// Dit oogt wel simpeler dan wat ik heb gedaan 😅😅':D
int main() {
    while(1) {
        BracketChecker bc(enterString());
        if (bc.check()) {
            std::cout << "Correct" << std::endl;
        } else {
            std::cout << "Incorrect" << std::endl;
        }
        std::cout << "Another? (y/n): ";
        std::string choice;
        std::cin >> choice;
        if (choice == "n" || choice == "N")
            break;
    }
    std::cout << "Goodbye" << std::endl;
    return 0;
}