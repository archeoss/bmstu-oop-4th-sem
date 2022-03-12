#include "points.h"

double to_radians(double degrees)
{
    return degrees * M_PI / 180;
}

void rotate_xpoint(point_t &point, double degree, point_t center)
{
    double radians = to_radians(degree);
    double cos_r = cos(radians);
    double sin_r = sin(radians);
    double y_real = point.y - center.y;
    double z_real = point.z - center.z;

    point.y = y_real * cos_r - z_real * sin_r + center.y;
    point.z = z_real * cos_r + y_real * sin_r + center.z;
}

void rotate_ypoint(point_t &point, double degree, point_t center)
{
    double radians = to_radians(degree);
    double cos_r = cos(radians);
    double sin_r = sin(radians);
    double x_real = point.x - center.x;
    double z_real = point.z - center.z;

    point.x = x_real * cos_r + z_real * sin_r + center.x;
    point.z = z_real * cos_r - x_real * sin_r + center.z;
}

void rotate_zpoint(point_t &point, double degree, point_t center)
{
    double radians = to_radians(degree);
    double cos_r = cos(radians);
    double sin_r = sin(radians);
    double x_real = point.x - center.x;
    double y_real = point.y - center.y;

    point.x = x_real * cos_r - y_real * sin_r + center.x;
    point.y = y_real * cos_r + x_real * sin_r + center.y;
}

int rotate_points(datapoints_t &data, transform_t degrees, point_t center)
{
    if (data.amount < 1)
        return EMPTY_DATA;

    for (int i = 0; i < data.amount; i++)
    {
        if (degrees.kx > EPS)
        {
            rotate_xpoint(data.array[i], degrees.kx, center);
        }
        if (degrees.ky > EPS)
        {
            rotate_ypoint(data.array[i], degrees.ky, center);
        }
        if (degrees.kz > EPS)
        {
            rotate_zpoint(data.array[i], degrees.kz, center);
        }
    }

    return OK;
}

int scale_point(point_t &point, transform_t scale, point_t center)
{
    if (fabs(scale.kx) < EPS || fabs(scale.ky) < EPS || fabs(scale.kz) < EPS) 
        return SMALL_SCALE_ERROR;
    
    point.x = (point.x - center.x) * scale.kx + center.x;
    point.y = (point.y - center.y) * scale.ky + center.y;
    point.z = (point.z - center.z) * scale.kz + center.z;
    
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
        error_code = scale_point(data.array[i++], scale, center);
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

int find_center(point_t &center, datapoints_t data)
{
    if (data.amount < MIN_POINTS)
        return INSUFFICIENT_POINTS;
    
    double  x_max = data.array[0].x, x_min = data.array[0].x,
            y_max = data.array[0].y, y_min = data.array[0].y,
            z_max = data.array[0].z, z_min = data.array[0].z;
           
    for (int i = 1; i < data.amount; i++)
    {
        x_max = max(data.array[i].x, x_max);
        y_max = max(data.array[i].y, y_max);
        z_max = max(data.array[i].z, z_max);
        x_min = min(data.array[i].x, x_min);
        y_min = min(data.array[i].y, y_min);
        z_min = min(data.array[i].z, z_min);
    }

    center.x = (x_max + x_min) / 2;
    center.y = (y_max + y_min) / 2;
    center.z = (z_max + z_min) / 2;
    
    return OK;
}