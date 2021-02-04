#include "rover.h"

int main(int argc, char **argv)
{
    int x_max = 0, y_max = 0, count = 0, r_count = 0, counter = 0;
    rover   **rovers = (rover **)malloc(sizeof(rover **) *((argc + 1) / 2));

// ensures that it shouldn't crash
    if(minor_validation(argv, argc) == 0)
        return(0);
    // sets up the map bounds
    while(argv[1][count])
    {
        while(argv[1][count] == ' ' || argv[1][count] == '\t' || argv[1][count] == '\r' || argv[1][count] == '\n' || argv[1][count] == '\v' || argv[1][count] == '\f')
            count++;
        if(x_max != 0)
            y_max = position_capture(&argv[1][count]);
        else
            x_max = position_capture(&argv[1][count]);
        while(argv[1][count] && argv[1][count] >= 48 && argv[1][count] <= 57)
            count++;
    }
    count = 2;
    //stores arguments in the rover struct
    while(argv[count])
    {
        rovers[r_count] = (rover *)malloc(sizeof(rover *));
        while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
            counter++;
        rovers[r_count]->x_coord = position_capture(&argv[count][counter]);
        while(argv[count][counter] >= 48 && argv[count][counter] <= 57)
            counter++;
        while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
            counter++;
        rovers[r_count]->y_coord = position_capture(&argv[count][counter]);
        while(argv[count][counter] >= 48 && argv[count][counter] <= 57)
            counter++;
        while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
            counter++;
        rovers[r_count]->direction = argv[count][counter];
        count++;
        rovers[r_count]->instructions = strdup(argv[count]);
        count++;
        r_count++;
        counter = 0;
    }
    rovers[r_count] = NULL;
    count = 0;
    r_count = 0;
    counter = 0;

    // calculates rover final positions
    while(rovers[r_count])
    {
        while(rovers[r_count]->instructions[count])
        {
            rovers[r_count] = movement(rovers[r_count], rovers[r_count]->instructions[count]);
            // a crash check
            while(rovers[counter])
            {
                if(rovers[r_count]->x_coord == rovers[counter]->x_coord && rovers[r_count]->y_coord == rovers[counter]->y_coord && r_count != counter)
                {
                    write(1, "a rover has collided with another rover\n", 40);
                    counter = -1;
                    break;
                }
                counter++;
            }
            count++;
            while(counter == -1 && rovers[r_count]->instructions[count])
                count++;
            counter = 0;
        }
        count = 0;
        r_count++;
    }
    r_count = 0;
    // outputs rovers final positions
    while(rovers[r_count])
    {
        if(rovers[r_count]->x_coord > x_max || rovers[r_count]->x_coord < 0 || rovers[r_count]->y_coord > y_max || rovers[r_count]->y_coord < 0)
            write(1, "the rover fell off the map\n", 27);
        else
        {
            write(1, itoa(rovers[r_count]->x_coord), strlen(itoa(rovers[r_count]->x_coord)));
            write(1, " ", 1);
            write(1, itoa(rovers[r_count]->y_coord), strlen(itoa(rovers[r_count]->y_coord)));
            write(1, " ", 1);
            write(1, &rovers[r_count]->direction, 1);
            write(1, "\n", 1);
        }
        r_count++;
    }
    return(1);
}