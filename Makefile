CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic
LDFLAGS=-framework CoreFoundation -framework IOKit

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=disable-mouse-acceleration

all: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXECUTABLE) $(OBJECTS)
