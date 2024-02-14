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

void TBS::clear() {
    for(int i = 0; i < index; i++)
    {
        rij[i] = 0;
    }
    index = 0;
}

void TBS::add(int value) {
    rij[index] = value;
    index++;
}

void TBS::swap(int index1, int index2) {
    int temp = rij[index1];
    rij[index1] = rij[index2];
    rij[index2] = temp;
    std::cout << "New Swap" << std::endl;
    showAll();
}

void TBS::selectionSort() {
    int out, in, min;

    for(out = 0; out < index-1; out++) {
        min = out;
        for (in = out + 1; in < index; in++) {
            if (rij[in] > rij[min]) {
                min = in;
            }
        }
        swap(out, min);
    }
}

void TBS::insertionSort(int start) {
    int in, out;
    for(out = start + 1; out < index; out++) {
        int temp = rij[out];
        in = out;
        while(in > 0 && rij[in-1] >= temp) {
            rij[in] = rij[in-1];
            --in;
        }
        rij[in] = temp;
        std::cout << "New Swap" << std::endl;
        showAll();
    }
}

void TBS::showAll() const {
    for(int i = 0; i < 10; i++)
    {
        std::cout << rij[i] << " ";
    }
    std::cout << std::endl;
}
