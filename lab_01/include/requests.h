#ifndef _REQUESTS_H_
#define _REQUESTS_H_

#include "figure.h"
#include "io.h"
#include "draw.h"
#include "backup.h"
enum TASKS {LOAD, SAVE, SAVE_BACKUP, CENTER, ROTATE, FIND_CENTER, SCALE, MOVE, DRAW, RESET, EXIT};

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
    transfer_t trasnform;
} rotate_data;

typedef struct
{
    point_t point;
    transfer_t trasnform;
} scale_data;

typedef struct
{
    transfer_t trasnform;
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
void fill_move_request(move_data &data, transfer_t transform);
void fill_scale_request(scale_data &data, transfer_t transform, point_t center);
void fill_rotate_request(rotate_data &data, transfer_t transform, point_t center);
void fill_center_request(center_data &data, point_t center);
void retrieve_center_request(point_t &center, find_center_data data);

int event_handler(request_t &);

#endif