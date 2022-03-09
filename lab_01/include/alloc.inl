#ifndef _MALLOC_INL_
#define _MALLOC_INL_

#include "alloc.h"

/*
    for io.h
*/
template int alloc_array<point_t>(point_t *&, int);
template int alloc_array<edge_t>(edge_t *&, int);

#endif