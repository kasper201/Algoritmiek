#pragma once

class IntLink
{
public:
                        IntLink();
                        IntLink( int, IntLink* );
    virtual            ~IntLink();

public:
    /*
     * plaats hier de methodes voor de klasse
     */

private:
    /*
     * attributen voor de klasse
     */

private:
    friend class IntLinkedList;
};

