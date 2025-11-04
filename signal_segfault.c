/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
 */


#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handle_segfaultSignal(){
    printf("A segmentation fault occured - probably a pointer being referenced to null, then dereferenced so its just null\n");
}

int main (int argc, char* argv[]) {
    signal(SIGSEGV, handle_segfaultSignal); //pass it to the helper method

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}