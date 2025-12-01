CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/bubble_sort.c src/insertion_sort.c src/selection_sort.c src/shell_sort.c src/quick_sort.c src/merge_sort.c src/heap_sort.c src/radix_sort.c src/file_generator.c src/file_operations.c
OBJ = $(SRC:.c=.o)
TARGET = output/main

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p output
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
