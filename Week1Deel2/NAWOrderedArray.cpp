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
    if(called <= 1)
    {
        array[index] = new NAW(naw.getNaam(), naw.getAdres(), naw.getPlaats());
        called++;
        index++;
        return 1;
    }
    int temp;
    int temp2;
    int indexmin1;
    for(int i = 0; i < index; i++)
    {
        temp = array[i]->compareTo(naw);
        temp2 = array[i + 1]->compareTo(naw);
        indexmin1 = array[index - 1]->compareTo(naw);
        if(temp == 0)
            return -1;
        else if(temp == 1)
            continue;
        else if(temp == -1 && temp2 == 1)
        {
            for(int j = index; j > i; j--)
            {
                array[j] = array[j - 1];
            }
            array[i] = new NAW(naw.getNaam(), naw.getAdres(), naw.getPlaats());
            index++;
            return 1;
        }
        else if (temp == -1 && temp2 == -1 && indexmin1 == -1) {
            array[index] = new NAW(naw.getNaam(), naw.getAdres(), naw.getPlaats());
            index++;
            return 1;
        }
        else if (temp == -1 && temp2 == -1 && indexmin1 == 1)
        {

        }
    }
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
    int err = remove(cOld);
    if(err == -1)
        return -1;
    err = add(cNew);
    if(err == -1)
        return -1;
    return 0;
}

void NAWOrderedArray::showAll() const
{
    for(int i = 0; i < index; i++)
    {
        std::cout << array[i]->getNaam() << " " << array[i]->getAdres() << " " << array[i]->getPlaats() << std::endl;
    }
}
