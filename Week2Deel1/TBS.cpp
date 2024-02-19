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

void TBS::sort(bool ascending) {
    int i = 0;
    bool sorted = false;
    int count = 0;
    while(!sorted)
    {
        if((ascending ? (array[i] > array[i+1]) : (array[i] < array[i+1])))
        {
            count++;
            swap(i, i+1);
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
    std::cout << "Swaps: " << count << std::endl;
    std::cout << "sorting " << (ascending ? "ascending" : "descending") << " completed" << std::endl;
}

void TBS::bubbleSort() {
    int in, out;
    int swaps = 0;
    for(out = 0; out < index - 1; out++)
    {
        for(in = 0; in < index - out - 1; in++)
        {
            if(array[in] > array[in + 1])
            {
                swap(in, in + 1);
                swaps++;
            }
        }
    }
    std::cout << "sorting completed" << std::endl;
    std::cout << "Total Swaps: " << swaps << std::endl;
}

void TBS::bubbleSort2() {
    int in, out;
    int swaps = 0;
    for(out = index - 1; out > 0; out--)
    {
        for(in = 0; in < out; in++)
        {
            if(array[in] > array[in + 1])
            {
                swap(in, in + 1);
                swaps++;
            }
        }
    }
    std::cout << "sorting completed" << std::endl;
    std::cout << "Total Swaps: " << swaps << std::endl;
}

void TBS::showAll() const {
    for(int i = 0; i < 10; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
