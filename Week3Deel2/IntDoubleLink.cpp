#include "IntDoubleLink.h"
#include <iostream>

IntDoubleLink::IntDoubleLink()
{
    value = 0;
    prev = nullptr;
    next = nullptr;
}

IntDoubleLink::IntDoubleLink( int v, IntDoubleLink* prev, IntDoubleLink* next)
{
    value = v;
    this->prev = prev;
    this->next = next;
}

IntDoubleLink::~IntDoubleLink()
{
    // Ensure next and prev are not null before deleting
    if (next != nullptr)
    {
        next->prev = nullptr;  // Set next's previous pointer to null to avoid dangling pointers
        delete next;           // Delete next link
    }

    if (prev != nullptr)
    {
        prev->next = nullptr;  // Set prev's next pointer to null to avoid dangling pointers
        delete prev;           // Delete prev link
    }
}

IntDoubleLink* IntDoubleLink::getPrev()
{
    return prev;
}

IntDoubleLink* IntDoubleLink::getNext()
{
    return next;
}