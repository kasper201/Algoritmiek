#pragma once

class NAW;
class NAWLink;

class NAWLinkedList
{
public:
                        NAWLinkedList();

    virtual            ~NAWLinkedList();

public: // vraag 1
    virtual void        addToStart( const NAW& );
    virtual NAWLink*    search( const NAW& )    const;
    virtual void        showAll()               const;
    virtual NAWLink*    removeFirst( const NAW& );

    /*
     * plaats hier evenuteel extra methodes voor de klasse
     */

private:
    /*
     * attributen voor de klasse
     */
};

