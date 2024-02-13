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

void TBS::swap(int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
    std::cout << "New Swap" << std::endl;
    showAll();
}

void TBS::selectionSort() {
    int out, in, min;

    for(out = 0; out < index-1; out++) {
        min = out;
        for (in = out + 1; in < index; in++) {
            if (array[in] > array[min]) {
                min = in;
            }
        }
        swap(out, min);
    }
}

void TBS::showAll() const {
    for(int i = 0; i < 10; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
