#include "draw.h"

static void draw_edge(painter_t painter, datapoints_t points, edge_t edge)
{
    point_t point_a = points.array[edge.point_a];
    point_t point_b = points.array[edge.point_b];

    painter.scene->addLine(
        painter.width / 2 + point_a.x,
        painter.height / 2 - point_a.y,
        painter.width / 2 + point_b.x,
        painter.height / 2 - point_b.y
   );
}

static void draw_edges(painter_t painter, dataedges_t edges, datapoints_t points)
{
    for (int i = 0; i < edges.amount; i++)
    {
        draw_edge(painter, points, edges.array[i]);
    }
}

int draw_figure(painter_t &painter, figure_t figure)
{
    int error_code = check_figure(figure);
    if (error_code != OK)
        return error_code;
    
    draw_edges(painter, figure.edges, figure.points);
    
    return error_code;
}