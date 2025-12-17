CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = alefetch

SRC = src/main.c src/sysinfo.c src/display.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
