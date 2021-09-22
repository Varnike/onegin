CC=g++
CFLAGS=-I -Wall.
DEPS = input.h error.h output.h sort.h file.h
OBJ = test.o input.o error.o output.o sort.o file.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean :
	rm *.o
