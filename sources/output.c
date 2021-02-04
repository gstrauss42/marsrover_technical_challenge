#include "../rover.h"

void    output(rover **rovers, int x_max, int y_max)
{
    int r_count = 0;
    while(rovers[r_count])
    {
        write(1, itoa(rovers[r_count]->x_coord), strlen(itoa(rovers[r_count]->x_coord)));
        write(1, " ", 1);
        write(1, itoa(rovers[r_count]->y_coord), strlen(itoa(rovers[r_count]->y_coord)));
        write(1, " ", 1);
        write(1, &rovers[r_count]->direction, 1);
        write(1, "\n", 1);
        r_count++;
    }
}