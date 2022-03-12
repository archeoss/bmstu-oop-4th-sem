#ifndef _LINKS_H_
#define _LINKS_H_

#include "points.h"
#include "errors.h"

#define MIN_LINKS 1

typedef int     type_id;
/*
    Describes id's of points, that's being connected
*/
typedef struct 
{
    type_id point_a,
            point_b;
} edge_t;

typedef struct
{
    int amount = 0;
    edge_t *array = NULL;
} dataedges_t;

int check_edges(dataedges_t edges, datapoints_t points);

#endif