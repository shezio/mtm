mycomp: complex.o mycomp.o validations.o
	gcc -g complex.o mycomp.o validations.o -ansi -Wall -pedantic -lm -o mycomp
complex.o: complex.c complex.h
	gcc -c complex.c -ansi -Wall -pedantic -o complex.o
mycomp.o: mycomp.c complex.h mycomp.h
	gcc -c mycomp.c -ansi -Wall -pedantic -o mycomp.o
validations.o: validations.c
	gcc -c validations.c -ansi -Wall -pedantic -o validations.o
