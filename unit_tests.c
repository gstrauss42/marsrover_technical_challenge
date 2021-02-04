#include "rover.h"

int main(void)
{
    // test 1: move 2 forward
    write(1, "running test ./rover \"100 100\" \"45 43 N\" \"MM\"\n", 46);
    write(1, "expected output: 45 45 N\n", 25);
    system("./rover '100 100' '45 43 N' 'MM'");
    write(1, "\n", 1);
    // test 2: move in a square counterclockwise
    write(1, "running test ./rover \"1000 1000\" \"440 460 N\" \"LMLMLMLM\"\n", 56);
    write(1, "expected output: 450 450 N\n", 27);
    system("./rover '1000 1000' '450 450 N' 'LMLMLMLM'");
    write(1, "\n", 1);
    // test 3: move in a square clockwise
    write(1, "running test ./rover \"1000 1000\" \"440 460 N\" \"RMRMRMRM\"\n", 56);
    write(1, "expected output: 450 450 N\n", 27);
    system("./rover '1000 1000' '450 450 N' 'RMRMRMRM'");
    write(1, "\n", 1);
    // test 4: a rover driving off the map
    write(1, "running test ./rover \"45 45\" \"45 42 N\" \"MM\"\n", 44);
    write(1, "expected output: a rover has driven off the map 45 46 N\n", 56);
    system("./rover '45 45' '45 42 N' 'MMMM'");
    write(1, "\n", 1);
    // test 5: a rover occupying the same space as another rover
    write(1, "running test ./rover \"100 100\" \"42 45 N\" \"MMM\" \"45 42 N\" \"MMM\"\n", 63);
    write(1, "expected output: a rover has collided with another rover 45 45 E 45 45 N\n", 73);
    system("./rover '100 100' '42 45 E' 'MMM' '45 42 N' 'MMM'");
    write(1, "\n", 1);
}