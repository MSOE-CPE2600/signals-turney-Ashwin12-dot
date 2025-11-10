/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signo, siginfo_t *info, void *context){
    (void)context; //warning clear
    printf("\nReceived Signal %d - sigusr \n", signo);
    if(info != NULL){
        printf("Sender pid is %d \n", info -> si_pid);
    }
}

int main(void){
    struct sigaction sa; 

    //Zero out struct and setup the handler i made
    sa.sa_sigaction = sigusr1_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask); //clear data -- have to use empty to zero the mask

    //handler for sigusr1
    if(sigaction(SIGUSR1, &sa, NULL) == -1){
        printf("sigaction error \n");
        return 1;
    }

    printf("PID = %d\n", getpid());
    printf("Waiting for signal . . . \n");

    while(1){
        pause();
    }
    return 0; 

}