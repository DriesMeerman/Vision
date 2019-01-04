#include "gifFile.h"
#include "../util/fileUtil.h"

/**
 * GIF files are indicated with the following values as first 3 bytes:
 * 47 49 46 
 * values for G I F in ascii
 **/
int isFileGif(char* path) {

    unsigned int buffer[3];
    readFirstBytesFromFile(path, 3, buffer);

    if (buffer[0] == 0x47 && 
        buffer[1] == 0x49 && 
        buffer[2] == 0x46){

        return 1;
    }

    return 0;
};
