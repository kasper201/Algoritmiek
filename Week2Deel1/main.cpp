#include <iostream>
#include "TBS.h"
#include <random>

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

int main() {
    /////////////////////////////////////////////////////////////////////////////////
    // niet bubble sort //
    nietBubblesort();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 1 //
    /*
     *
     */
    vraag1();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 2 //
    /*
     *
     */

    /////////////////////////////////////////////////////////////////////////////

    return 0;
}