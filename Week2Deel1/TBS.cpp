//
// Created by Kasper on 06/02/2024.
//

#include "TBS.h"
#include <iostream>

TBS::TBS() {
    index = 0;
}

TBS::~TBS() {

}

void TBS::add(int value) {
    array[index] = value;
    index++;
}

void TBS::sort(bool ascending) {
    int temp;
    int i = 0;
    bool sorted = false;
    while(!sorted)
    {
        if(array[i] > array[i+1] && ascending)
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i = 0;
        }
        else if(array[i] < array[i+1] && !ascending)
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i = 0;
        }
        else
        {
            i++;
            if(i == 9)
            {
                sorted = true;
            }
        }
    }
}

void TBS::showAll() const {
    for(int i = 0; i < 10; i++)
    {
        std::cout << array[i] << std::endl;
    }
}
