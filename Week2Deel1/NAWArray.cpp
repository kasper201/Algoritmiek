#include "stdafx.h"
#include "NAWArray.h"
#include "NAW.h"

#include <sstream>
#include <iostream>

NAWArray::NAWArray()
{
    index = 0;
    for(int i = 0; i < 10; i++)
    {
        array[i] = new NAW();
    }
}

NAWArray::~NAWArray()
{
    for (int i = 0; i < index - 1; i++)
        delete array[i];
}

void NAWArray::add( const NAW& naw)
{
    array[index] = new NAW(naw);
    std::cout << "\nAdded: " << std::endl;
    std::cout << array[index]->getNaam() << std::endl;
    std::cout << array[index]->getAdres() << std::endl;
    std::cout << array[index]->getPlaats() << std::endl;
    index++;
}

void NAWArray::swap(int index1, int index2) {
    NAW* temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void NAWArray::sort() {
    int outer, inner;
    for (outer = index - 1; outer > 1; outer--)
    {
        for (inner = 0; inner < outer; inner++)
        {
            if (array[inner]->getNaam() > array[inner + 1]->getNaam())
            {
                swap(inner, inner + 1);
            }
        }
    }
}

void NAWArray::sortWoonplaats() {
    int outer, inner;
    for (outer = index - 1; outer > 1; outer--)
    {
        for (inner = 0; inner < outer; inner++)
        {
            if (array[inner]->getPlaats() > array[inner + 1]->getPlaats())
            {
                swap(inner, inner + 1);
            }
        }
    }
}

void NAWArray::showAll() const {
    for (int i = 0; i < index; i++)
    {
        std::cout << array[i]->getNaam() << " " << array[i]->getAdres() << " " << array[i]->getPlaats() << std::endl;
    }
}
