#include "IntLinkedList.h"

#include "IntLink.h"

#include <iostream>

IntLinkedList::IntLinkedList()
{
    first = nullptr;
    counter = 0;
}


IntLinkedList::~IntLinkedList()
{
    auto* current = first;
    for(int i = 0; i < counter; i++)
    {
        auto* next = current->next;
        //delete current;
        current = next;
    }
    first = nullptr;
    counter = 0;
}

IntLink* IntLinkedList::getAt( int n ) const //O(N)
{
    if(this->first == nullptr || n < 0 || n >= counter)
        return nullptr;

    auto* current = first; // first is a pointer to the first link in the list
    for (int i = 0; i < n; i++)
    {
        current = current->next;
    }
    return current;
}

bool IntLinkedList::setAt( int pos, int n)
{
    bool succeeded = false;

    if(this->first == nullptr)
        return false;

    if (pos >= 0 && pos < counter)
    {
        auto* current = first; // first is a pointer to the first link in the list
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        current->value = n;
        succeeded = true;
    }

    return succeeded;
}

int IntLinkedList::length1() const // ik denk dat dit juist is??
{
    int length = 0;
    auto* current = first;
    while (current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

int IntLinkedList::length2() const
{
    return counter;
}

void IntLinkedList::bubbleSort()
{
    int in, out;
    int swaps = 0;
    for(out = counter - 1; out > 1; out--)
    {
        for(in = 0; in < out; in++)
        {
            if(getAt(in)->value > getAt(in + 1)->value)
            {
                int temp = getAt(in)->value;
                setAt(in, getAt(in + 1)->value);
                setAt(in + 1, temp);
                swaps++;
            }
        }
    }
}

/*
 *  geschatte snelheid van dit algoritme: O(N²)
 *  onderbouwing: het is een bubble sort algoritme die alle waarden met elkaar vergelijkt
 *  met behulp van twee for loops.
 *
 *
 */

 /*
 * metingen van de duur van het sorteren...
 *
 *    aantal waarden:       duur in us:
 *        1000              506683
 *        2000              4455546
 *        5000              64765134
 *       10000              536590465 (8.94 minuten)
 *         ...
  *      Ik ga niet verder dan 10 000 want dat duurt al bijna 9 minuten en het is duidelijk dat het algoritme O(N²) is.
 */  

/*
 *  gemeten snelheid van dit algoritme: O(N³)
 *  onderbouwing: bij een verdubbeling van de input, neemt de tijd exponentieel toe met bij een verdubbeling van de input
 *  een factor van 8.
 *  dit is een indicatie dat het algoritme O(N³) is.
 *
 *
 */

void IntLinkedList::addToStart( int n)
{
    auto *link = new IntLink(n, this->first); // IntLink( int v, IntLink* link
    this->first = link;
    this->counter++;
}

void IntLinkedList::showAll() const
{
    auto* current = first;
    while (current != nullptr)
    {
        std::cout << current->value << std::endl;
        current = current->next;
    }
}
