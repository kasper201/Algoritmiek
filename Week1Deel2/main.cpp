// Week1Deel2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "NAWOrderedArray.h"
#include "NAW.h"

#include "IntOrderedArray.h"

#include <iostream>
#include <sstream>

void testNAWOrderedArray();
void testIntOrderedArray();

int main()
{
    testNAWOrderedArray();

    return 0;
}

void testNAWOrderedArray()
{
    NAWOrderedArray array;

    for ( int n = 0; n < 10; n++ )
    {
        std::cout << "Adding " << n + 1 << "..." << std::endl;
        std::stringstream naam, adres, plaats;

        naam   << "avans "              << n + 1;
        adres  << "onderwijsboulevard " << n + 1;
        plaats << "den bosch "          << n + 1;

        array.add( { naam.str(), adres.str(), plaats.str() } );
    }

    array.showAll();
    std::cout << "Starting find, add, remove, replace tests..." << std::endl;

    std::cout << array.find( {"avans 7","onderwijsboulevard 7","den bosch 7"} ) << std::endl;
    std::cout << array.find( {"avans 7","onderwijsboulevard 8","den bosch 9"} ) << std::endl;
//    std::cout << array.add( {"avans 7","onderwijsboulevard 8","den bosch 9"} ) << std::endl;
    std::cout << array.add( {"avans 7","onderwijsboulevard 8","den bosch 9"} ) << std::endl; // niet-gedefinieerd requirement...
    std::cout << array.remove( {"avans 7","onderwijsboulevard 8","den bosch 9"} ) << std::endl;
    std::cout << array.remove( {"avans 7","onderwijsboulevard 8","den bosch 9"} ) << std::endl;
    std::cout << array.replace( {"avans 7","onderwijsboulevard 7","den bosch 7"}
            , {"avans 17","onderwijsboulevard 18","den bosch 19"} ) << std::endl;
    std::cout << array.replace( {"avans 1","onderwijsboulevard 2","den bosch 3"}
            , {"avans 17","onderwijsboulevard 18","den bosch 19"} ) << std::endl;

    array.showAll();
    testIntOrderedArray();
}

void testIntOrderedArray()
{
    IntOrderedArray array;
    for ( int n = 1; n <= 10; n++ )
    {
        if ( (n&1) == 0 )
            array.quickInsert( n+10 );
        else
            array.quickInsert( n );
    }

    array.showAll();

    std::cout << "Last Element Smaller or Equal to: " << array.getLastElementSmallerOrEqualTo( 5 ) << std::endl;
}
