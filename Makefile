CC=g++
CFLAGS=-I -Wall.
DEPS = input.h error.h output.h sort.h file.h onegin.h
OBJ = main.o input.o error.o output.o sort.o file.o onegin.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean :
	rm *.o
