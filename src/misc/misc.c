void fileString(char* filePath){
    FILE *fp;
    fp = fopen(filePath, "rb"); // read mode

    if (fp == NULL)
    {
        printf("Error while opening the file.\n");
        exit(1);
    }

    printf("The contents of %s file are:\n", filePath);
    printf("pre while\n");
    unsigned char ch;
    unsigned long fileLen;

    //fseek(fp, 0, SEEK_END);
    //fileLen = ftell(fp);      // get the exact size of the pic
    fileLen = 3;  //read first 140 bytes of file
    //fseek(fp, 0, SEEK_SET);

    printf("Image size = %o bytes - %o kb \n", fileLen, fileLen / 1024) ;
    // while ((ch = fgetc(fp)) != EOF) {
    //     printf("%c", ch);
    // }

    unsigned long counter;
    for (counter = 0; counter < fileLen; ++counter) {
        ch = fgetc(fp);
        printf("%X ", ch);
        printf("%u\t", ch);
        printf("%o\t", ch);
    }

    printf("\n\npost loop\n");
        

    fclose(fp);
    

    // fp = fopen(filePath, "r");
    // fprintf(fp, "This is testing for fprintf...\n");
    // fputs("This is testing for fputs...\n", fp);
    // fclose(fp);
    // return "_";
}