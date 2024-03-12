
all: printy

printy: main.o
	./bin/main.o

main.o: ./src/main.c
	gcc -o ./bin/main.o ./src/main.c

clean:
	rm ./bin/*.o