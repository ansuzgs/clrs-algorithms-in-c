CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11

SRC = src/main.c src/complexity_functions.c src/utils.c
OBJ = $(SRC:.c=.o)
EXEC = calc_complexity

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o tests/*.o $(EXEC)

.PHONY: all clean