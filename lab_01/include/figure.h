#ifndef _FIGURE_H_
#define _FIGURE_H_

#include "points.h"
#include "edges.h"
#include "alloc.h"
#include "def.h"
typedef struct
{
    int             created;
    char *          name;
    datapoints_t    points;
    dataedges_t     edges;
} figure_t;

figure_t &init_figure(void);

int destroy_figure(figure_t &figure);
int rotate_figure(figure_t &figure, transfer_t degrees, point_t center);
int center_figure(figure_t &figure, point_t center);
int move_figure(figure_t &figure, transfer_t transform);
int scale_figure(figure_t &figure, transfer_t transform, point_t center);

template <typename data_type>
void free_data(data_type data);
int check_figure(figure_t figure);

#endif