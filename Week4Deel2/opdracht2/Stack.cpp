//
// Created by flits on 3/1/24.
//

#include "Stack.h"

#include <iostream>

Stack::Stack() {
    top = -1;

}

Stack::~Stack() {

}

void Stack::push(std::string value) {
    if (isFull()) {
        std::cout << "Stack is full" << std::endl;
    } else {
        stack[++top] = value;
    }
}

void Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        top--;
    }
}

std::string Stack::peek() {
    return stack[top];
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == 127;
}
