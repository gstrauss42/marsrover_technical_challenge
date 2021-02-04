#include "../rover.h"

int position_capture(char *string)
{
    int ret = 0;
    int count = 0;
    while(string[count] && string[count] >= 48 && string[count] <= 57)
    {
        ret = ret * 10 + string[count] - 48;
        count++;
    }
    return(ret);
}