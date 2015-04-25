/**
 * Manager for processing I/O
 */
#ifndef IO_HEADER 
#define IO_HEADER

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
int arg_flag_set(int argc, char* argv[], int i, char flag);


/* Reads from standard input and returns entries object */
void read_input();

#endif
