TARGET = spy
LIBS =   -lm -ldl -lrt
CC = gcc
CFLAGS = -fomit-frame-pointer
EXTLIBS = .

.PHONY: default all clean

default: $(TARGET)
all: default

C_OBJECTS = $(patsubst %.c, %.c.o, $(wildcard *.c))
S_OBJECTS = $(patsubst %.s, %.s.o, $(wildcard *.s))
HEADERS = $(wildcard *.h)

%.c.o: %.c $(HEADERS)
	$(CC) -L$(EXTLIBS) $(CFLAGS) $(LIBS) -c $< -o $@
	
%.s.o: %.s
	$(CC) -c $< -o $@

.PRECIOUS: $(TARGET) $(C_OBJECTS)

$(TARGET): $(S_OBJECTS) $(C_OBJECTS)
	$(CC) -L$(EXTLIBS) $(S_OBJECTS) $(C_OBJECTS) -Wall $(LIBS)   -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
