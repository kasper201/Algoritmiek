#include "NAWLinkedList.h"
#include "IntLinkedList.h"

#include "NAW.h"
#include "NAWLink.h"

#include <chrono>
#include <iostream>
#include <sstream>

void testNAWLinkedList();
void testintLinkedList();

int main()
{
    testNAWLinkedList();
    //testintLinkedList();

    return 0;
}

void testNAWLinkedList()
{
    NAWLinkedList   linkedList;
    NAWLink        *link1, *link2;

    for ( int n = 0; n < 20; n++ )
    {
        std::stringstream naam, adres, plaats;

        naam   << "avans "              << n + 1;
        adres  << "onderwijsboulevard " << n + 1;
        plaats << "den bosch "          << n + 1;

        linkedList.addToStart( { naam.str(), adres.str(), plaats.str() } );
    }

    linkedList.showAll();

    std::stringstream naam, adres, plaats;

    naam   << "avans "              << 7;
    adres  << "onderwijsboulevard " << 7;
    plaats << "den bosch "          << 7;

    link1 = linkedList.search( { naam.str(), adres.str(), plaats.str() } );
    link2 = linkedList.removeFirst( { naam.str(), adres.str(), plaats.str() } );

    std::cout << link1 << " =?= " << link2 << std::endl;
}

void testintLinkedList()
{
    IntLinkedList                           linkedList;
    std::chrono::steady_clock::time_point   start, end;

    for ( int n = 100; n > 0; n-- )
    {
        if ( (n & 1) == 0 )
            linkedList.addToStart( n+10 );
        else
            linkedList.addToStart( n );
    }

    std::cout << "link at position  7: " << linkedList.getAt( 7) << std::endl;
    std::cout << "link at position 37: " << linkedList.getAt(37) << std::endl;

    linkedList.setAt(  7,  8 );
    linkedList.setAt( 37, 38 );

    std::cout << "link at position  7: " << linkedList.getAt( 7) << std::endl;
    std::cout << "link at position 37: " << linkedList.getAt(37) << std::endl;

    std::cout << linkedList.length1() << " =?= " << linkedList.length2() << std::endl;

    linkedList.showAll();

    start   = std::chrono::steady_clock::now();
    linkedList.bubbleSort(); for ( int n=0; n<(1<<25); n++ );
    end     = std::chrono::steady_clock::now();

    std::cout << "duration = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;

    linkedList.showAll();
}
