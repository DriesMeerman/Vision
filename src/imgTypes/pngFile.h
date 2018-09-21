#ifndef FUNCTIONS_PNG_H_INCLUDED
#define FUNCTIONS_PNG_H_INCLUDED

typedef struct pngObject {
    char* path;
    int width, height, size;
} pngObject;

int isFilePng(char* path);
int getWidth(char* path);
void getIhdrBytes(char* path, char buffer[]);
int getHeight(char* path);
int getPixelCount(char* path);

int processPng(char* filePath);

pngObject createPngObject(char* path);

#endif