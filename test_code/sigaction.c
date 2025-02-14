#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signum) {
  printf("Received signal %d\n", signum);
}

int main(void) {
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGINT, &action, NULL);

    while (1) {
        // Do some work
    }
    return 0;
}

