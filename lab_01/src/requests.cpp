#include "requests.h"

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
            error_code = find_cntr(request.find_center, figure);
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

