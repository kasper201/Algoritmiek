//
// Created by flits on 3/1/24.
//

#ifndef WEEK2DEEL2_KASSA_H
#define WEEK2DEEL2_KASSA_H

#include "Queue.h"

class kassa {
public:
    kassa();
    virtual ~kassa();

public:
    void updateSim(Queue &queue, int maxNKlant, int inQ, int min);
};


#endif //WEEK2DEEL2_KASSA_H
