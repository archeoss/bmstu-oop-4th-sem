#include "points.h"

void to_center(point_t &point, point_t center)
{
    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;
}

void from_center(point_t &point, point_t center)
{
    point.x += center.x;
    point.y += center.y;
    point.z += center.z;
}

double to_radians(double degrees)
{
    return degrees * M_PI / 180;
}

void rotate_xpoint(point_t &point, double degree)
{
    double 
        radians = to_radians(degree),
        cos_r = cos(radians),
        sin_r = sin(radians), 
        y = point.y,
        z = point.z;

    point.y = y * cos_r - z * sin_r;
    point.z = z * cos_r + y * sin_r;
}

void rotate_ypoint(point_t &point, double degree)
{
    double 
        radians = to_radians(degree),
        cos_r = cos(radians),
        sin_r = sin(radians), 
        x = point.x,
        z = point.z;

    point.x = x * cos_r + z * sin_r;
    point.z = z * cos_r - x * sin_r;
}

void rotate_zpoint(point_t &point, double degree)
{
    double 
        radians = to_radians(degree),
        cos_r = cos(radians),
        sin_r = sin(radians), 
        x = point.x,
        y = point.y;

    point.x = x * cos_r - y * sin_r;
    point.y = y * cos_r + x * sin_r;
}

int rotate_points(datapoints_t &data, transform_t degrees, point_t center)
{
    if (data.amount < 1)
        return EMPTY_DATA;

    for (int i = 0; i < data.amount; i++)
    {
        to_center(data.array[i], center);
        if (degrees.kx > EPS)
        {
            rotate_xpoint(data.array[i], degrees.kx);
        }
        if (degrees.ky > EPS)
        {
            rotate_ypoint(data.array[i], degrees.ky);
        }
        if (degrees.kz > EPS)
        {
            rotate_zpoint(data.array[i], degrees.kz);
        }
        from_center(data.array[i], center);
    }

    return OK;
}

int scale_point(point_t &point, transform_t scale)
{
    if (fabs(scale.kx) < EPS || fabs(scale.ky) < EPS || fabs(scale.kz) < EPS) 
        return SMALL_SCALE_ERROR;
    
    point.x = point.x * scale.kx;
    point.y = point.y * scale.ky;
    point.z = point.z * scale.kz;
    
    return OK;
}

int scale_points(datapoints_t &data, transform_t scale, point_t center)
{
    if (data.amount < 1)
        return EMPTY_DATA;

    int i = 0,
        error_code = OK;

    while (error_code == OK && i < data.amount)
    {
        to_center(data.array[i], center);
        error_code = scale_point(data.array[i], scale);
        from_center(data.array[i++], center);
    }

    return error_code;
}

void move_point(point_t &point, transform_t move)
{
    point.x += move.kx;
    point.y += move.ky;
    point.z += move.kz;
}

int move_points(datapoints_t &data, transform_t move)
{
    if (data.amount < 1)
        return EMPTY_DATA;

    for (int i = 0; i < data.amount; i++)
    {
        move_point(data.array[i], move);
    }

    return OK;
}

int check_points(datapoints_t &data)
{
    if (data.amount >= MIN_POINTS)
        return OK;
    else
        return INSUFFICIENT_POINTS;
}

static double max(double a, double b)
{
    return a > b ? a : b;  
}

static double min(double a, double b)
{
    return a < b ? a : b;  
}

static void find_max(point_t &max_point, point_t *array, int n)
{
    double  x_max = array[0].x,
            y_max = array[0].y,
            z_max = array[0].z;
           
    for (int i = 1; i < n; i++)
    {
        x_max = max(array[i].x, x_max);
        y_max = max(array[i].y, y_max);
        z_max = max(array[i].z, z_max);
    }

    max_point.x = x_max, max_point.y = y_max, max_point.z = z_max;
}

static void find_min(point_t &min_point, point_t *array, int n)
{
    double  x_min = array[0].x,
            y_min = array[0].y,
            z_min = array[0].z;
           
    for (int i = 1; i < n; i++)
    {
        x_min = min(array[i].x, x_min);
        y_min = min(array[i].y, y_min);
        z_min = min(array[i].z, z_min);
    }

    min_point.x = x_min, min_point.y = y_min, min_point.z = z_min;
}

int find_center(point_t &center, datapoints_t data)
{
    if (data.amount < MIN_POINTS)
        return INSUFFICIENT_POINTS;
    
    point_t max_point, min_point;
    find_max(max_point, data.array, data.amount);
    find_min(min_point, data.array, data.amount);

    center.x = (max_point.x + min_point.x) / 2;
    center.y = (max_point.y + min_point.y) / 2;
    center.z = (max_point.z + min_point.z) / 2;
    
    return OK;
}

int alloc_points(point_t *&array, int amount)
{
    void *arr_p = NULL;
    int error_code = alloc_array(arr_p, amount, sizeof(point_t));
    array = static_cast<point_t *>(arr_p);

    return error_code;
}

/*
    Free's array and set to NULL
*/
void free_points(point_t *&points)
{
    free_array(static_cast<void *>(points));
    points = NULL;
}