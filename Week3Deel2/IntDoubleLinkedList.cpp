#include "IntDoubleLinkedList.h"
#include "IntDoubleLink.h"
#include <iostream>

IntDoubleLinkedList::IntDoubleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->counter = 0;
}

IntDoubleLinkedList::~IntDoubleLinkedList()
{
    IntDoubleLink* current = head;
    IntDoubleLink* nextLink;

    // Iterate through the linked list and delete each element
//    while (current != nullptr) {
//        std::cout << "current: " << current << std::endl;
//        auto *temp = current->getNext();
//        if(temp == current)
//            break;
//        nextLink = temp;
//        delete current;
//        current = nextLink; // Move to the next link before deleting the current one
//    }

    head = nullptr;
    tail = nullptr;
    counter = 0;
}

void IntDoubleLinkedList::insertAtStart( int v )
{
    if (this->head == nullptr) {
        // If the list is empty, create the first link and set both head and tail to it
        this->head = new IntDoubleLink(v, nullptr, nullptr);
        this->tail = this->head;
    } else {
        // If the list is not empty, insert the new link at the start
        auto *link = new IntDoubleLink(v, nullptr, this->head);
        this->head->prev = link;
        this->head = link;
    }
    this->counter++;
}

void IntDoubleLinkedList::insertAtEnd(int v)
{
    if (this->head == nullptr) {
        // If the list is empty, create the first link and set both head and tail to it
        this->head = new IntDoubleLink(v, nullptr, nullptr);
        this->tail = this->head;
    } else {
        // If the list is not empty, insert the new link at the end
        auto *link = new IntDoubleLink(v, this->tail, nullptr);
        this->tail->next = link;
        this->tail = link;
    }
    this->counter++;
}

bool IntDoubleLinkedList::removeAtStart() //O(1) if error then true else false
{
    bool err;
    if(this->head != nullptr)
    {
        auto* next = this->head->getNext();
        delete this->head;
        this->head = next;
        this->counter--;
        err = false;
    }
    else
        err = true;
    return err;
}

bool IntDoubleLinkedList::removeAtEnd() //O(1) if error then true else false
{
    bool err;
    if(this->tail != nullptr)
    {
        auto* prev = this->tail->getPrev();
        delete this->tail;
        this->tail = prev;
        this->counter--;
        err = false;
    }
    else
        err = true;
    return err;
}

IntDoubleLink* IntDoubleLinkedList::getHead()
{
    return this->head;
}

IntDoubleLink* IntDoubleLinkedList::getTail()
{
    return this->tail;
}

void IntDoubleLinkedList::rapidBubbleSort()
{
    for (int i = 0; i < this->counter - 1; i++)
    {
        auto *current = this->head;
        for (int j = 0; j < this->counter - i - 1; j++)
        {
            if (current->getNext() != nullptr)
            {
                if (current->value > current->getNext()->value)
                {
                    int temp = current->value;
                    current->value = current->getNext()->value;
                    current->getNext()->value = temp;
                }
                current = current->getNext();
            }
            else
                return;
        }
    }
}


/*
 * metingen van de duur van het sorteren...
 *
 *    aantal waarden:       duur in us:
 *        1000              6366
 *        2000              18345
 *        5000              315444
 *       10000              1301451
 *         ...
 */  

/*
 *  gemeten snelheid van dit algoritme: O(N²)
 *  onderbouwing: het is een bubble sort algoritme die alle waarden met elkaar vergelijkt en duurt
 *  bij een verdubbeling van de waarden ongeveer 4 keer zo lang.
 *
 *  Bij het testen is de else statement uitgecomment om zo de snelheid van het algoritme beter te meten.
 *
 *
 */

/*
 *  Vergelijking met bubblesort van week 3 deel 1
 *  De sneleheid van dit algoritme is vele male hoger dan die van week 3 deel 1.
 *
 */

void IntDoubleLinkedList::insertAction( int v )
{
    if (this->head == nullptr) {
        // If the list is empty, create the first link and set both head and tail to it
        this->head = new IntDoubleLink(v, nullptr, nullptr);
        this->tail = this->head;
    } else {
        // If the list is not empty, insert the new link at the end
        auto *link = new IntDoubleLink(v, this->tail, nullptr);
        this->tail->next = link;
        this->tail = link;
    }
    this->counter++;
}

int IntDoubleLinkedList::undo()
{
    if(this->tail != nullptr && this->tail->getPrev() != nullptr)
        this->tail = this->tail->getPrev();
    return this->tail->value; // return current value/action...
}

int IntDoubleLinkedList::redo()
{
    if(this->tail != nullptr && this->tail->getNext() != nullptr)
        this->tail = this->tail->getNext();
    return this->tail->value; // return current value/action...
}

int IntDoubleLinkedList::getCurrentAction()
{
    return this->tail->value;
}

void IntDoubleLinkedList::showAll()
{
    auto* current = this->head;
    while (current != nullptr)
    {
        std::cout << current->value << std::endl;
        current = current->getNext();
    }
}