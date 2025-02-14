#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Sleeping for 3 seconds...\n");
    sleep(3); // The program waits 3 seconds
    printf("Done sleeping.\n");
    return 0;
}
