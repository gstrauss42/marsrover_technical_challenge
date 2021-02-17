# marsrover_technical_challenge

### A program to move rovers around a map, run from the terminal

##### Preface:
>This code was written on linux and has not been checked for compatability with other operating systems, as such there may be compilation errors if you compile on windows

##### To Compile:
>make

>alternativley

>gcc main.c sources/*.c -o rover

##### To Run:
>./rover "5 5" "1 2 N" "LMLMLMLMM" "3 3 E" "MMRMMRMRRM" 

>(the input example given in the question)

##### Test Cases:
>sh test_cases.sh

##### Unit Tests:
>gcc unit_tests.c -o unit_tests
>./unit_tests

### Assumptions made

> Given that the pdf asks for all assumptions to be documented I assumed that I should include some logical assumptions

> I assumed that a rover is not supposed to be able to exceed the bounds of the map and subsequentally stopped moving upon leaving the map

>I assumed that because rovers move sequentially they could collide and gave the error "a rover has collided with another rover" when they occupied the same space due to movement

>I assumed that map co-ordinates could only be positive as it indicates the upper right as the given co-ordinates and the bottom left co-ordinates are 0, 0
