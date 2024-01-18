CC = gcc
CFLAGS = -Wall

# List of object files
OBJ = src/main.o src/print.o

# Rule to build the executable
sudoku_solver: $(OBJ)
	$(CC) $(CFLAGS) -o sudoku_solver $(OBJ) -lm

# Rule to build the object file for main.c
src/main.o: src/main.c src/print.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

# Rule to build the object file for print.c
src/print.o: src/print.c src/print.h
	$(CC) $(CFLAGS) -c src/print.c -o src/print.o

# Clean rule
clean:
	rm -f sudoku_solver $(OBJ)
