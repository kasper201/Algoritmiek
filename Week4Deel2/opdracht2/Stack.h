//
// Created by flits on 3/1/24.
//

#ifndef WEEK2DEEL2_STACK_H
#define WEEK2DEEL2_STACK_H

#include <string>

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
    std::string stack[128];
    int top;
};


#endif //WEEK2DEEL2_STACK_H
