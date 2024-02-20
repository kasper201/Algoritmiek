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

    /*for(int i = 0; i <= 15; i++)
    {
        tbs.add(dis(gen));
    }*/
    for(int i = 14; i > 0; i--)
    {
        tbs.add(i);
    }
    tbs.showAll();
    std::cout << "Sorting" << std::endl;
    tbs.bubbleSort();
    std::cout << "Sorted" << std::endl;
    tbs.showAll();
}

void vraag1Def() // met test array vanuit school
{
    std::cout << "Juiste richting" << std::endl;
    TBS tbs;
    tbs.add(7); tbs.add(3); tbs.add(8); tbs.add(1); tbs.add(2); tbs.add(5); tbs.add(4); tbs.add(6); tbs.add(9); tbs.add(0);
    tbs.bubbleSort();
}

void vraag1Inc() // incorrecte richting (bubblesort2)
{
    std::cout << "verkeerde richting, werkt niet!!! " << std::endl;
    TBS tbs;
    tbs.add(7); tbs.add(3); tbs.add(8); tbs.add(1); tbs.add(2); tbs.add(5); tbs.add(4); tbs.add(6); tbs.add(9); tbs.add(0);
    //tbs.bubbleSort2();
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
//    vraag1();
    vraag1Def(); // <-- dit is de juiste!!!!!!!
/*
Juiste richting
0 7 3 8 1 2 5 4 6 9
0 1 7 3 8 2 4 5 6 9
0 1 2 7 3 8 4 5 6 9
0 1 2 3 7 4 8 5 6 9
0 1 2 3 4 7 5 8 6 9
0 1 2 3 4 5 7 6 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
sorting completed
Total Swaps: 23
 */

//    vraag1Inc();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 2 //
    /*
     * Dit algoritme is stabiel omdat het rekening houdt met al gesorteerde elementen. Dit heb ik getest doormiddel van eerst te sorteren op naam en daarna op woonplaats.
     * Hier zie je dat de elementen die al gesorteerd zijn op naam ook gesorteerd blijven op woonplaats binnen de gesorteerde elementen van woonplaats.
     */
    std::cout << "Vraag 2" << std::endl;
    vraag2();
    /*
     * relevante output:
 * avans 7 onderwijsboulevard 4 den bosch 3
 * avans 6 onderwijsboulevard 8 den bosch 3
 * avans 8 onderwijsboulevard 5 den bosch 3
 * avans 5 onderwijsboulevard 2 den bosch 5
 * avans 0 onderwijsboulevard 5 den bosch 7
 * avans 7 onderwijsboulevard 3 den bosch 5
 * avans 1 onderwijsboulevard 4 den bosch 5
 * avans 9 onderwijsboulevard 6 den bosch 9
 * avans 5 onderwijsboulevard 3 den bosch 4
 *
 * Sorting
 *
 * Sorted by name
 * avans 0 onderwijsboulevard 5 den bosch 7
 * avans 1 onderwijsboulevard 4 den bosch 5
 * avans 5 onderwijsboulevard 2 den bosch 5
 * avans 5 onderwijsboulevard 3 den bosch 4
 * avans 6 onderwijsboulevard 8 den bosch 3
 * avans 7 onderwijsboulevard 4 den bosch 3
 * avans 7 onderwijsboulevard 3 den bosch 5
 * avans 8 onderwijsboulevard 5 den bosch 3
 * avans 9 onderwijsboulevard 6 den bosch 9
 *
 * Sorting
 *
 * Sorted by woonplaats
 * avans 6 onderwijsboulevard 8 den bosch 3
 * avans 7 onderwijsboulevard 4 den bosch 3
 * avans 8 onderwijsboulevard 5 den bosch 3
 * avans 5 onderwijsboulevard 3 den bosch 4
 * avans 1 onderwijsboulevard 4 den bosch 5
 * avans 5 onderwijsboulevard 2 den bosch 5
 * avans 7 onderwijsboulevard 3 den bosch 5
 * avans 0 onderwijsboulevard 5 den bosch 7
 * avans 9 onderwijsboulevard 6 den bosch 9
     */

    /////////////////////////////////////////////////////////////////////////////

    return 0;
}