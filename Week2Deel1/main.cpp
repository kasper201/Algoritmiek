#include <iostream>
#include <random>
#include <sstream>

#include "stdafx.h"
#include "TBS.h"
#include "NAWArray.h"
#include "NAW.h"

void nietBubblesort()
{
    TBS tbs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for(int i = 0; i <= 10; i++)
    {
        tbs.add(dis(gen));
    }
    tbs.showAll();
    std::cout << "Sorting" << std::endl;
    tbs.sort(true);
    std::cout << "Sorted ascending" << std::endl;
    tbs.showAll();
    std::cout << "Sorting" << std::endl;
    tbs.sort(false);
    std::cout << "Sorted descending" << std::endl;
    tbs.showAll();
}

void vraag1()
{
    TBS tbs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for(int i = 0; i <= 10; i++)
    {
        tbs.add(dis(gen));
    }
    tbs.showAll();
    std::cout << "Sorting" << std::endl;
    tbs.bubbleSort();
    std::cout << "Sorted" << std::endl;
    tbs.showAll();
}

void vraag2()
{
    NAWArray array;

//    array.add( { "avans 60", "onderwijsboulevard 87", "den bosch 99" } );
    for ( int n = 0; n < 10; n++ )
    {
        std::stringstream naam, adres, plaats;

        naam   << "avans "              << n + 1;
        adres  << "onderwijsboulevard " << n + 1;
        plaats << "den bosch "          << n + 1;

        array.add( { naam.str(), adres.str(), plaats.str() } );
    }
    array.showAll();
    std::cout << "\nSorting" << std::endl;
    array.sort();
    std::cout << "\nSorted" << std::endl;
    array.showAll();
}

int main() {
    /////////////////////////////////////////////////////////////////////////////////
    // niet bubble sort //
    nietBubblesort();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 1 //
    /*
     * bubble sort is een O(n^2) algoritme omdat het een nested loop heeft die door de array heen gaat en voor elk element ongeveer n/2 swaps moet uitvoeren en n keer moet loopen om alle elementen te hebben gehad.
     * O(n/2) * O(n) = O(n^2)
     */
//    std::cout << "Vraag 1" << std::endl;
//    vraag1();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 2 //
    /*
     * Dit algoritme is niet stabiel omdat het geen rekening houdt met al gesorteerde elementen.
     */
    std::cout << "Vraag 2" << std::endl;
    vraag2();

    /////////////////////////////////////////////////////////////////////////////

    return 0;
}