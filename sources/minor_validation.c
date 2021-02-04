#include "../rover.h"

int minor_validation(char **av, int ac)
{
    int count = 0;
    //checks for the correct number of arguments
    if(ac % 2 != 0)
        return(0);
    //checks that none of the arguments are NULL
    while(av[count])
    {
        if(av[count] && av[count][0])
            count++;
        else
            return(0);
    }
    return(1);
}