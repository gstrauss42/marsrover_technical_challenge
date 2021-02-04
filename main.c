#include "rover.h"

int main(int argc, char **argv)
{
    int     x_max;
    int     y_max;
    rover   **rovers;
    
    x_max = 0;
    y_max = 0;
    rovers = (rover **)malloc(sizeof(rover **) *((argc + 1) / 2));
    // ensures that it shouldn't crash
    if(minor_validation(argv, argc) == 0)
        return(0);
    // sets up the map bounds
    setup_map(&x_max, &y_max, argv);
    //stores arguments in the rover struct
    setup_rovers(&rovers, argv);
    // calculates rover final positions
    move_rovers(&rovers, x_max, y_max);
    // outputs rover final positions
    output(rovers, x_max, y_max);
    return(1);
}