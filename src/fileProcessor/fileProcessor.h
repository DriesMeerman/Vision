#ifndef FILEPROCESSOR_H_INCLUDED
#define FILEPROCESSOR_H_INCLUDED

typedef enum fileType {
    UNKNOWN,
    PNG,
    JPG,
} fileType;

// typedef struct pngObject {
//     char* path;
//     int width, height, size;
// } pngObject;

int processFile(char* filePath);
int processDirectory(char* dirPath);

enum fileType checkFileType(char* path);

char* fileTypeToString(enum fileType type);

#endif