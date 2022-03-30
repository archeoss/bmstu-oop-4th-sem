#include "edges.h"

static int check_validaty(edge_t edge, int num_of_points)
{
    return  edge.point_a < num_of_points \
                && edge.point_b < num_of_points \
                    ? OK : EDGES_EXCEED_POINTS;
}

int check_edges(dataedges_t edges, datapoints_t points)
{
    int error_code = OK;
    if (edges.amount < MIN_LINKS)
        error_code = INSUFFICIENT_LINKS;
    else
    {
        for (int i = 0; error_code == OK && i < edges.amount; i++)
        {
            error_code = check_validaty(edges.array[i], points.amount);
        }
    }

    return error_code;
}

int alloc_edges(edge_t *&data, int amount)
{
    void *arr_p = NULL;
    int error_code = alloc_array(arr_p, amount, sizeof(edge_t));
    data = static_cast<edge_t *>(arr_p);

    return error_code;
}

/*
    Free's array and set to NULL
*/
void free_edges(edge_t *&edges)
{
    free_array(static_cast<void *>(edges));
    edges = NULL;
}