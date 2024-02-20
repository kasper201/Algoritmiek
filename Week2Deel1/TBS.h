//
// Created by Kasper on 06/02/2024.
//

#ifndef WEEK2DEEL1_TBS_H
#define WEEK2DEEL1_TBS_H


class TBS {
public:
    TBS();
    virtual ~TBS();

public:
    void add(int value);
    void swap(int index1, int index2);
    void sort(bool ascending);
    void bubbleSort();
    void showAll() const;

private:
    int array[20];
    int index;
};


#endif //WEEK2DEEL1_TBS_H
