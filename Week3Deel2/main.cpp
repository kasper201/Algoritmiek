#include "IntDoubleLinkedList.h"

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>

void testVraag1();
void testVraag2();

int main()
{
    //testVraag1();
    testVraag2();

    return 0;
}

void testVraag1()
{
    const int                               SIZE = 1000;
    IntDoubleLinkedList                     linkedList;
    std::chrono::steady_clock::time_point   start, end;

    std::srand( unsigned(time(nullptr)) );

    for ( int n = 0; n < SIZE; n++ )
    {
        if ( (n&1) == 0 )
            linkedList.insertAtStart( std::rand() );
        else
            linkedList.insertAtEnd( std::rand() );
    }

    start   = std::chrono::steady_clock::now();
    linkedList.rapidBubbleSort();// for ( int n=0; n<(1<<25); n++ );
    end     = std::chrono::steady_clock::now();

    std::cout << "duration = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;

    //linkedList.showAll();
}

void testVraag2()
{
    IntDoubleLinkedList linkedList;

    for ( int n = 0; n < 20; n++ )
        linkedList.insertAction( n );

    for ( int n = 0; n < 10; n++ )
        std::cout << linkedList.undo() << std::endl;

    for ( int n = 0; n < 5; n++ )
        std::cout << linkedList.redo() << std::endl;

    linkedList.insertAction( 100 );

    std::cout << " ----- " << std::endl;
    linkedList.showAll();
}
