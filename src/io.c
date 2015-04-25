#include <stdlib.h>

#include "io.h"


int argFlagSet(int argc, char* argv[], int i, char flag){
    /* Check bounds */
    if (i < 0 || i >= argc) { return 0; }

    /* Check if flag. Notice 1-length strings also return 0 here */
    if (argv[i][0] != '-') { return 0; }

    /* Return comparison */
    return argv[i][1] == flag;
}


FILE *getInputStream(int argc, char* argv[]){
    int i;
    FILE *inputStream = stdin;

    for (i=1; i<argc; i++){
        if (argFlagSet(argc, argv, i-1, 'i')){
            inputStream = fopen(argv[i], "r");
            if (inputStream == NULL){
                fprintf(stderr,
                    "Error, could not open %s for input\n", argv[i]
                );
            }
            break;
        }
    }

    return inputStream;
}


FILE *getOutputStream(int argc, char* argv[]){
    int i;
    FILE *outputStream = stdout;

    for (i=1; i<argc; i++){
        if (argFlagSet(argc, argv, i-1, 'o')){
            outputStream = fopen(argv[i], "w");
            if (outputStream == NULL){
                fprintf(stderr,
                    "Error, could not open %s for output\n", argv[i]
                );
            }
            break;
        }
    }

    return outputStream;
}


void cleanupIO(FILE *input, FILE *output){
    if (input != NULL && input != stdin){
        fclose(input);
    }

    if (output != NULL && output != stdout && output != stderr){
        fclose(output);
    }
}


void readInput(){
}
