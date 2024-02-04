#include "stdafx.h"
#include "NAWArray.h"
#include "NAW.h"

#include <sstream>
#include <iostream>

NAWArray::NAWArray()
{
    index = 0;
    for(int i = 0; i < 10; i++)
    {
        array[i] = new NAW();
    }
}

NAWArray::~NAWArray()
{
    for (int i = 0; i < index - 1; i++)
        delete array[i];
}

void NAWArray::add( const NAW& naw)
{
    array[index] = new NAW(naw);
    std::cout << "\nAdded: " << std::endl;
    std::cout << array[index]->getNaam() << std::endl;
    std::cout << array[index]->getAdres() << std::endl;
    std::cout << array[index]->getPlaats() << std::endl;
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
            for(int j = i; j < index-1; j++)
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
            for(int j = i; j < index-1; j++)
            {
                array[j] = array[j+1];
            }
            index--;
            return i;
        }
    }
    return -1;
}

int NAWArray::verwijderAllenMetNaam( const std::string& naam ) {
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getNaam() == naam)
        {
            delete array[i];
            for(int j = i; j < index-1; j++)
            {
                array[j] = array[j+1];
            }
            index--;
        }
    }
    return -1;
}

int NAWArray::verwijderEersteMetAdresEnPlaats( const std::string& adres
        , const std::string&  plaats)
{
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getAdres() == adres && array[i]->getPlaats() == plaats)
        {
            delete array[i];
            for(int j = i; j < index-1; j++)
            {
                array[j] = array[j+1];
            }
            index--;
            return i;
        }
    }
    return -1;
}

int NAWArray::verwijderAllenMetAdresEnPlaats( const std::string& adres
        , const std::string& plaats )
{
    int found = -1;
    for(int i = 0; i < index; i++)
    {
        if(array[i]->getAdres() == adres && array[i]->getPlaats() == plaats)
        {
            delete array[i];
            for(int j = i; j < index-1; j++)
            {
                array[j] = array[j+1];
                array[j+1] = nullptr;
            }
            found = 0;
            index--;
            i--;
        }
    }
    return found;
}
