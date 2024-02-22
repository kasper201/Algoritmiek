#include "NAWLinkedList.h"

#include "NAW.h"
#include "NAWLink.h"

#include <iostream>

/*
 * opdracht 1
 */

NAWLinkedList::NAWLinkedList()
{
    first = nullptr;
    counter = 0;
}


NAWLinkedList::~NAWLinkedList()
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

void NAWLinkedList::addToStart( const NAW& naw)
{
    auto *link = new NAWLink();
    link->naw = naw;
    link->next = this->first;

    this->first = link;
    this->counter++;
}

NAWLink* NAWLinkedList::search(const NAW& naw) const
{
    auto* current = first;
    while (!(current->naw.heeftNaam(naw.getNaam()) &&
           current->naw.heeftAdres(naw.getAdres()) &&
           current->naw.heeftPlaats(naw.getPlaats())))
    {
        if(current->next == nullptr)
            return nullptr;
        else
            current = current->next;
    }
    return current;
}

void NAWLinkedList::showAll() const
{
    auto* current = first;
    while (current != nullptr)
    {
        std::cout << current->naw.getNaam() << " " << current->naw.getAdres() << " " << current->naw.getPlaats() << std::endl;
        current = current->next;
    }
}

NAWLink* NAWLinkedList::removeFirst( const NAW& )
{
    auto* current = first;
    first = first->next;
    counter--;
    return current;
}
