mycomp: complex.o mycomp.o input_validations.o
	gcc -g complex.o mycomp.o input_validations.o -ansi -Wall -pedantic -lm -o mycomp
complex.o: complex.c complex.h
	gcc -c complex.c -ansi -Wall -pedantic -o complex.o
mycomp.o: mycomp.c complex.h mycomp.h
	gcc -c mycomp.c -ansi -Wall -pedantic -o mycomp.o
input_validations.o: input_validations.c
	gcc -c input_validations.c -ansi -Wall -pedantic -o input_validations.o
