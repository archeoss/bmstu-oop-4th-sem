#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <malloc.h>
#include "errors.h"

int alloc_array(void *&array, int n, size_t ssize);
void free_array(void *array);

#endif