default: build

OBJECTS = ./o/main.o ./o/jpegFile.o ./o/fileUtil.o ./o/util.o ./o/pngFile.o ./o/fileProcessor.o
COMPILER_FLAGS = -Wall
# OBJECTS = ./o/main.o ./o/fileUtil.o

build: phase1
	gcc ${COMPILER_FLAGS} ${OBJECTS} -o ./exe

phase1:
	mkdir -p o
	gcc -c ./src/main.c -o ./o/main.o
	gcc -c ./src/util/fileUtil.c -o ./o/fileUtil.o
	gcc -c ./src/util/util.c -o ./o/util.o
	gcc -c ./src/imgTypes/jpegFile.c -o ./o/jpegFile.o
	gcc -c ./src/imgTypes/pngFile.c -o ./o/pngFile.o
	gcc -c ./src/fileProcessor/fileProcessor.c -o ./o/fileProcessor.o
	
	

clean:
	rm -rf ./o
	rm -f exe

# ///////////////////////////////////////////////////////////////////////////////

# output: main.o
# 	gcc main.o -o output

# main.o: main.c
# 	gcc -c main.c

# clean:
# 	rm *.o

# HEADERS = util/fileUtil.h imgTypes/jpegFile.h
# OBJECTS = ./o/fileUtil.o ./o/jpegFile.o
# FILES = ./main.c ./util/fileUtil.c ./imgTypes/jpegFile.c

# generate: object
# 	gcc -WALL ${OBJECTS} -c ./exe

# object: 
# 	mkdir -p o
# 	gcc -c ${FILES} $< -o $@

# ///////////////////////////////////////////////////////////////////////////////

# TARGET = main
# LIBS = -lm
# CC = gcc
# CFLAGS = -g -Wall

# .PHONY: default all clean

# default: $(TARGET)
# all: default

# OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
# HEADERS = $(wildcard *.h)

# %.o: %.c $(HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# .PRECIOUS: $(TARGET) $(OBJECTS)

# $(TARGET): $(OBJECTS)
# 	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

# clean:
# 	-rm -f *.o
# 	-rm -f $(TARGET)