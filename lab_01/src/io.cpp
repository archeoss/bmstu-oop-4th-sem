#include "io.h"

static int read_amount(type_id &amount, FILE *f)
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

static int read_point(point_t &point, FILE *f)
{
    return fscanf(f, "%lf%lf%lf", &point.x, &point.y, &point.z);
}

static int read_points(datapoints_t &data, FILE *f)
{
    int i = 0,
        error_code = OK;

    error_code = read_amount(data.amount, f);
    if (error_code == OK)
    {
        error_code = alloc_points(data.array, data.amount);

        while (error_code == OK && i < data.amount)
        {
            if (read_point(data.array[i++], f) != 3)
                error_code = INCORRECT_DATA;
        }

        if (error_code != OK)
        {
            free_points(data.array);
            data.amount = 0;
        }
    }

    return error_code;
}

static int read_edge(edge_t &edge, FILE *f)
{
    return fscanf(f, "%d%d", &edge.point_a, &edge.point_b);
}

static int read_edges(dataedges_t &data, FILE *f)
{
    int i = 0,
        error_code = OK;

    error_code = read_amount(data.amount, f);
    if (error_code == OK)
    {
        error_code = alloc_edges(data.array, data.amount);
        
        while (error_code == OK && i < data.amount)
        {
            if (read_edge(data.array[i++], f) != 2)
                error_code = INCORRECT_DATA;
        }
        if (error_code != OK)
        {
            free_edges(data.array);
            data.amount = 0;
        }
    }

    return error_code;
}

static int load_temp_figure(figure_t &figure, FILE *f)
{
    int error_code = OK;
    if ((error_code = read_points(figure.points, f)) == OK)
    {
        error_code = read_edges(figure.edges, f);

        if (error_code != OK)
        {
            free_data(figure.points);
        }
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

    figure_t figure_temp = init_figure(filename);
    int error_code = load_temp_figure(figure_temp, f);
    
    fclose(f);

    if (error_code == OK)
    {
        error_code = check_figure(figure_temp);
        if (error_code != OK)
        {
            destroy_figure(figure_temp);
        }
    }

    if (error_code == OK)
    {
        destroy_figure(figure);
        figure = figure_temp;
    }

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
