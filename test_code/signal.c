#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signum) {
    printf("Received SIGINT NUMBER %d\n", signum);
    exit(0);
}

int main() {
    // Set the signal handler for the SIGINT and SIGTERM signals
    // to the signal_handler function
    /*
        SIGINT (INTERRUPT) is the interrupt signal and is raised when you press Ctrl+C.
        SIGTERM (TERMINATION) signal is generated when the program is terminated by the operating system.
            --> kill -TERM PID_Of_Main_Programm || kill -TERM 5154
    */
    
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    while (1) {
        // Do some work here...
    }

    return 0;
}

