#pragma once

class NAW;

class NAWOrderedArray
{
public:
    NAWOrderedArray();
    virtual        ~NAWOrderedArray();

public: // methode voor vraag 1
    virtual int     find( const NAW& )      const;
    virtual int     add( const NAW& );
    virtual int     remove( const NAW& );
    virtual int     replace( const NAW& cOld, const NAW& cNew );

public: // niet gevraagd, wel handig
    virtual void    showAll()               const;

private:
    int called = 0;
    int index = 0;
    NAW* array[20];
};
