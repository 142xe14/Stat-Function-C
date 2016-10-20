CFLAGS = -std=c11 -Wpedantic -Wall -Wextra -Werror -D_XOPEN_SOURCE=600

ex1 : ex1.o
		$(CC) $(CFLAGS) ex1.o -o ex1

ex2 : ex2.o
		$(CC) $(CFLAGS) ex2.o -o ex2

ex1.o : ex1.c
		$(CC) $(CFLAGS) -c ex1.c -o ex1.o

ex2.o : ex2.c
		$(CC) $(CFLAGS) -c ex2.c -o ex2.o

clean :
		$(RM) *.o ex1 ex2

all : ex1 ex2