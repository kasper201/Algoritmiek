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

    // add NAW objects to NAWarray
    array.add( { "avans 7", "onderwijsboulevard 4", "den bosch 3"} );
    array.add( { "avans 6", "onderwijsboulevard 8", "den bosch 3"} );
    array.add( { "avans 8", "onderwijsboulevard 5", "den bosch 3"} );
    array.add( { "avans 5", "onderwijsboulevard 2", "den bosch 5"} );
    array.add( { "avans 0", "onderwijsboulevard 5", "den bosch 7"} );
    array.add( { "avans 7", "onderwijsboulevard 3", "den bosch 5"} );
    array.add( { "avans 1", "onderwijsboulevard 4", "den bosch 5"} );
    array.add( { "avans 9", "onderwijsboulevard 6", "den bosch 9"} );
    array.add( { "avans 5", "onderwijsboulevard 3", "den bosch 4"} );
    array.showAll();

    std::cout << "\nSorting" << std::endl;
    array.sort();
    std::cout << "\nSorted by name" << std::endl;
    array.showAll();
    std::cout << "\nSorting" << std::endl;
    array.sortWoonplaats();
    std::cout << "\nSorted by woonplaats" << std::endl;
    array.showAll();
}

int main() {
    /////////////////////////////////////////////////////////////////////////////////
    // niet bubble sort //
    //nietBubblesort();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 1 //
    /*
     * bubble sort is een O(n^2) algoritme omdat het een nested loop heeft die door de array heen gaat en voor elk element ongeveer n/2 swaps moet uitvoeren en n keer moet loopen om alle elementen te hebben gehad.
     * O(n/2) * O(n) = O(n^2)
     */
//    std::cout << "Vraag 1" << std::endl;
//  vraag1();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 2 //
    /*
     * Dit algoritme is stabiel omdat het rekening houdt met al gesorteerde elementen. Dit heb ik getest doormiddel van eerst te sorteren op naam en daarna op woonplaats.
     * Hier zie je dat de elementen die al gesorteerd zijn op naam ook gesorteerd blijven op woonplaats binnen de gesorteerde elementen van woonplaats.
     */
    std::cout << "Vraag 2" << std::endl;
    vraag2();

    /////////////////////////////////////////////////////////////////////////////

    return 0;
}