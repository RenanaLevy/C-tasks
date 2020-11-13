CC= gcc -Wall
all: mains maind

# creating mains- with static library
mains: main.o libmyMath.a
	$(CC) main.o -lmyMath -L. -o mains

# creating static library
libmyMath.a: power.o basicMath.o
	ar rcs libmyMath.a power.o basicMath.o

# creating maind- with dynamic library
maind: main.o libmyMath.so
	$(CC) main.o -lmyMath -L. -o maind

# creating dynamic library
libmyMath.so: power.o basicMath.o
	$(CC) -fPIC -c power.c -o power.o
	$(CC) -fPIC -c basicMath.c -o basicMath.o
	gcc -shared power.o basicMath.o -o libmyMath.so

mymaths: libmyMath.a
mymathd: libmyMath.so

# compile power
power.o: power.c
	$(CC) -c power.c -o power.o

# compile basicMath
basicMath.o: basicMath.c
	$(CC) -c basicMath.c -o basicMath.o

# compile main
main.o: main.c myMath.h
	$(CC) -c main.c -o main.o


.PHONY: all clean

clean:
	rm *.o *.a *.so maind mains