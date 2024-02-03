#include "stdafx.h"
#include "NAWOrderedArray.h"
#include "NAW.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// constructor / destructor

NAWOrderedArray::NAWOrderedArray()
{
    index = 0;
    for(int i = 0; i < 10; i++)
    {
        array[i] = new NAW();
    }
}


NAWOrderedArray::~NAWOrderedArray()
{
    for(int i = 0; i < 10; i++)
    {
        delete array[i];
    }
}

///////////////////////////////////////////////////////////////////////////////
// find, add, remove, replace...

int NAWOrderedArray::find( const NAW& input) const
{
    int max = 10;
    int min = 0;
    int i = max / 2;
    int temp;
    while(i != max)
    {
        temp = array[i]->compareTo(input);

        //std::cout << i << std::endl;
        //std::cout << temp << std::endl;

        if(temp == 0)
            return i;
        else if(temp == 1)
        {
            max = i - 1;
            i = (max + min) / 2;
        }
        else if(temp == -1)
        {
            min = i + 1;
            i = (max + min) / 2;
        }
    }
    return -1;
}

int NAWOrderedArray::add( const NAW& naw)
{
    //if(array[index - 1]->compareTo(naw) == -1)
    array[index] = new NAW(naw.getNaam(), naw.getAdres(), naw.getPlaats());
    index++;
    return 1;
}

int NAWOrderedArray::remove( const NAW& verwijder)
{
    int rem = find(verwijder);
    if(rem == -1)
        return -1;
    delete array[rem];
    for(int i = rem; i < index; i++)
    {
        array[i] = array[i + 1];
    }
    return 1;
}

int NAWOrderedArray::replace( const NAW& cOld, const NAW& cNew )
{
    return -1;
}

void NAWOrderedArray::showAll() const
{
    for(int i = 0; i < 10; i++)
    {
        std::cout << array[i]->getNaam() << " " << array[i]->getAdres() << " " << array[i]->getPlaats() << std::endl;
    }
}