#include "IntLink.h"


IntLink::IntLink()
{
    next = nullptr;
}

IntLink::IntLink( int v, IntLink* link)
{
    value = v;
    next = link;
}

IntLink::~IntLink()
{
    delete next;
}
