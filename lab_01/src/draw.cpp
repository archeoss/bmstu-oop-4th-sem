#include "draw.h"

static void draw_line(scene_t scene, double x_a, double y_a, double x_b, double y_b)
{
    scene->addLine(x_a, y_a, x_b, y_b);
}

static void draw_edge(painter_t painter, datapoints_t points, edge_t edge)
{
    point_t 
        point_a = points.array[edge.point_a],
        point_b = points.array[edge.point_b];

    double 
        screen_xa = painter.width / 2 + point_a.x,
        screen_ya = painter.height / 2 - point_a.y,
        screen_xb = painter.width / 2 + point_b.x,
        screen_yb = painter.height / 2 - point_b.y;
 
    draw_line(painter.scene, screen_xa, screen_ya, screen_xb, screen_yb);
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
    if (error_code == OK)
        draw_edges(painter, figure.edges, figure.points);
    
    return error_code;
}