#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <malloc.h>
#include "errors.h"
#include "figure.h"

template <typename array_type>
int alloc_array(array_type *&array, int n);

void free_array(void *array);


#endif