#include "figure.h"
#include <stdlib.h>

template <typename data_type>
static void init_data(data_type &data)
{
    data.amount = 0;
    data.array = NULL;
}

template <typename data_type>
void free_data(data_type data)
{
    data.amount = 0;
    free_array(data.array);
}

figure_t &init_figure(void)
{
    static figure_t main_figure;
    init_data<datapoints_t>(main_figure.points);
    init_data<dataedges_t>(main_figure.edges);
    main_figure.name = static_cast<char *>(malloc(sizeof(char) * MAX_STR_SIZE));
    
    return main_figure;
}

int destroy_figure(figure_t &figure)
{
    if (figure.created == YES)
    {
        free_data<datapoints_t>(figure.points);
        free_data<dataedges_t>(figure.edges);
        free(figure.name);
        figure.created = NO;
    }

    return OK;
}

int center_figure(figure_t &figure, point_t center)
{
    point_t center_obj;
    int error_code = find_center(center_obj, figure.points);
    if (error_code == OK)
    {
        transfer_t transfer;
        transfer.kx = center.x - center_obj.x;
        transfer.ky = center.y - center_obj.y;
        transfer.kz = 0;
        error_code = move_points(figure.points, transfer);
    }

    return error_code;
}

int rotate_figure(figure_t &figure, transfer_t degrees, point_t center)
{
    return rotate_points(figure.points, degrees, center);
}

int move_figure(figure_t &figure, transfer_t transform)
{
    return move_points(figure.points, transform);
}

int scale_figure(figure_t &figure, transfer_t transform, point_t center)
{
    return scale_points(figure.points, transform, center);
}

int check_figure(figure_t figure)
{
    int error_code = check_points(figure.points);
    if (error_code == OK)
        error_code = check_edges(figure.edges, figure.points);
    
    return error_code;
}
