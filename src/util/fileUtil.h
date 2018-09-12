#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/**
 * This function takes a path and an amount of bytes it should read from the start of that file. 
 * The final argument should be an array that will be filled with the bytes that have been read.
 **/
void readFirstBytesFromFile(char* path, int byteCount, unsigned int result[]);
void readBytes(char* path, char buffer[], int start, int end);

#endif