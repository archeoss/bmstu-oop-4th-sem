#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include "figure.h"
#include "errors.h"
#include "alloc.h"

int save_figure(const char *filename, figure_t figure);
int load_figure(figure_t &figure, const char *filename);

#endif