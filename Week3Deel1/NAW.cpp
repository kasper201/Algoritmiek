#include "NAW.h"

/*
 * copieer gegevens van week 1 met eventuele aanvullingen
 */


///////////////////////////////////////////////////////////////////////////////
// constructor / destructor

NAW::NAW()
{
}

NAW::NAW( const std::string& naam, const std::string& adres, const std::string& woonplaats )
{
}

NAW::~NAW()
{
}

///////////////////////////////////////////////////////////////////////////////
// comparators, part 1

int NAW::compareTo( const NAW& ) const
{
    return 0; // hint vooraf: implementeer deze methode...
}


///////////////////////////////////////////////////////////////////////////////
// getters / setters

const std::string& NAW::getNaam() const
{
    return nonsense; // neem broncode over van week 1 deel 1
}

const std::string& NAW::getAdres() const
{
    return nonsense; // neem broncode over van week 1 deel 1
}

const std::string& NAW::getPlaats() const
{
    return nonsense; // neem broncode over van week 1 deel 1
}

void NAW::setNaam( const std::string& )
{
// neem broncode over van week 1 deel 1
}

void NAW::setAdres( const std::string& )
{
// neem broncode over van week 1 deel 1
}

void NAW::setPlaats( const std::string& )
{
// neem broncode over van week 1 deel 1
}

///////////////////////////////////////////////////////////////////////////////
// comparators, part 2

bool NAW::heeftNaam( const std::string& ) const
{
    return false; // neem broncode over van week 1 deel 1
}

bool NAW::heeftAdres( const std::string& ) const
{
    return false; // neem broncode over van week 1 deel 1
}

bool NAW::heeftPlaats( const std::string& ) const
{
    return false; // neem broncode over van week 1 deel 1
}
