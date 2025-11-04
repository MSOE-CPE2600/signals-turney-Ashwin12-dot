#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_alarm(int sig){
    printf("Signal received - ALARM - no time left.\n");
}


int main(){
    signal(SIGALRM, handle_alarm); //refer to handle alarm
    alarm(5); //set an alarm for 5 seconds
    
    printf("Alarm set for 5 seconds\n");
    pause();

    printf("Done waiting\n");
    return 0;

}