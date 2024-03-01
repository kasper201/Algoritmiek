//
// Created by flits on 3/1/24.
//

#ifndef WEEK2DEEL2_QUEUE_H
#define WEEK2DEEL2_QUEUE_H

class Queue {
public:
    Queue();
    virtual ~Queue();
    void insert(int);
    void remove();
    void showAll() const;
    double peek() const;
    int getCount() const;
private:
    double array[256];
    int front, rear;
};

#endif //WEEK2DEEL2_QUEUE_H
