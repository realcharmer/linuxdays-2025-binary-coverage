CC = gcc
CFLAGS = -Wall -Wextra -O0 -fprofile-arcs -ftest-coverage
TARGET = stringutils
SRC = stringutils.c
PYTEST = pytest -v

.PHONY: all build test clean

all: build

build: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

test: build
	$(PYTEST)

clean:
	rm -f $(TARGET) *.gcda *.gcno *.gcov
