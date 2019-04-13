# FLAGS 
CC = gcc
CFLAGS = -I ./include -Wall

# MAKES
all: main clean

# MAIN FILE
main: cand.o univ.o utilities.o
	$(CC) ./src/main.c cand.o univ.o utilities.o -o ./bin/main $(CFLAGS)

# OBJECT FILES
cand.o:
	$(CC) -c ./src/cand.c $(CFLAGS)

univ.o:
	$(CC) -c ./src/univ.c $(CFLAGS)

sort.o:
	$(CC) -c ./src/sort.c $(CFLAGS)

utilities.o:
	$(CC) -c ./src/utilities.c $(CFLAGS)

# CLEAN OBJECT FILES
clean:
	rm *.o
