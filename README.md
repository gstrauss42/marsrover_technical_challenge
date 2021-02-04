# marsrover_technical_challenge

To compile: run make, alternativley gcc main.c sources/*.c -o rover

To run    : ./rover "5 5" "1 2 N" "LMLMLMLMM" "3 3 E" "MMRMMRMRRM" 
(the input example given in the question)

Ipressumed that a rover is not supposed to be able to exceed the bounds of the map and gave an error when it ended up outside the map

I pressumed that because rovers move sequentially they could collide and gave the error "the rover crashed into another rover" when they occupied the same space due to movement

