#pragma once

#include "NAW.h"

class NAWLink
{
private:
                    NAWLink();
                    NAWLink( const NAW&, NAWLink* );
public:
    virtual        ~NAWLink();

public:
    /*
     * plaats hier de methodes voor de klasse
     */
private:
    /*
     * attributen voor de klasse
     */
    NAW naw;
    NAWLink *next;

private:
    friend class NAWLinkedList;
};

