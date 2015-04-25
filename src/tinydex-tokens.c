/**
 * Takes in list of entries, and tries to find common motifs
 */
#include <stdio.h>
#include <stdlib.h>

#include "io.h"



int main(int argc, char *argv[]){
    FILE *input = getInputStream(argc, argv);
    FILE *output = getOutputStream(argc, argv);
    if (input == NULL || output == NULL){ exit(EXIT_FAILURE); }

    cleanupIO(input, output);
    return 0;
}
