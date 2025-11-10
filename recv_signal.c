/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */


 #include <stdio.h>
 #include <signal.h>
 #include <unistd.h>


 void sigusr1_handler(int sig, siginfo_t *info, void *uncontext){
    //im going to do what i did last time for sigaction -> zero out data first and clear warnings

    //this does nothing, legit j uses the parameters so avoid warnings
    (void) sig; 
    (void) uncontext; 

    printf("\n Received SIGURS1 from process ID! ID is %d \n", info -> si_pid); //go to struct and receive process ID
    printf("\n Received value: %d\n", info -> si_value.sival_int); //get the value from the struct
    
 }

 int main(void) {
    //this part is basically sigaction -- im gonna copy my code from sigaction

     struct sigaction sa; 

    //Zero out struct and setup the handler i made
    sa.sa_sigaction = sigusr1_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask); //clear data -- have to use empty to zero the mask

    //use sigaction for receiving signals

    //do this when this signal arrives -- what sigaction does
    sigaction(SIGUSR1, &sa, NULL);

    printf("PID from receiver: %d\n", getpid());
    printf("Waiting for signal . . . \n");

    while (1){
        pause(); //when u get signal
    }

 }