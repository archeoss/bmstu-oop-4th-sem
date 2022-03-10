#ifndef _ERRORS_H_
#define _ERRORS_H_

#define OK                  0
#define INPUT_ERROR         -1
#define INCORRECT_DATA      -2
#define ALLOC_ERROR         -3
#define EMPTY_DATA          -4
#define SMALL_SCALE_ERROR   -5
#define FIGURE_NOT_CREATED  -6
#define FILE_NOT_EXIST      -7
#define UNKNOWN_COMMAND     -8
#define INSUFFICIENT_POINTS -9
#define INSUFFICIENT_LINKS  -10
#define CANNOT_OPEN_DIALOG  -11
#define NO_BACKUP           -12
#define EDGES_EXCEED_POINTS -13

#include <QMessageBox>
#include <stdlib.h>
void log_error(int err);

#endif