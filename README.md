# marsrover_technical_challenge

A program to move rovers around a map, run from the terminal

To compile: run make, alternativley gcc main.c sources/*.c -o rover

To run    : ./rover "5 5" "1 2 N" "LMLMLMLMM" "3 3 E" "MMRMMRMRRM" 
(the input example given in the question)

to run test cases: sh test_cases.sh

to run unit tests: gcc unit_tests.c then ./a.out

### Assumptions made

> Given that the pdf asks for all assumptions to be documents I assumed that I should include some logical assumptions
> I assumed that a rover is not supposed to be able to exceed the bounds of the map and subsequentally stopped moving upon leaving the map
>I pressumed that because rovers move sequentially they could collide and gave the error "a rover has collided with another rover" when they occupied the same space due to movement
>I pressumed that map co-ordinates could only be positive as it indicates the upper right as the given co-ordinates and the bottom left are 0, 0
>the repo contains both the rover executable and the unit tests executable compiled on a linux system





