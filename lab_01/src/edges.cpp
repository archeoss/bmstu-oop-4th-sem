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
        for (int i = 0; i < edges.amount && error_code == OK; i++)
        {
            error_code = check_validaty(edges.array[i], points.amount);
        }
    }

    return error_code;
}