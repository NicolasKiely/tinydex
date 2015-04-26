/**
 * Manager for processing I/O
 */
#ifndef IO_HEADER 
#define IO_HEADER

#include <stdio.h>

#include "record.h"


/* Combined Input/Output Streams, as well as flag map */
struct IOcontext {
    FILE *input;
    FILE *output;
    int *pFlags;
};

 
/**
 * Gets array of flag positions. I'th position in array corresponds to
 * ascii value i. Value at position is last position flag appears
 * in argv[], or -1 if not present.
 * - argc: Argument count passed to main()
 * - argv: Arg set passed to main()
 * Return newly allocated int array
 * Side effects: None
 */
int *IOcontext_lookupArgFlags(int argc, char* argv[]);


/**
 * Gets file stream based on defaults or program args
 * - pFlags: Flag map build by _lookupArgFlags
 * - type: Either "input" or "output". Case sensitive!
 * - mode: File mode string (eg "r")
 * - def: Default file (stdin or stdout)
 * - argc: main()'s argc arg count
 * - argv: main()'s argv arg list 
 * Returns File pointer if successful, null if not
 * Side effects: May open files for read/write
 */
FILE *IOcontext_lookupFile(
    int *pFlags, const char *type, const char *mode,
    FILE *def, int argc, char *argv[]
);


/**
 * Gets default or specified input and output sources
 * - argc: Argument count passed to main()
 * - argv: Argument set passed to main()
 * Returns IO context
 * Side effects: None
 */
struct IOcontext *IOcontext_create(int argc, char* argv[]);


/**
 * Cleans up input/output context
 * - pioc: Reference to context pointer
 * Returns void
 * Side effects: Frees allocated memory, reassigns context to null,
 *   and closes any files opened
 */
void IOcontext_free(struct IOcontext **pioc);


/* Reads from standard input and returns entries object */
void readInput();

#endif
