#include <stdio.h>
#include <stdlib.h>
#include "util/fileUtil.h"
#include "imgTypes/jpegFile.h"
#include "imgTypes/pngFile.h"

int main(int argc, char const *argv[]) {
  
    printf("Start.\n");

    int bitCount = 10;

    for (int i = 0; i < argc; ++i) {
        printf("Argument: %s\n",argv[i]);
    }

    // const char* reset = "\u001b[0m";
    // const char* green = "\u001b[32m";
    // const char* red = "\u001b[31m";

    char* filePath = "./asset/bitterbal.jpg";
    if (argc > 1){
        filePath = argv[1];
    }
    if (argc > 2){
        bitCount = atoi(argv[2]);
    }

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

