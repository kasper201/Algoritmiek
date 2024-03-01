//
// Created by flits on 3/1/24.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>

#include "Queue.h"
#include "kassa.h"

std::mutex mutex;

void updateInfo(int *aantalKassa, int *maxNKlant, int *maxNKlantMinderPerMin, int *maxTijd)
{
    std::cout << "Enter the number of cash registers (max 16000 advised): "; // 16000 is advised but not tested yet
    std::cin >> *aantalKassa;

    std::cout << "Enter the maximum number of customers (per time): ";
    std::cin >> *maxNKlant;

    std::cout << "Enter the maximum number of customers less per minute: ";
    std::cin >> *maxNKlantMinderPerMin;

    std::cout << "Enter the maximum time: ";
    std::cin >> *maxTijd;
}

int simulate(int maxNKlant, int maxNKlantMinderPerMin, int maxTijd, int *gemiddeldWachtend)
{
    Queue queue;
    kassa kassa;
    std::cout << "Simulation started" << std::endl;
    int queueLength = 0;

    for(int i = 0; i < maxTijd; i++)
    {
        queueLength = queue.getCount();
        kassa.updateSim(queue, maxNKlant, queueLength, maxNKlantMinderPerMin);
        std::cout << "Time: " << i << std::endl;
        std::cout << "Queue length: " << queueLength << std::endl;

        std::lock_guard<std::mutex> lock(mutex); // lock the mutex to prevent concurrent access to 'gemiddeldWachtend'
            *gemiddeldWachtend += queueLength;
    }

    return 0;
}

int main()
{
    int gemiddeldWachtend = 0;

    // default values
    int aantalKassa = 4;
    int maxNKlant = 10;
    int maxNKlantMinderPerMin = 10;
    int maxTijd = 60;

    updateInfo(&aantalKassa, &maxNKlant, &maxNKlantMinderPerMin, &maxTijd);

    std::thread thread[aantalKassa]; // create a thread for each cash register

    for(int i = 0; i < aantalKassa; i++)
    {
        thread[i] = std::thread(simulate, maxNKlant, maxNKlantMinderPerMin, maxTijd, &gemiddeldWachtend);
    }

    for(int i = 0; i < aantalKassa; i++)
    {
        thread[i].join();
    }

    std::cout << "Average waiting is (about): " << std::round((static_cast<double>(gemiddeldWachtend) / static_cast<double>(aantalKassa * maxTijd))) << std::endl; // bereken gemiddelde wachttijd
    return 0;
}