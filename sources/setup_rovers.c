#include "../rover.h"

void    setup_rovers(rover ***rovers, char **argv)
{
    int count = 2;
    int counter = 0;
    int r_count = 0;

    while(argv[count])
    {
        (*rovers)[r_count] = (rover *)malloc(sizeof(rover *));
        while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
            counter++;
        (*rovers)[r_count]->x_coord = position_capture(&argv[count][counter]);
        while(argv[count][counter] >= 48 && argv[count][counter] <= 57)
            counter++;
        while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
            counter++;
        (*rovers)[r_count]->y_coord = position_capture(&argv[count][counter]);
        while(argv[count][counter] >= 48 && argv[count][counter] <= 57)
            counter++;
        while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
            counter++;
        (*rovers)[r_count]->direction = argv[count][counter];
        count++;
        (*rovers)[r_count]->instructions = strdup(argv[count]);
        count++;
        r_count++;
        counter = 0;
    }
    (*rovers)[r_count] = NULL;
}