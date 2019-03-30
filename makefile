CC = gcc
CFLAGS = -I .\include -Wall

all: main clean

main:
	$(CC) .\src\main.c -o .\bin\main $(CFLAGS)

clean:
	del /S *.o
	#delete all object files created for the executable	