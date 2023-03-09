my_string : my_string.o functions.o
	gcc -g -ansi -Wall -pedantic my_string.o functions.o -o my_string
my_string.o : my_string.c my_string.h
	gcc -c -ansi -Wall -pedantic my_string.c -o my_string.o
functions.o : functions.c
	gcc -c -ansi -Wall -pedantic functions.c -o functions.o