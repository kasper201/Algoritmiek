//
// Created by flits on 3/1/24.
//

#include <iostream>
#include "Queue.h"

#define size 256

Queue::Queue() {
    front = rear = 0;
}

Queue::~Queue() {

}

void Queue::insert(int n) {

    array[rear] = n;
    rear++;
    if(rear == size) {
        rear = 0;
    }
}

void Queue::remove() {
    if(front == rear) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    array[front] = 0;
    front++;
    if(front == size) {
        front = 0;
    }
}

void Queue::showAll() const {
    int i = front;
    while(i != rear)
    {
        std::cout << array[i] << std::endl;
        i++;
        if(i == size) {
            i = 0;
        }
    }
}

double Queue::peek() const {
    if(front == rear) {
        return 0.0;
    }
    return array[front];
}

int Queue::getCount() const {
    if(rear >= front) {
        return rear - front;
    }
    return (size - front) + rear;
}