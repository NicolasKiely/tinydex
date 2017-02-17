/**
 * Creates list of record offsets for seek(2)
 * Reads from stdin, writes to stdout
 * Usage:
 *   prog
 */

#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){
  int offset=0;
  int c;
  
  while ( (c = getchar()) != EOF ){
    if (c == '\n')
      printf("%d\n", offset);

    // Move to next byte
    offset++;
  }

  return EXIT_SUCCESS;
}
