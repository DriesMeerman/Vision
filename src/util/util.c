#include "util.h"

void reverseArray(char array[], unsigned int arrayLength){
    // unsigned int arrayLength = sizeof(array);
    // printf("\n\t reversing array of size %u\n", arrayLength);

    for (unsigned int i = 0; i < arrayLength; i++){
        char tmp = array[i];
        array[i] = array[--arrayLength];
        array[arrayLength] = tmp;
    }
}