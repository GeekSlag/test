# Makefile for test

CC = gcc
CFLAGS = -g -Wall -I$(IDIR)

IDIR = include
ODIR = obj
LDIR = lib
SDIR = source
LIBS =

_DEPS = debug.h list.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS = main.o debug.o list.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

TARGET = a.out

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY : clean

clean :
	rm -f $(ODIR)/*.o $(TARGET)
