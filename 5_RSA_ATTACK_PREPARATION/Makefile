TARGET = slowdown
LIBS =   -lm -ldl -lrt
CC = gcc
CFLAGS = -fomit-frame-pointer
EXTLIBS = .

.PHONY: default all clean

default: slowdown
all: default

SLOWDOWN_OBJECTS = slowdown.c.o map.c.o clflush.s.o delay.s.o memaccesstime.s.o
HEADERS = $(wildcard *.h)

%.c.o: %.c $(HEADERS)
	$(CC) -L$(EXTLIBS) $(CFLAGS) $(LIBS) -c $< -o $@
	
%.s.o: %.s
	$(CC) -c $< -o $@

.PRECIOUS: $(TARGET) $(C_OBJECTS)

slowdown: $(SLOWDOWN_OBJECTS)
	$(CC) -L$(EXTLIBS) $(SLOWDOWN_OBJECTS) -Wall $(LIBS)   -o slowdown
	
clean:
	-rm -f *.o
	-rm -f slowdown
	-rm -f result.csv
