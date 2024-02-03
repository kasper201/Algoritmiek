#pragma once
class IntOrderedArray
{
public:
    IntOrderedArray();
    virtual            ~IntOrderedArray();

public: // voor vraag 3
    virtual void        exploreBinarySearch( int )              const;

public: // voor vraag 4
    virtual int         getLastElementSmallerOrEqualTo( int )   const;
    virtual void        moveElementsOnePositionToRight( int );

    virtual int         quickInsert( int );

public: // niet gevraagd, wel handig
    virtual void        showAll()                               const;

private:
    // vul hier de attributen voor deze klasse in.
    // let op: hou je aan de beschrijving van de presentatie!!!
};

