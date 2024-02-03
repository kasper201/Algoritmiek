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
    // vul hier de attributen voor deze klasse in.
    // let op: hou je aan de beschrijving van de presentatie!!!
};
