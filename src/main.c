#include <stdio.h>
#include <stdlib.h>
#include "util/fileUtil.h"
#include "util/util.h"
#include "imgTypes/jpegFile.h"
#include "imgTypes/pngFile.h"
#include "fileProcessor/fileProcessor.h"

enum Action {
    unknown,
    file,
    dir,
    help
} action;

enum Action getAction(char* actionString);
void actionHandler(enum Action action, char const *argv[]);

int printSize = 0;


int main(int argc, char const *argv[]) {
  
    printf("Start.\n");

    argumentHandler(argc, argv);
    return 1;

    int bitCount = 10;

    argumentHandler(argc, argv);

    // const char* reset = "\u001b[0m";
    // const char* green = "\u001b[32m";
    // const char* red = "\u001b[31m";
//     #define KNRM  "\x1B[0m"
// #define KRED  "\x1B[31m"
// #define KGRN  "\x1B[32m"
// #define KYEL  "\x1B[33m"
// #define KBLU  "\x1B[34m"
// #define KMAG  "\x1B[35m"
// #define KCYN  "\x1B[36m"
// #define KWHT  "\x1B[37m"

    char* filePath = "./asset/bitterbal.jpg";
    if (argc > 1){
        filePath = argv[1];
    }
    if (argc > 2){
        bitCount = atoi(argv[2]);
    }

    enum fileType type = checkFileType(filePath);
    printf("Found type: %s", fileTypeToString(type));

/*
    const char* isJpg = "False";
    if (isFileJPG(filePath)){
        isJpg = "True";
    }

    const char* isPng = "False";
    if (isFilePng(filePath)){
        isPng = "True";
    }

    


    printf ("Is image %s a JPG %s\n", filePath, isJpg);
    printf ("Is image %s a PNG %s\n", filePath, isPng);

    struct pngObject png = createPngObject(filePath); 
    printf("\n png width: %d ", png.width);
    printf("\n png heigth: %d ", png.height);
    char buf[50];
    readBytes(filePath, buf, 11, 11+13);
    printf("\nloop\n");

    for (int i=0; i < 13; i++){
        printf("%X ", buf[i]);
    }
    printf("\n");
    */


    //fileString(filePath);
    /*unsigned int  buffer[bitCount];

    readFirstBytesFromFile(filePath, bitCount, buffer);

    int index;
    char blaat[bitCount];
    for (index = 0; index < bitCount; index++) {
        printf("%X ", buffer[index]);
        blaat[index] = buffer[index];
    }

    char result[10];
    memcpy(result, blaat, 10);

    printf("\nResult: %s", result);*/

    printf("\n\nFinished.\n");

    return 0;
}


int argumentHandler(int argc, char const *argv[]){

    if(validateArguments(argc, argv) == 0) {
        printf("\nInvalid arguments.\n");
        return 0;
    }

    printf("\nArguments: ");
    for (int i = 0; i < argc; ++i) {
        printf("\"%s\" ",argv[i]);
    }

    actionHandler(getAction(argv[1]), argv);

    printf("\n\n");

    return 1;
};

enum Action getAction(char* actionString){

    printf("\nget action %s\n", actionString);

    //todo https://www.techonthenet.com/c_language/standard_library_functions/string_h/strcmp.php
    if (strcmp(actionString, "file") == 0)
        return file;

    if (strcmp(actionString, "dir") == 0 || strcmp(actionString, "folder") == 0)
        return dir;

    if (strcmp(actionString, "help") == 0)
        return help;

    return unknown;
}



int validateArguments(int argc, char const *argv[]){
    return 1;
}

void fileAction(char* filePath){
    processFile(filePath);
}

void dirAction(char* dirPath){
    processDirectory(dirPath);
}

void helpAction(){
    printf("\n------------------------\n");
    printf("\tHELP");
    printf("\n------------------------\n");
    printf("Available actions:\n");
    printf("file\t\t ${filepath}\n");
    printf("dir / folder\t ${folderpath}\n");
    printf("help\t\t print help\n");
    // printf("\nAvailable flags\n");
}

void actionHandler(enum Action action, char const *argv[]){
    switch(action){
        case help:
            helpAction();
            break;
        case file:
            fileAction(argv[2]);
            break;
        case dir:
            processDirectory(argv[2]);
            break;
        default:
            printf("\nAction %d not yet supported\n", action);
    }
};
