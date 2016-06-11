FLAGS=-Wextra -Wall -Werror -pedantic -std=c99

all: start

start: main.o linearlist.o iterator.o
	gcc $(FLAGS) -o kp8 linearlist.o iterator.o main.o

main.o: main.c
	gcc -c $(FLAGS) main.c

linearlist.o: linearlist.c
	gcc -c $(FLAGS) linearlist.c

iterator.o: iterator.c
	gcc -c $(FLAGS) iterator.c

clear:
	-rm -f *.o *.gch kp8