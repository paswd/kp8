FLAGS=-Wextra -Wall -Werror -pedantic -std=c99

all: start

start: main.o linearlist.o
	gcc $(FLAGS) -o kp8 main.o linearlist.o

main.o: main.c
	gcc -c $(FLAGS) main.c

linearlist.o: linearlist.h linearlist.c
	gcc -c $(FLAGS) linearlist.h linearlist.c

clear:
	-rm -f *.o *.gch kp8