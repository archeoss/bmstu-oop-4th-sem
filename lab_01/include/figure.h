#ifndef _FIGURE_H_
#define _FIGURE_H_

#include "edges.h"
#include "alloc.h"
#include <stdlib.h>

#define MAX_STR_SIZE 256

typedef struct
{
    char *          name;
    datapoints_t    points;
    dataedges_t     edges;
} figure_t;

figure_t &init_figure(void);
figure_t &init_figure(const char *name);

int destroy_figure(figure_t &figure);
int rotate_figure(figure_t &figure, transform_t degrees, point_t center);
int center_figure(figure_t &figure, point_t center);
int move_figure(figure_t &figure, transform_t transform);
int scale_figure(figure_t &figure, transform_t transform, point_t center);

void free_data(dataedges_t data);
void free_data(datapoints_t data);
int check_figure(figure_t figure);

#endif