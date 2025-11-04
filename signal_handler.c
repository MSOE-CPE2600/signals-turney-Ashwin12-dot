/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */

 //I am going to use a counter for this, its going to be volatile because its constantly changing
 //use sig_atomic_t to actually exit the code safely 
volatile sig_atomic_t counter = 0;


void handle_signal() {
    printf("Received a signal\n");
    //exit(1);
    //increment counter instead
    counter++;
}



//------------------------------- part 4 

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
        if(counter == 1){
            printf("too many ints - killing program with command - SIGKILL");  //kill after 3 - not a requirement just do not want to abruptly stop
            kill(getpid(), SIGKILL); //get the process ID and send SIGKILL to it - stops program
        }
    }

    return 0;
}