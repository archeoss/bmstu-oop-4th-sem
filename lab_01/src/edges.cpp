#include "edges.h"

int check_edges(dataedges_t data)
{
    if (data.amount >= MIN_LINKS)
        return OK;
    else
        return INSUFFICIENT_LINKS;
}