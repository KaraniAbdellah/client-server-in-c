#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Entering pause...\n");
    pause();
    printf("Exiting pause.\n");
    return 0;
}
