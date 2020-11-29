CC = gcc -Wall
all: mains

mains: main.o libmyBank.a
$(CC) main.o -lmybank -L. -o mains

libmyBank.a: myBank.o 
ar rcs libmyBank.a myBank.o

myBank.o: myBank.c
$(CC) -c myBank.o -o myBank.c

main.o: main.c myBank.h
$(CC) -c main.c -o main.o

.PHONEY all clean

clean: rm *.o *.a mains