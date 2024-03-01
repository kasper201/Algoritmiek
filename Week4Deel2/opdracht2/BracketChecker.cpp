//
// Created by flits on 3/1/24.
//

#include "BracketChecker.h"
#include <iostream>

BracketChecker::BracketChecker(std::string input) {
    this->input = input;
}

BracketChecker::~BracketChecker() {

}

bool BracketChecker::check() {
    int length = input.length();
    Stack stack;

    for(int j = 0; j < length; j++){
        char ch = input[j];
        switch(ch)
        {
            case '{':
            case '[':
            case '(':
            case 'I':
            case 'D':
                stack.push(std::string(1, ch));
                break;

            case 'E':
                if(stack.isEmpty()){
                    std::cout << "Error: " << ch << " at " << j << std::endl;
                    return false;
                }
                if(stack.peek() != "I"){
                    std::cout << "Error: " << ch << " at " << j << std::endl;
                    return false;
                }
                stack.pop();
                break;
            case 'W':
                if(stack.isEmpty())
                    return true;
                if(stack.peek() == "D")
                    stack.pop();
                break;
            case '}':
            case ']':
            case ')':
                if(stack.isEmpty()){
                    std::cout << "Error: " << ch << " at " << j << std::endl;
                    return false;
                }
                std::string chx = stack.peek();
                if( (ch == '}' && chx != "{") || // ik vond dit deel erg lastig te begrijpen maar t is gelukt.
                    (ch == ']' && chx != "[") ||
                    (ch == ')' && chx != "(") ){
                    std::cout << "Error: " << ch << " at " << j << std::endl;
                    return false;
                }
                stack.pop();
                break;
            //default:
                //break;
        }
    }
    if(!stack.isEmpty()){
        while(stack.peek() == "I")
        {
            stack.pop();
            if(stack.isEmpty())
                return true;
        }
        std::cout << "Error: missing right delimiter" << std::endl;
        return false;
    }
    return true;
}