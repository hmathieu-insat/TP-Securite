TARGET = secret
LIBS =   -lm -ldl -lrt
CC = gcc
CFLAGS = -fomit-frame-pointer
EXTLIBS = .

.PHONY: default all clean

default: secret
all: default

SECRET_OBJECTS = secret.c.o
HEADERS = $(wildcard *.h)

%.c.o: %.c $(HEADERS)
	$(CC) -L$(EXTLIBS) $(CFLAGS) $(LIBS) -c $< -o $@
	
%.s.o: %.s
	$(CC) -c $< -o $@

.PRECIOUS: $(TARGET) $(C_OBJECTS)
	
secret: $(SECRET_OBJECTS)
	$(CC) -L$(EXTLIBS) $(SECRET_OBJECTS) -Wall $(LIBS)   -o secret

clean:
	-rm -f *.o
	-rm -f secret
