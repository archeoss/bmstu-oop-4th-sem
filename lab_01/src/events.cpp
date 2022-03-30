#include "events.h"

void fill_draw_request(draw_data &data, painter_t painter)
{
    data.painter = painter;
}

void fill_load_request(load_data &data, const char *filename)
{
    data.filename = filename;
}

void fill_save_request(save_data &data, const char *filename)
{
    data.filename = filename;
}

void fill_center_request(center_data &data, point_t center)
{
    data.point = center;
}

void fill_move_request(move_data &data, transform_t transform)
{
    data.trasnform = transform;
}

void fill_scale_request(scale_data &data, transform_t transform, point_t center)
{
    data.trasnform = transform;
    data.point = center;
}

void fill_rotate_request(rotate_data &data, transform_t transform, point_t center)
{
    data.trasnform = transform;
    data.point = center;
}

void retrieve_center_request(point_t &center, find_center_data data)
{
    center = data.center;
}

int center(figure_t &figure, center_data data)
{
    return center_figure(figure, data.point);
}

int save(save_data data, figure_t &figure)
{
    return save_figure(data.filename, figure);
}

int load(figure_t &figure, load_data data)
{
    return load_figure(figure, data.filename);
}

int rotate(figure_t &figure, rotate_data data)
{
    return rotate_figure(figure, data.trasnform, data.point);
}

int move(figure_t &figure, move_data data)
{
    return move_figure(figure, data.trasnform);
}

int scale(figure_t &figure, scale_data data)
{
    return scale_figure(figure, data.trasnform, data.point);
}

int draw(figure_t &figure, draw_data data)
{
    return draw_figure(data.painter, figure);
}

int find_cntr(find_center_data &data, figure_t figure)
{
    return find_center(data.center, figure.points);
}

int reset(figure_t &figure)
{
    return load_backup(figure);
}

int save_figure(figure_t figure)
{
    return save_backup(figure);
}
