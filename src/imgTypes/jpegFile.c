#include "jpegFile.h"
#include "../util/fileUtil.h"

/**
 * JPEG files are indicated with the following values as first 3 bytes:
 * 255 216 255
 * FF  D8  FF
 **/
int isFileJPG(char* path) {

    unsigned int buffer[3];
    readFirstBytesFromFile(path, 3, buffer);

    if (buffer[0] == 0xFF && 
        buffer[1] == 0xD8 && 
        buffer[2] == 0xFF){

        return 1;
    }

    return 0;
};
