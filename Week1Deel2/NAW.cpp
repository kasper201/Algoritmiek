#include "stdafx.h"
#include "NAW.h"

///////////////////////////////////////////////////////////////////////////////
// constructor / destructor

NAW::NAW()
{
}

NAW::NAW( const std::string& naam, const std::string& adres, const std::string& woonplaats )
{
    setNaam(naam);
    setAdres(adres);
    setPlaats(woonplaats);
}

NAW::~NAW()
{
}

///////////////////////////////////////////////////////////////////////////////
// getters / setters

const std::string& NAW::getNaam() const
{
    return this->naam; // vervang deze regel door kloppende broncode
}

const std::string& NAW::getAdres() const
{
    return this->adres; // vervang deze regel door kloppende broncode
}

const std::string& NAW::getPlaats() const
{
    return this->woonplaats; // vervang deze regel door kloppende broncode
}

void NAW::setNaam( const std::string& naamIn)
{
    this->naam = naamIn;
}

void NAW::setAdres( const std::string& adresIn)
{
    this->adres = adresIn;
}

void NAW::setPlaats( const std::string& woonplaatsIn)
{
    this->woonplaats = woonplaatsIn;
}

///////////////////////////////////////////////////////////////////////////////
// comparators

bool NAW::heeftNaam( const std::string& naamIn) const
{
    return this->naam == naamIn;

}

bool NAW::heeftAdres( const std::string& adresIn) const
{
    return this->adres == adresIn;
}

bool NAW::heeftPlaats( const std::string& woonplaatsIn) const
{
    return this->woonplaats == woonplaatsIn;
}