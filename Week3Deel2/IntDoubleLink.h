#pragma once
class IntDoubleLink
{
private:
                            IntDoubleLink();
                            IntDoubleLink( int, IntDoubleLink*, IntDoubleLink* );
public:
    virtual                ~IntDoubleLink();

public:
    virtual IntDoubleLink  *getPrev();
    virtual IntDoubleLink  *getNext();

    /*
     * plaats hier de methodes voor de klasse
     */

private:
    /*
     * attributen voor de klasse
     */
    int value;
    IntDoubleLink *prev;
    IntDoubleLink *next;
private:
    friend class IntDoubleLinkedList;
};

