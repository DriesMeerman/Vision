#include <stdio.h>
#include "fileUtil.h"

void readFirstBytesFromFile(char* path, int byteCount, unsigned int result[]){

    FILE *fp;
    fp = fopen(path, "rb"); // read mode

    if (fp == NULL)
    {
        return;// NULL;
    }

    unsigned char ch;
    unsigned long fileLen;
    unsigned long counter;

    fseek(fp, 0, SEEK_END);
    fileLen = ftell(fp);      // get the exact size of the pic
    fseek(fp, 0, SEEK_SET);

    if (byteCount > fileLen){
        byteCount = fileLen;
    }

    unsigned int buffer[byteCount];
    
    for (counter = 0; counter < byteCount; counter++) {
        ch = fgetc(fp);
        result[counter] = ch;
    }

    fclose(fp);
}

void readBytes(char* path, char buffer[], int start, int end){
    FILE *fp;
    fp = fopen(path, "rb"); // read mode

    if (fp == NULL)
    {
        return;// NULL;
    }

    unsigned char ch;
    unsigned long fileLen;
    unsigned long counter;
    
    long byteCount = end - start;

    fseek(fp, 0, SEEK_END);
    fileLen = ftell(fp);      // get the exact size of the pic
    fseek(fp, 0, SEEK_SET);

    if (byteCount > fileLen){
        byteCount = fileLen - byteCount;
    }
    if (byteCount < 0) return;

    //unsigned int buffer[byteCount];
    
    fseek(fp, start, SEEK_SET);

    for (counter = 0; counter < byteCount; counter++) {
        ch = fgetc(fp);
        buffer[counter] = ch;
    }

    fclose(fp);
}