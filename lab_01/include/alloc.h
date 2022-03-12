#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <malloc.h>
#include "errors.h"
#include "figure.h"

int alloc_array(edge_t *&array, int n);
int alloc_array(point_t *&array, int n);

void free_array(void *array);

#endif