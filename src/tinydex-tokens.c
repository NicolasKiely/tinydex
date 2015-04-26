/**
 * Takes in list of entries, and tries to find common motifs
 */
#include <stdio.h>
#include <stdlib.h>

#include "io.h"



int main(int argc, char *argv[]){
    struct IOcontext *ioc = IOcontext_create(argc, argv);
    if (ioc == NULL){ exit(EXIT_FAILURE); }


    IOcontext_free(&ioc);
    return EXIT_SUCCESS;
}
