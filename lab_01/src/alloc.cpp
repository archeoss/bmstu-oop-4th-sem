#include "alloc.h"

int alloc_array(void *&array, int n, size_t ssize)
{
    int error_code = OK;
    array = malloc(n * ssize);
    if (!array)
    {
        error_code = ALLOC_ERROR;
    }

    return error_code;
}

void free_array(void *array)
{
    if (array)
    {    
        free(array);
    }
}
