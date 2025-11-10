/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */


//so we need to use random
 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <time.h>

 int main(int argc, char *argv[]){
    if(argc != 2){
        printf("usage: %s\n", argv[0]);
        return 1;
    }

    //we need a union - never used it b4, researched it and used it
    //sigqueue requires it
    pid_t pid = atoi(argv[1]); //get the PID 
    union sigval value; //we need this for sigqueue it will not work if we don't

    srand(time(NULL)); //generate a random time 
    value.sival_int = rand () % 100; //send a random value

    printf("sending sigusr1 to pid %d with value %d\n", pid, value.sival_int); 

    sigqueue(pid, SIGUSR1, value); //send the signal!!
    return 0;
 }


