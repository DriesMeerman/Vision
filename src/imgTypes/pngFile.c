#include "pngFile.h"
#include "../util/fileUtil.h"
#include "../util/util.h"

/**
 * PNG files are indicated with the following values as first 8 bytes:
 * 89 50 4E 47 0D 0A 1A 0A
 * Followed by a 4 byte size of the IHDR chunk, which starts at byte 12.
 **/
int isFilePng(char* path) {

    unsigned int buffer[8];
    readFirstBytesFromFile(path, 8, buffer);

    if (buffer[0] == 0x89 && 
        buffer[1] == 0x50 && 
        buffer[2] == 0x4E &&
        buffer[3] == 0x47 &&
        buffer[4] == 0x0D &&
        buffer[5] == 0x0A &&
        buffer[6] == 0x1A &&
        buffer[7] == 0x0A ){

        return 1;
    }

    return 0;
};

int getWidth(char* path){
    char buffer[20];
    getIhdrBytes(path, buffer);
    char widthBuffer[4];
    memcpy(widthBuffer, &buffer[4], 4);

    /**
     * for little endian machine first reverse the widthbuffer so it reads it as correct int
     * https://stackoverflow.com/questions/8173037/convert-4-bytes-char-to-int32-in-c
     **/
    reverseArray(widthBuffer, sizeof(widthBuffer));

    unsigned int width = * (int *) widthBuffer;
    return width;
}

int getHeight(char* path){
    char buffer[20];
    getIhdrBytes(path, buffer);
    char widthBuffer[4];
    memcpy(widthBuffer, &buffer[8], 4);

    /**
     * for little endian machine first reverse the widthbuffer so it reads it as correct int
     * https://stackoverflow.com/questions/8173037/convert-4-bytes-char-to-int32-in-c
     **/
    reverseArray(widthBuffer, sizeof(widthBuffer));

    unsigned int width = * (int *) widthBuffer;
    return width;
}

/**
 * The IHDR chunk must appear FIRST ( byte 12 ). It contains:

   Width:              4 bytes
   Height:             4 bytes
   Bit depth:          1 byte
   Color type:         1 byte
   Compression method: 1 byte
   Filter method:      1 byte
   Interlace method:   1 byte 
   Other stuff.
 */
void getIhdrBytes(char* path, char buffer[]){
    // char buffer[13];
    readBytes(path, buffer, 12, 12+13); //this is ass backwards fix it.
}

pngObject createPngObject(char* path){
    if (isFilePng(path) > 0){
        int width = getWidth(path);
        int height = getHeight(path);
        struct pngObject png = {
            .path = path,
            .width = width,
            .height = height,
            .size = width * height
        };

        return png;
    }
    
    struct pngObject empty  = {
        .path = "",
        .width = 0,
        .height = 0,
        .size = 0
    };
    return empty;
}

int processPng(char* filePath){
    struct pngObject png = createPngObject(filePath);
    if (printSize == 1){
        printf("Width: %d\n", png.width);
        printf("Heigth: %d\n", png.height);
    }
}