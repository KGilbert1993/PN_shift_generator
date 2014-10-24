# Default makefile 
# 24 October 2014
# Kevin Gilbert
# Pseudo Noise shift register generator

CC=gcc
CFLAGS=-c
LDFLAGS=
SOURCES=main.c pn_gen.c
SOURCES_2=main.c scrambler.c
OBJECTS=$(SOURCES:.c=.o)
OBJECTS_2=$(SOURCES_2:.c=.o)
EXECUTABLE=gen
EXECUTABLE_2=scramble

all: $(SOURCES) $(EXECUTABLE)

scramble: $(SOURCES_2) $(EXECTUABLE_2)

$(EXECUTABLE_2): $(OBJECTS_2)
	$(CC) $(LDFLAGS) $(OBJECTS_2) -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CLFAGS) $< -o $@

clean_gen: 
	rm -rf *o $(EXECUTABLE_1)

clean_scramble:
	rm -rf *o $(EXECUTABLE_2)
