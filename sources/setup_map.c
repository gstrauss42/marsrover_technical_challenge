#include "../rover.h"

void    setup_map(int *x_max, int *y_max, char **argv)
{
    int count = 0;
    while(argv[1][count])
    {
        while(argv[1][count] == ' ' || argv[1][count] == '\t' || argv[1][count] == '\r' || argv[1][count] == '\n' || argv[1][count] == '\v' || argv[1][count] == '\f')
            count++;
        if(*x_max != 0)
            *y_max = position_capture(&argv[1][count]);
        else
            *x_max = position_capture(&argv[1][count]);
        while(argv[1][count] && argv[1][count] >= 48 && argv[1][count] <= 57)
            count++;
    }
}