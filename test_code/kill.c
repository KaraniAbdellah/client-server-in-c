#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();  // get the process ID of the current process
  int result = kill(pid, SIGKILL);  // send the SIGKILL signal to the process
  if (result == 0) {
    printf("Process terminated successfully.\n");
  } else {
    perror("Error terminating process");
  }
  return 0;
}