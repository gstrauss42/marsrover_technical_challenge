#ifndef ROVER_H
# define ROVER_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct rover_information{
    int     x_coord;
    int     y_coord;
    char    direction;
    char    *instructions;
}              rover;

typedef struct directions{

}              direction;

int     position_capture(char *string);
rover   *movement(rover *the_rover, char instruction);
char	*strdup(const char *str);
char    *itoa(int n);
int     minor_validation(char **av, int ac);
void    setup_map(int *x_max, int *y_max, char **argv);
void    setup_rovers(rover ***rovers, char **argv);
void    move_rovers(rover ***rovers, int x_max, int y_max);
void    output(rover **rovers, int x_max, int y_max);

#endif