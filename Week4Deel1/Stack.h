//
// Created by Kasper on 29/02/2024.
//

#ifndef WEEK2DEEL2_STACK_H
#define WEEK2DEEL2_STACK_H

#include <iostream>
#include <string>

#define size 128

class Stack {
public:
    Stack();
    virtual ~Stack();
    void push(std::string value);
    void pop();
    std::string peek();
    bool isEmpty() const;
    bool isFull() const;
    void print();
private:
    std::string stack[size];
    int top;
};


#endif //WEEK2DEEL2_STACK_H
