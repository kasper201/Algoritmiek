#include <iostream>
#include <random>

#include "TBS.h"

void vraag1()
{
    TBS tbs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for(int i = 0; i < 10; i++)
    {
        tbs.add(dis(gen));
    }
    tbs.showAll();
    std::cout << "Sorting" << std::endl;
    tbs.selectionSort();
    std::cout << "Sorted" << std::endl;
    tbs.showAll();

}

void vraag2()
{

}

int main() {
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 1 //
    vraag1();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 2 //

    /////////////////////////////////////////////////////////////////////////////////
    return 0;
}
