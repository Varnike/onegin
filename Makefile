CC=g++
CFLAGS=-I.
DEPS = input.h config.h error.h output.h sort.h
OBJ = test.o input.o error.o output.o sort.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean :
	rm *.o
