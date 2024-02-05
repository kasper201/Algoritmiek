#include "stdafx.h"
#include "IntOrderedArray.h"
#include <iostream>


IntOrderedArray::IntOrderedArray()
{
    index = 0;
}


IntOrderedArray::~IntOrderedArray()
{
    for(int i = 0; i < index - 1; i++)
        array[i] = 0;
}

void IntOrderedArray::exploreBinarySearch( int searchKey) const
{
// vul hier de broncode in voor vraag 3.a
    int lowerbound = 0;
    int upperbound = index - 1;
    int curIn;
    while(true)
    {
        curIn = (lowerbound + upperbound ) / 2;
        if(array[curIn] == searchKey)
        {
            std::cout << "Found " << searchKey << " at index " << curIn << std::endl;
            std::cout << "lowerbound: " << lowerbound << std::endl;
            std::cout << "upperbound: " << upperbound << std::endl;
            return;
        }
        else if(lowerbound > upperbound)
        {
            std::cout << "Can't find " << searchKey << std::endl;
            std::cout << "lowerbound: " << lowerbound << std::endl;
            std::cout << "upperbound: " << upperbound << std::endl;
            return;
        }
        else
        {
            if(array[curIn] < searchKey)
            {
                lowerbound = curIn + 1;
            }
            else
            {
                upperbound = curIn - 1;
            }
        }
    }
}

/*
 * vul hieronder de tabel in voor vraag 3.b
 *
 *    waarde  lowerbound    upperbound
 *      0       0            -1
 *      2       1            0
 *      4       2            1
 *      5       2            1
 *     23       6            5
 *     26       6            6
 *     30       7            6
 */

/*
 * formuleer hieronder het antwoord op vraag 3.c
 *
 * De relatie tussen de 'lowerbound' en 'upperbound' is dat de 'lowerbound' altijd kleiner is dan de 'upperbound'
 * tenzij de waarde die gezocht wordt niet in de array zit. In dat geval is de 'lowerbound' op denduur groter dan de 'upperbound'.
 *
 *
 */

int IntOrderedArray::getLastElementSmallerOrEqualTo( int value)   const // Ik snapte niet helemaal of je de plaats in de array wou of de waarde zelf.
{
    int lowerbound = 0;
    int upperbound = index - 1;
    int curIn;
    while(true)
    {
        curIn = (lowerbound + upperbound ) / 2;
        if(array[curIn] == value)
        {
            return curIn;
        }
        else if(lowerbound > upperbound)
        {
            return curIn;
        }
        else
        {
            if(array[curIn] < value)
            {
                lowerbound = curIn + 1;
            }
            else
            {
                upperbound = curIn - 1;
            }
        }
    }
}

void IntOrderedArray::moveElementsOnePositionToRight( int curIn)
{
    for(int i = index; i > curIn; i--)
    {
        array[i] = array[i - 1];
    }
}

int IntOrderedArray::quickInsert( int value )
{
    int lowerbound = 0;
    int upperbound = index - 1;
    int curIn;
    if(index == 0)
    {
        array[0] = value;
        index++;
        return 0;
    }
    while(true)
    {
        curIn = (lowerbound + upperbound ) / 2;
        if(array[curIn] == value)
        {
            std::cout << "Value " << value << " already exists at index " << curIn << std::endl;
            return -1;
        }
        else if(lowerbound > upperbound)
        {
            moveElementsOnePositionToRight(curIn + 1);
            array[curIn + 1] = value;
            index++;
            return curIn + 1;
        }
        else
        {
            if(array[curIn] < value)
            {
                lowerbound = curIn + 1;
            }
            else
            {
                upperbound = curIn - 1;
            }
        }
    }
    return -1;
}

void IntOrderedArray::showAll() const
{
    for ( int n = 0; n < index; n++ )
    {
        std::cout << array[n] << std::endl;
    }
}
