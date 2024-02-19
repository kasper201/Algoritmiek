#pragma once

class IntLink;

class IntLinkedList
{
public:
                        IntLinkedList();
    virtual            ~IntLinkedList();

public: // vraag 3
    virtual IntLink*    getAt( int )    const;
    virtual bool        setAt( int, int );

    virtual int         length1()       const;
    virtual int         length2()       const;

public: // vraag 4
    virtual void        bubbleSort();

public: // niet gevraagd wel handig... (zie vraag 1)
    virtual void        addToStart( int );
    virtual void        showAll()       const;

private:
    /*
     * attributen voor de klasse
     */
};

