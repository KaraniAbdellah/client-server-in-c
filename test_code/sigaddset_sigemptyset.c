#include <signal.h>
#include <asm-generic/signal.h>

int main(void) {
    sigset_t signal_set;

    // Initialize an empty signal set
    sigemptyset(&signal_set);

    // Add SIGINT to the signal set
    sigaddset(&signal_set, SIGINT);

}



