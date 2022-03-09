#include "io.h"

static int read_point(FILE *f, point_t &point)
{
    return fscanf(f, "%lf%lf%lf", &point.x, &point.y, &point.z);
}

static int read_points(FILE *f, datapoints_t &data)
{
    int i = 0,
        error_code = OK;

    while (error_code == OK && i < data.amount)
    {
        if (read_point(f, data.array[i++]) != 3)
            error_code = INCORRECT_DATA;
    }

    return error_code;
}

static int read_edge(FILE *f, edge_t &edge)
{
    return fscanf(f, "%d%d", &edge.point_a, &edge.point_b);
}

static int read_edges(FILE *f, dataedges_t &data)
{
    int i = 0,
        error_code = OK;

    while (error_code == OK && i < data.amount)
    {
        if (read_edge(f, data.array[i++]) != 2)
            error_code = INCORRECT_DATA;
        
    }

    return error_code;
}

static int read_amount(FILE *f, type_id &amount)
{
    int error_code = OK;
    if(!fscanf(f, "%d", &amount))
    {
        error_code = INPUT_ERROR;
    }
    else if (amount < 2)
    {
        error_code = INCORRECT_DATA;
    }

    return error_code;
}

template <typename data_type, typename array_type>
static int load_data(FILE *f, data_type &data, int (* interpretator)(FILE *, data_type &))
{
    int error_code = OK;
    error_code = read_amount(f, data.amount);
    if (error_code == OK)
    {
        error_code = alloc_array<array_type>(data.array, data.amount);
    }
    if (error_code == OK)
    {
        error_code = interpretator(f, data);
    }

    return error_code;
}

/*
    Figure structure:
    <Num. of points>
    <x> <y> <z>
    ...
    <x> <y> <z>
    <Num. of edges>
    <point_a> <point_b>
    ...
    <point_a> <point_b>
*/
int load_figure(figure_t &figure, const char *filename)
{
    if (!filename)
        return INCORRECT_DATA;
    
    FILE *f = fopen(filename, "r");
    if (!f)
        return FILE_NOT_EXIST;
    figure_t figure_temp;
    int error_code = load_data<datapoints_t, point_t>(f, figure_temp.points, read_points);
    if (error_code == OK)
    {
        error_code = load_data<dataedges_t, edge_t>(f, figure_temp.edges, read_edges);
    }
    if (error_code != OK)
    {
        free_data<datapoints_t>(figure_temp.points);
        free_data<dataedges_t>(figure_temp.edges);
    }
    else
    {
        if (figure.created == YES)
        {
            destroy_figure(figure);
            figure = init_figure();
        }
        figure.created = YES;
        figure.points = figure_temp.points;
        figure.edges = figure_temp.edges;
        strcpy(figure.name, filename);
    }
    fclose(f);

    return error_code;
}

static void save_point(FILE *f, point_t point)
{
    fprintf(f, "%lf %lf %lf\n", point.x, point.y, point.z);
}

static void save_data(FILE *f, datapoints_t data)
{
    fprintf(f, "%d\n", data.amount);
    for (int i = 0; i < data.amount; i++)
    {
        save_point(f, data.array[i]);
    }
}

static void save_edge(FILE *f, edge_t edge)
{
    fprintf(f, "%d %d\n", edge.point_a, edge.point_b);
}

static void save_data(FILE *f, dataedges_t data)
{
    fprintf(f, "%d\n", data.amount);
    for (int i = 0; i < data.amount; i++)
    {
        save_edge(f, data.array[i]);
    }
}

int save_figure(const char *filename, figure_t figure)
{
    if (!filename)
        return INCORRECT_DATA;

    FILE *f = fopen(filename, "w");
    if (!f)
        return FILE_NOT_EXIST;
    
    save_data(f, figure.points);
    save_data(f, figure.edges);
    fclose(f);

    return OK;
}
