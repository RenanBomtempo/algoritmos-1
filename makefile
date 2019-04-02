# FLAGS 
CC = gcc
CFLAGS = -I .\include -Wall

# MAKES
all: main clean

# MAIN FILE
main: cand.o univ.o process.o
	$(CC) .\src\main.c cand.o univ.o process.o -o .\bin\main $(CFLAGS)

# OBJECT FILES
cand.o:
	$(CC) -c .\src\cand.c $(CFLAGS)

univ.o:
	$(CC) -c .\src\univ.c $(CFLAGS)

sort.o:
	$(CC) -c .\src\sort.c $(CFLAGS)

process.o:
	$(CC) -c .\src\process.c $(CFLAGS)

# CLEAN OBJECT FILES
clean:
	del /S *.o
	#delete all object files created for the executable	