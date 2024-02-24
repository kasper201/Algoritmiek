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
    while (current != nullptr)
    {
        auto* next = current->next;
        delete current;
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
}

/*
 *  geschatte snelheid van dit algoritme: O(...)
 *  onderbouwing:
 *
 *
 */

 /*
 * metingen van de duur van het sorteren...
 *
 *    aantal waarden:       duur in us:
 *        1000
 *        2000
 *        5000
 *       10000
 *         ...
 */  

/*
 *  gemeten snelheid van dit algoritme: O(...)
 *  onderbouwing:
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
