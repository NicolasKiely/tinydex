#include "io.h"

int arg_flag_set(int argc, char* argv[], int i, char flag){
    /* Check bounds */
    if (i < 0 || i >= argc) { return 0; }

    /* Check if flag. Notice 1-length strings also return 0 here */
    if (argv[i][0] != '-') { return 0; }

    /* Return comparison */
    return argv[i][1] == flag;
}


void read_input(){
}
