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
    virtual int     zoekOpEersteNaam( const std::string& )          const;
    virtual int     zoekOpEersteAdres( const std::string& )         const;
    virtual int     zoekOpEerstePlaats( const std::string& )        const;
    virtual int     zoekOpEersteAdresEnPlaats( const std::string&
            , const std::string& ) const;

public: // vraag 4
    virtual int     verwijderEersteMetNaam( const std::string& );
    virtual int     verwijderLaatsteMetNaam( const std::string& );
    virtual int     verwijderAllenMetNaam( const std::string& );
    virtual int     verwijderEersteMetAdresEnPlaats( const std::string&
            , const std::string& );
    virtual int     verwijderAllenMetAdresEnPlaats( const std::string&
            , const std::string& );

private:
    // vul hier de attributen voor deze klasse in.
    // let op: hou je aan de beschrijving van de presentatie!!!
    NAW* array[20];
    int index = 0;

};
