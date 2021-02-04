#include "rover.h"

int main(int argc, char **argv)
{
    int x_max = 0, y_max = 0, count = 0, r_count = 0, counter = 0;
    rover   **rovers = (rover **)malloc(sizeof(rover **) *((argc + 1) / 2));

    if(argc >= 4)
    {
        while(argv[1][count])
        {
            while(argv[1][count] == ' ' || argv[1][count] == '\t' || argv[1][count] == '\r' || argv[1][count] == '\n' || argv[1][count] == '\v' || argv[1][count] == '\f')
                count++;
            if(x_max != 0)
                y_max = argv[1][count];
            else
                x_max = argv[1][count];
            count++;
        }
        count = 2;
        while(argv[count])
        {
            rovers[r_count] = (rover *)malloc(sizeof(rover *));
            while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
                counter++;
            rovers[r_count]->x_coord = position_capture(&argv[count][counter++]);
            while(argv[count][counter] == ' ' || argv[count][counter] == '\t' || argv[count][counter] == '\r' || argv[count][counter] == '\n' || argv[count][counter] == '\v' || argv[count][counter] == '\f')
                counter++;
            rovers[r_count]->y_coord = position_capture(&argv[count][counter++]);            
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
        
        // calculate rover final positions
        while(rovers[r_count])
        {
            while(rovers[r_count]->instructions[count])
            {
                rovers[r_count] = movement(rovers[r_count], rovers[r_count]->instructions[count]);
                count++;
            }
            count = 0;
            r_count++;
        }
        r_count = 0;
        // outputting rovers final positions
        while(rovers[r_count])
        {
            write(1, itoa(rovers[r_count]->x_coord), 1);
            write(1, " ", 1);
            write(1, itoa(rovers[r_count]->y_coord), 1);
            write(1, " ", 1);
            write(1, &rovers[r_count]->direction, 1);
            write(1, "\n", 1);
            r_count++;
        }
    }
    return(0);
}