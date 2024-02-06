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
    void sort(bool ascending);
    void showAll() const;

private:
    int array[10];
    int index;
};


#endif //WEEK2DEEL1_TBS_H
