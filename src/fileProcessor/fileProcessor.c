#include <dirent.h>
#include "fileProcessor.h"
#include "../imgTypes/jpegFile.h"
#include "../imgTypes/pngFile.h"
#include "../imgTypes/gifFile.h"


enum fileType checkFileType(char* path){
    enum fileType type = UNKNOWN;

    if (isFileJPG(path))
        type = JPG;

    if (isFilePng(path))
        type = PNG;
    
    if (isFileGif(path))
        type = GIF;

    return type;
};

int processFile(char* filePath){
    // printf("File: \"%s\"\t", filePath);
    enum fileType type = checkFileType(filePath);
    printf("Type: \x1B[36m%s\x1B[0m\t Path: %s\n", fileTypeToString(type), filePath);

    switch (type) {
        case PNG:
            processPng(filePath);
    }
}

int processDirectory(char* dirPath){
    DIR *dir;
    struct dirent *ent;
    
    char* filePath;
    filePath = (char*) malloc(sizeof(char) * 1024);

    if (dir = opendir (dirPath)) {
    /* print all the files and directories within directory */
    while (ent = readdir (dir)) {
        char* fileName = ent->d_name;
        //printf ("%s\t%s\n", fileName, ent->d_type);
        if (strcmp(fileName, ".") != 0 && strcmp(fileName, "..") != 0){
            //printf("\ncurrent filename: %s\n", fileName);
            strcat(filePath, dirPath);
            strcat(filePath, fileName);
            // printf("dirpath \"%s\"", dirPath);
            // printf("\tfilename \"%s\"", fileName);
            // printf("\tfilePath \"%s\"\n\n", filePath);

            processFile(filePath);;
            *filePath = 0;
            
        }
    }
    free(filePath);
    
    closedir (dir);
    } else {
    /* could not open directory */
    perror ("");
    return 0;
    }
}

char* fileTypeToString(enum fileType type){
    switch (type){
        case UNKNOWN:
            return "UNKNOWN";
        case JPG:
            return "JPG";
        case PNG:
            return "PNG";
        case GIF:
            return "GIF";
        default:
            return "UNKNOWN";
    }
    return "type not found";
}