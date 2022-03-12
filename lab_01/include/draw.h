#ifndef _DRAW_H_
#define _DRAW_H_

#include "figure.h"
#include <QGraphicsScene>

typedef struct
{
    QGraphicsScene *scene;
    double width;
    double height;
} painter_t;

int draw_figure(painter_t &painter, figure_t figure);

#endif