CROSS_COMPILE ?=

CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall
OBJ = writer.o

all: writer

writer: $(OBJ)
	$(CC) $(CFLAGS) -o writer $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f writer *.o

.PHONY: all clean
