#include "stdafx.h"
#include "NAWArray.h"
#include "NAW.h"

#include <sstream>

NAWArray::NAWArray()
{
    for(int i = 0; i < 10; i++)
    {
        array[i] = new NAW();
    }
}

NAWArray::~NAWArray()
{
    for (int i = 0; i < 10; i++)
        delete array[i];

// gooi zo nodig, zaken weg....
}

void NAWArray::add( const NAW& naw)
{
    array[index] = new NAW(naw);
    index++;
}

int NAWArray::zoekOpEersteNaam( const std::string& naam) const
{
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getNaam() == naam)
        {
            return i;
        }
    }
    return -1;
}

int NAWArray::zoekOpEersteAdres( const std::string& adres) const
{
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getAdres() == adres)
        {
            return i;
        }
    }
    return -1;
}

int NAWArray::zoekOpEerstePlaats( const std::string& plaats) const
{
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getPlaats() == plaats)
        {
            return i;
        }
    }
    return -1;
}

int NAWArray::zoekOpEersteAdresEnPlaats( const std::string& adres
        , const std::string& plaats) const
{
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getAdres() == adres && array[i]->getPlaats() == plaats)
        {
            return i;
        }
    }
    return -1;
}

int NAWArray::verwijderEersteMetNaam( const std::string& naam)
{
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getNaam() == naam)
        {
            delete array[i];
            for(int j = i; j < index; j++)
            {
                array[j] = array[j+1];
            }
            index--;
            return i;
        }
    }
    return -1;
}

int NAWArray::verwijderLaatsteMetNaam( const std::string& naam)
{
    for(int i = index; i >= 0; i--)
    {
        if(array[i]->getNaam() == naam)
        {
            delete array[i];
            for(int j = i; j < index; j++)
            {
                array[j] = array[j+1];
            }
            index--;
            return i;
        }
    }
    return -1;
}

int NAWArray::verwijderAllenMetNaam( const std::string& )
{
    return -1; // vervang deze regel door kloppende broncode
}

int NAWArray::verwijderEersteMetAdresEnPlaats( const std::string&
        , const std::string&  )
{
    return -1; // vervang deze regel door kloppende broncode
}

int NAWArray::verwijderAllenMetAdresEnPlaats( const std::string&
        , const std::string&  )
{
    return -1; // vervang deze regel door kloppende broncode
}
