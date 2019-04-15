# FLAGS 
CC = gcc
CFLAGS = -I ./include -Wall
VALG = -g 

# MAKES
all: main clean

# MAIN FILE
main: util.o col.o cand.o stblm.o
	$(CC) ./src/main.c   util.o col.o cand.o stblm.o   -o ./bin/main $(CFLAGS) $(VALG)

# OBJECT FILES
cand.o:
	$(CC) -c ./src/cand.c $(CFLAGS)

col.o:
	$(CC) -c ./src/col.c $(CFLAGS)

util.o:
	$(CC) -c ./src/util.c $(CFLAGS)

stblm.o:
	$(CC) -c ./src/stblm.c $(CFLAGS)

# CLEAN OBJECT FILES
clean:
	rm *.o
