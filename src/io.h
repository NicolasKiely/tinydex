/**
 * Manager for processing I/O
 */
#ifndef IO_HEADER 
#define IO_HEADER

#include <stdio.h>

#include "record.h"

 
/**
 * Checks if an arg position represents a flag
 * Safely checks for bounds
 * - argc: Argument count passed to main()
 * - argv: Arg set passed to main()
 * - i: Index of arg to check
 * - flag: Flag character to check
 * Return true if flag match, false otherwise
 * Side effects: None
 */
int argFlagSet(int argc, char* argv[], int i, char flag);


/**
 * Gets default or specified input source
 * - argc: Argument count passed to main()
 * - argv: Argument set passed to main()
 * Returns file descriptor
 * Side effects: None
 */
FILE *getInputStream(int argc, char* argv[]);


/**
 * Cleans up input/output streams
 * - input: Input stream. Closed if not stdin or null
 * - output: Output stream. Closed if not stdin or null
 * Returns void
 * Side effects: May close files
 */
void cleanupIO(FILE *input, FILE *output);


/* Reads from standard input and returns entries object */
void readInput();

#endif
