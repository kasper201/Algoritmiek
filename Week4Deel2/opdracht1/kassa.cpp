//
// Created by flits on 3/1/24.
//

#include "kassa.h"
#include <random>

int getRand(int max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, max);
    return round(dist(mt));
}

kassa::kassa() {
}

kassa::~kassa() {

}

void kassa::updateSim(Queue &queue, int maxNKlant, int inQ, int min) {
    if(inQ > maxNKlant) // should not be possible but just in case
        return;

    int klanten = getRand(maxNKlant - inQ);
    for(int i = 0; i < klanten; i++)
    {
        queue.insert(1);
    }
    for(int i = 0; i < min; i++)
    {
        queue.remove();
    }
}
