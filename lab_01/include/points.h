#ifndef _POINTS_H_
#define _POINTS_H_
#include <stdlib.h>
#include <math.h>
#include "errors.h"
#include "def.h"

typedef double  type_point;
typedef int     type_id;
typedef double  transfer_data;

typedef struct 
{
    type_point  x,
                y,
                z;
} point_t;

typedef struct
{
    int amount = 0;
    point_t *array = NULL;
} datapoints_t;

typedef struct
{
    transfer_data   kx,
                    ky,
                    kz;
} transfer_t;

double to_radians(double degrees);
void rotate_xpoint(point_t &point, double degree, point_t center);
void rotate_ypoint(point_t &point, double degree, point_t center);
void rotate_zpoint(point_t &point, double degree, point_t center);
int rotate_points(datapoints_t &data, transfer_t degrees, point_t center);
int scale_point(point_t &point, transfer_t scale, point_t center);
int scale_points(datapoints_t &data, transfer_t scale, point_t center);
void move_point(point_t &point, transfer_t move);
int move_points(datapoints_t &data, transfer_t move);
int check_points(datapoints_t &data);
int find_center(point_t &center, datapoints_t data);
#endif