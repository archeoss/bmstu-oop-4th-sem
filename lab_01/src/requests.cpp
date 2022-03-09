#include "requests.h"

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

void fill_move_request(move_data &data, transfer_t transform)
{
    data.trasnform = transform;
}

void fill_scale_request(scale_data &data, transfer_t transform, point_t center)
{
    data.trasnform = transform;
    data.point = center;
}

void fill_rotate_request(rotate_data &data, transfer_t transform, point_t center)
{
    data.trasnform = transform;
    data.point = center;
}

static int center(figure_t &figure, center_data data)
{
    return center_figure(figure, data.point);
}

static int save(save_data data, figure_t &figure)
{
    return save_figure(data.filename, figure);
}

static int load(figure_t &figure, load_data data)
{
    return load_figure(figure, data.filename);
}

static int rotate(figure_t &figure, rotate_data data)
{
    return rotate_figure(figure, data.trasnform, data.point);
}

static int move(figure_t &figure, move_data data)
{
    return move_figure(figure, data.trasnform);
}

static int scale(figure_t &figure, scale_data data)
{
    return scale_figure(figure, data.trasnform, data.point);
}

static int draw(figure_t &figure, draw_data data)
{
    return draw_figure(data.painter, figure);
}

static int find_c(find_center_data &data, figure_t figure)
{
    return find_center(data.center, figure.points);
}

static int reset(figure_t &figure)
{
    return load_backup(figure);
}

static int save_figure(figure_t figure)
{
    return save_backup(figure);
}

int event_handler(request_t &request)
{
    static figure_t figure = init_figure();
    int error_code = OK;
    switch (request.task)
    {
        case LOAD:
            error_code = load(figure, request.load);
            break;

        case CENTER:
            error_code = center(figure, request.center);
            break;

        case SAVE:
            error_code = save(request.save, figure);
            break;
                    
        case ROTATE:
            error_code = rotate(figure, request.rotate);
            break;
            
        case SCALE:
            error_code = scale(figure, request.scale);
            break;
            
        case MOVE:
            error_code = move(figure, request.move);
            break;
            
        case DRAW:
            error_code = draw(figure, request.draw);
            break;

        case FIND_CENTER:
            error_code = find_c(request.find_center, figure);
            break;

        case SAVE_BACKUP:
            error_code = save_figure(figure);
            break;

        case RESET:
            error_code = reset(figure);
            break;
            
        case EXIT:
            error_code = destroy_figure(figure);
            break;

        default:
            error_code = UNKNOWN_COMMAND;
            break;
    }

    return error_code;
}

