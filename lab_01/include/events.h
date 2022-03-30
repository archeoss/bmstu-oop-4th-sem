#ifndef _EVENTS_H_
#define _EVENTS_H_

#include "figure.h"
#include "io.h"
#include "draw.h"
#include "backup.h"
#include <stdlib.h>

typedef struct 
{
    const char *filename;
} load_data;

typedef struct 
{
    const char *filename;
} save_data;

typedef struct 
{
    point_t point;
} center_data;

typedef struct 
{
    point_t point;
    transform_t trasnform;
} rotate_data;

typedef struct
{
    point_t point;
    transform_t trasnform;
} scale_data;

typedef struct
{
    transform_t trasnform;
} move_data;

typedef struct
{
    painter_t painter;
} draw_data;

typedef struct
{
    point_t center;
} find_center_data;

typedef struct 
{
    int task;
    union
    {
        load_data load;
        save_data save;
        center_data center;
        rotate_data rotate;
        scale_data scale;
        move_data move;
        draw_data draw;
        find_center_data find_center;
    };
} request_t;

typedef struct
{
    const char *filename;
} backup_data;

void fill_draw_request(draw_data &data, painter_t painter);

void fill_load_request(load_data &data, const char *filename);

void fill_save_request(save_data &data, const char *filename);

void fill_center_request(center_data &data, point_t center);

void fill_move_request(move_data &data, transform_t transform);

void fill_scale_request(scale_data &data, transform_t transform, point_t center);

void fill_rotate_request(rotate_data &data, transform_t transform, point_t center);

void retrieve_center_request(point_t &center, find_center_data data);

int center(figure_t &figure, center_data data);

int save(save_data data, figure_t &figure);

int load(figure_t &figure, load_data data);

int rotate(figure_t &figure, rotate_data data);

int move(figure_t &figure, move_data data);

int scale(figure_t &figure, scale_data data);

int draw(figure_t &figure, draw_data data);

int find_cntr(find_center_data &data, figure_t figure);

int reset(figure_t &figure);

int save_figure(figure_t figure);


#endif