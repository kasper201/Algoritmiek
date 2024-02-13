#pragma once

#include <string>

class NAW;

class NAWArray
{
public:
    NAWArray();
    virtual        ~NAWArray();

public: // niet gevraagd, wel handig
    virtual void    add( const NAW& );

public: // vraag 2
    void          swap( int index1, int index2 );
    void          sort();
    void          sortWoonplaats();
    void          showAll() const;

private:
    // vul hier de attributen voor deze klasse in.
    // let op: hou je aan de beschrijving van de presentatie!!!
    NAW* array[20];
    int index = 0;

};
