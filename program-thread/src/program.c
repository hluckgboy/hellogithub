/**
 * @file program.c
 * @brief program program
 */
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("Hello, World!\n");

  int result = fork();
  if (result < 0) {
    printf("Fork failed.\n");
  } else if (result == 0) {
    printf("Child process\n");
  } else {
    if (wait(NULL) < 0) {
      perror("Wait failed");
    }
    printf("Child process finished\n");
  }
  return 0;
}