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
    void clear();
    void add(int value);
    void swap(int index1, int index2);
    void selectionSort();
    void insertionSort(); // start is the index where the sorting starts + 1 since the first element is always sorted
    void showAll() const;

private:
    int rij[20];
    int index;
};


#endif //WEEK2DEEL1_TBS_H
