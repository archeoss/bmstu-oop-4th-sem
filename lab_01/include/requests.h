#ifndef _REQUESTS_H_
#define _REQUESTS_H_

#include "figure.h"
#include "io.h"
#include "draw.h"
#include "backup.h"
#include "events.h"

enum TASKS {LOAD, SAVE, SAVE_BACKUP, CENTER, ROTATE, FIND_CENTER, SCALE, MOVE, DRAW, RESET, EXIT};

int event_handler(request_t &);

#endif