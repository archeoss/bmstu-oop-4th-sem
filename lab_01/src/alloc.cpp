#include "alloc.h"

template <typename array_type>
int alloc_array(array_type *&array, int n)
{
    int error_code = OK;
    array = static_cast<array_type *>(malloc(n * sizeof(array_type)));
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

#include "alloc.inl"