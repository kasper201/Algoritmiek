#pragma once

class IntDoubleLink;

class IntDoubleLinkedList
{
public:
                            IntDoubleLinkedList();
    virtual                ~IntDoubleLinkedList();

public:
    virtual void            insertAtStart( int );
    virtual void            insertAtEnd( int );

    virtual bool            removeAtStart();
    virtual bool            removeAtEnd();

public:
    virtual IntDoubleLink  *getHead();
    virtual IntDoubleLink  *getTail();

public: // voor vraag 1
    virtual void            rapidBubbleSort();

public: // voor vraag 2
    virtual void            insertAction( int code );
    virtual int             undo();
    virtual int             redo();
    virtual int             getCurrentAction();

public: // alleen voor het gemak
    virtual void            showAll();

private:
    /*
     * attributen voor de klasse
     */
    IntDoubleLink *head;
    IntDoubleLink *tail;
    int counter;
};

