#include "stdafx.h"
#include "NAW.h"

///////////////////////////////////////////////////////////////////////////////
// constructor / destructor

NAW::NAW()
{
}

NAW::NAW( const std::string& naam, const std::string& adres, const std::string& woonplaats )
{
    this->setNaam(naam);
    this->setAdres(adres);
    this->setPlaats(woonplaats);
}

NAW::~NAW()
{
}
///////////////////////////////////////////////////////////////////////////////
// comparators, part 1

int NAW::compareTo(const NAW& naw) const
{
    if (this->woonplaats != naw.woonplaats) {
        if(this->woonplaats.length() < naw.woonplaats.length())
            return -1;
        return (this->woonplaats < naw.woonplaats) ? -1 : 1;
    }

    if (this->naam != naw.naam) {
        if(this->naam.length() < naw.naam.length())
            return -2;
        return (this->naam < naw.naam) ? -2 : 2;
    }
    if(this->adres.length() < naw.adres.length())
        return -3;
    return (this->adres < naw.adres) ? -3 : (this->adres > naw.adres) ? 3 : 0;
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