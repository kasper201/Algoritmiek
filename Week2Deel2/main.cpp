#include <iostream>
#include <random>

#include "TBS.h"

void vraag1()
{
    TBS tbs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    // clear array and add new random numbers
    tbs.clear();
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
    TBS tbs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    // clear array and add new random numbers
    tbs.clear();
    for(int i = 0; i < 10; i++)
    {
        tbs.add(dis(gen));
    }
    tbs.showAll();

    std::cout << "Sorting" << std::endl;
    tbs.insertionSort();
    std::cout << "Sorted" << std::endl;
    tbs.showAll();
}

void testArray()
{
    TBS tbs;
    std::cout << "\nTest array" << std::endl;

    // set array to given test array
    std::cout << "Clearing array" << std::endl;
    tbs.clear();
    tbs.add(7); tbs.add(3); tbs.add(8); tbs.add(1); tbs.add(2); tbs.add(5); tbs.add(4); tbs.add(6); tbs.add(9); tbs.add(0);
    tbs.showAll();
    std::cout << "Sorting using selection sort" << std::endl;
    tbs.selectionSort();
    std::cout << "Sorted" << std::endl;
    tbs.showAll();

    // set array to given test array
    std::cout << "Clearing array" << std::endl;
    tbs.clear();
    tbs.add(7); tbs.add(3); tbs.add(8); tbs.add(1); tbs.add(2); tbs.add(5); tbs.add(4); tbs.add(6); tbs.add(9); tbs.add(0);
    tbs.showAll();
    std::cout << "Sorting using insertion sort" << std::endl;
    tbs.insertionSort();
    std::cout << "Sorted" << std::endl;
    tbs.showAll();
}

int main() {
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 1 //
    /*
     * Het algoritme is O(n^2) omdat er nogsteeds twee loops zijn die over de array heen gaan voor comparions.
     * Enkel de swap functie wordt nu O(N) omdat deze enkel een keer per paar wordt aangeroepen en dus max N keer.
     */
    /*
        Test array
        Clearing array
        7 3 8 1 2 5 4 6 9 0
        Sorting using selection sort
        7 3 8 1 2 5 4 6 0 9
        7 3 0 1 2 5 4 6 8 9
        6 3 0 1 2 5 4 7 8 9
        4 3 0 1 2 5 6 7 8 9
        4 3 0 1 2 5 6 7 8 9
        2 3 0 1 4 5 6 7 8 9
        2 1 0 3 4 5 6 7 8 9
        0 1 2 3 4 5 6 7 8 9
        0 1 2 3 4 5 6 7 8 9
        Sorted
        0 1 2 3 4 5 6 7 8 9
     */
    //vraag1();
    /////////////////////////////////////////////////////////////////////////////////
    // Vraag 2 //
    /*
     * Het algoritme is O(N^2) omdat het algoritme nogsteeds twee loops heeft die over de array heen gaan en worst case all elementen van de array moeten worden vergeleken en geswapped na elke iteratie.
     */
    //vraag2();

    /*
        7 3 8 1 2 5 4 6 9 0
        Sorting using insertion sort
        0 7 3 8 1 2 5 4 6 9
        0 7 3 8 1 2 5 4 6 9
        0 7 3 8 1 2 4 5 6 9
        0 7 3 8 1 2 4 5 6 9
        0 7 3 8 1 2 4 5 6 9
        0 1 7 3 8 2 4 5 6 9
        0 1 3 7 8 2 4 5 6 9
        0 1 3 7 8 2 4 5 6 9
        0 1 3 7 8 2 4 5 6 9
        Sorted
        0 1 3 7 8 2 4 5 6 9
     */
    /////////////////////////////////////////////////////////////////////////////////
    // Vragen met gegeven test array //
    testArray();
    /////////////////////////////////////////////////////////////////////////////////
    return 0;
}
