# Makefile for test

CC = gcc
CFLAGS = -I$(IDIR)

IDIR = include
ODIR = obj
LDIR = lib
SDIR = src

LIBS =

_DEPS = dbg.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS = main.o dbg.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

TARGET = demo

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY : clean

clean :
	rm -f $(ODIR)/*.o $(TARGET)
