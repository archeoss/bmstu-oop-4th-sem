#include "alloc.h"

int alloc_array(edge_t *&array, int n)
{
    int error_code = OK;
    array = static_cast<edge_t *>(malloc(n * sizeof(edge_t)));
    if (!array)
    {
        error_code = ALLOC_ERROR;
    }

    return error_code;
}

int alloc_array(point_t *&array, int n)
{
    int error_code = OK;
    array = static_cast<point_t *>(malloc(n * sizeof(point_t)));
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
