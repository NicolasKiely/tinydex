#include <stdlib.h>
#include <string.h>

#include "io.h"


int *IOcontext_lookupArgFlags(int argc, char* argv[]){
    int i;
    int *pFlags = malloc(255 * sizeof(int));
    if (pFlags == NULL){
        fprintf(stderr, "Error, could not allocate memory for flags\n");
        return NULL;
    }
    memset(pFlags, -1, 255 * sizeof(int));

    /* Loop over all arguments */
    for (i=0; i<argc; i++){
        /* Check if flag */
        if (argv[i][0] != '-'){ continue; }

        /* Set flag character's position */
        pFlags[ (int) argv[i][1] ] = i;
    }
    
    return pFlags;
}


FILE *IOcontext_lookupFile(
    int *pFlags, const char *type, const char *mode,
    FILE *def, int argc, char *argv[]
){
    int i;
    FILE *file = def;
    if (pFlags==NULL || type==NULL || mode==NULL){ return NULL; }

    i = pFlags[ (int) type[0] ];

    if (i > -1){
        if (i+1 >= argc || argv[i+1][0] == '-'){
            fprintf(stderr, "Error, %s file not specified\n", type);
            return NULL;
        }

        file = fopen(argv[i+1], mode);
        if (file == NULL){
            fprintf(stderr,
                "Error, could not open %s file '%s'\n", type, argv[i+1]
            );
            return NULL;
        }
    }

    return file;
}


struct IOcontext *IOcontext_create(int argc, char* argv[]){
    /* Initialize io context */
    struct IOcontext *ioc = malloc(sizeof(struct IOcontext));
    if (ioc == NULL){
        fprintf(stderr, "Error, could not allocate memory for io\n");
        return NULL;
    }
    memset(ioc, 0, sizeof(struct IOcontext));

    /* Get arg flag lookup */
    ioc->pFlags = IOcontext_lookupArgFlags(argc, argv);
    if (ioc->pFlags == NULL){
        IOcontext_free(&ioc);
        return NULL;
    }
    
    /* Open files, default to stdin/stdout */
    ioc->input  = IOcontext_lookupFile(
        ioc->pFlags, "input", "r", stdin, argc, argv
    );
    ioc->output = IOcontext_lookupFile(
        ioc->pFlags, "output", "w", stdout, argc, argv
    );

    if (ioc->input==NULL || ioc->output==NULL){
        IOcontext_free(&ioc);
        return NULL;
    }

    return ioc;
}



void IOcontext_free(struct IOcontext **pIoc){
    struct IOcontext *ioc;
    if (pIoc == NULL){ return; }
    ioc = *pIoc;
    if (ioc == NULL){ return; }

    /* Close any files */
    if (ioc->input != NULL && ioc->input != stdin){
        fclose(ioc->input);
    }

    if (ioc->output != NULL && ioc->output != stdout){
        fclose(ioc->output);
    }

    /* Clean up allocated flag buffer */
    if (ioc->pFlags != NULL){
        free(ioc->pFlags);
    }

    free(ioc);
    *pIoc = NULL;
}


void readInput(){
}
