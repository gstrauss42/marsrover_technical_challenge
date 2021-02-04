#include "../rover.h"

rover *movement(rover *the_rover, char instruction)
{
    if(instruction == 'M')
    {
        if(the_rover->direction == 'N')
            the_rover->y_coord = the_rover->y_coord + 1;
        else if(the_rover->direction == 'E')
            the_rover->x_coord = the_rover->x_coord + 1;
        else if(the_rover->direction == 'S')
            the_rover->y_coord = the_rover->y_coord - 1;
        else if(the_rover->direction == 'W')
            the_rover->x_coord = the_rover->x_coord - 1;
    }
    else if(instruction == 'R')
    {
        if(the_rover->direction == 'N')
            the_rover->direction = 'E';
        else if(the_rover->direction == 'E')
            the_rover->direction = 'S';
        else if(the_rover->direction == 'S')
            the_rover->direction = 'W';
        else if(the_rover->direction == 'W')
            the_rover->direction = 'N';
    }
    else if(instruction == 'L')
    {
        if(the_rover->direction == 'N')
            the_rover->direction = 'W';
        else if(the_rover->direction == 'W')
            the_rover->direction = 'S';
        else if(the_rover->direction == 'S')
            the_rover->direction = 'E';
        else if(the_rover->direction == 'E')
            the_rover->direction = 'N';
    }
    return(the_rover);
}