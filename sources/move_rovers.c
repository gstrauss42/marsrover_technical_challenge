#include "../rover.h"

void    move_rovers(rover ***rovers, int x_max, int y_max)
{
    int err = 0;
    int r_count = 0;
    int count = 0;
    int counter = 0;

    while((*rovers)[r_count])
    {
        while((*rovers)[r_count]->instructions[count])
        {
            (*rovers)[r_count] = movement((*rovers)[r_count], (*rovers)[r_count]->instructions[count]);
            // out of bounds check
            if((*rovers)[r_count]->x_coord > x_max || (*rovers)[r_count]->y_coord > y_max)
            {
                write(1, "a rover has driven off the map\n", 31);
                err = -1;
            }
            // a crash check
            while((*rovers)[counter])
            {
                if((*rovers)[r_count]->x_coord == (*rovers)[counter]->x_coord && (*rovers)[r_count]->y_coord == (*rovers)[counter]->y_coord && r_count != counter)
                {
                    write(1, "a rover has collided with another rover\n", 40);
                    err = -1;
                    break;
                }
                counter++;
            }
            count++;
            while(err == -1 && (*rovers)[r_count]->instructions[count])
                count++;
            counter = 0;
        }
        count = 0;
        r_count++;
    }
}