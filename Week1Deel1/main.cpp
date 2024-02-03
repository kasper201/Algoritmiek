//
// Created by Kasper on 29/01/2024.
//
#include "stdafx.h"

#include "NAWArray.h"
#include "NAW.h"

#include <iostream>
#include <sstream>

int main()
{
    NAWArray array;

    for ( int n = 0; n < 10; n++ )
    {
        std::stringstream naam, adres, plaats;

        naam   << "avans "              << n + 1;
        adres  << "onderwijsboulevard " << n + 1;
        plaats << "den bosch "          << n + 1;

        array.add( { naam.str(), adres.str(), plaats.str() } );
    }

    std::cout << array.zoekOpEersteNaam( "avans 4" )  << std::endl;
    std::cout << array.zoekOpEersteNaam( "avans 34" ) << std::endl;
    std::cout << array.zoekOpEersteAdres( "onderwijsboulevard 7" )  << std::endl;
    std::cout << array.zoekOpEersteAdres( "onderwijsboulevard 37" ) << std::endl;
    std::cout << array.zoekOpEerstePlaats( "den bosch 2" )  << std::endl;
    std::cout << array.zoekOpEerstePlaats( "den bosch 83" ) << std::endl;
    std::cout << array.zoekOpEersteAdresEnPlaats( "onderwijsboulevard 7", "den bosch 7" ) << std::endl;
    std::cout << array.zoekOpEersteAdresEnPlaats( "onderwijsboulevard 7", "den bosch 8" ) << std::endl;
    std::cout << "Start met verwijderen: " << std::endl;
    std::cout << array.verwijderEersteMetNaam( "avans 4" )  << std::endl;
    std::cout << array.verwijderEersteMetNaam( "avans 34" ) << std::endl;
    std::cout << array.verwijderLaatsteMetNaam( "avans 5" )  << std::endl;
    std::cout << array.verwijderLaatsteMetNaam( "avans 34" ) << std::endl;
    std::cout << array.verwijderAllenMetNaam( "avans 5" )  << std::endl;
    std::cout << array.verwijderAllenMetNaam( "avans 34" ) << std::endl;
    std::cout << array.verwijderEersteMetAdresEnPlaats( "onderwijsboulevard 7", "den bosch 7" ) << std::endl;
    std::cout << array.verwijderEersteMetAdresEnPlaats( "onderwijsboulevard 7", "den bosch 8" ) << std::endl;
    std::cout << array.verwijderAllenMetAdresEnPlaats( "onderwijsboulevard 8", "den bosch 8" ) << std::endl;
    std::cout << array.verwijderAllenMetAdresEnPlaats( "onderwijsboulevard 9", "den bosch 8" ) << std::endl;

    return 0;
}
