//
// Created by Kasper on 29/02/2024.
//

#include "Stack.h"

Stack::Stack() {
    top = -1;
}

Stack::~Stack() {
}

void Stack::push(std::string value) {
    top++;
    stack[top] = value;
}

void Stack::pop() {
    top--;
}

std::string Stack::peek() {
    return stack[top];
}

bool Stack::isEmpty() const {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

bool Stack::isFull() const {
    if(top == size - 1) {
        return true;
    } else {
        return false;
    }
}

void Stack::print() {
    if(isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    }
    for(int i = 0; i <= top; i++) {
        std::cout << stack[i] << std::endl;
    }
}
