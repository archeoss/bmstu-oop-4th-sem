#include "backup.h"

int save_backup(figure_t figure)
{
    char back_file[MAX_STR_SIZE];
    strcpy(back_file, figure.name);
    strcat(back_file, "_backup.csv");

    return save_figure(back_file, figure);
}

int load_backup(figure_t &figure)
{
    int error_code = OK;
    char back_file[MAX_STR_SIZE];
    char name[MAX_STR_SIZE];
    strcpy(name, figure.name);
    strcpy(back_file, figure.name);
    strcat(back_file, "_backup.csv");
    FILE *f = fopen(back_file, "r");
    if (f != NULL)
    {
        fclose(f);
        error_code = load_figure(figure, back_file);
    }
    if (error_code == OK)
    {
        strcpy(figure.name, name); 
    }
    if (error_code != OK)
    {
        error_code = NO_BACKUP;
    }

    return error_code;
}