#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Hello World\n");
for(int i =1; i < argc; i++)
{
int pid = fork();
  if (pid > 0) {
    // Parent
    printf("Parent => My ID is %d\n", getpid());
    printf("Parent => Child is created with ID %d\n", pid);

    int child_pid = wait(NULL);
    printf("Parent => Child process with ID %d is terminated\n", child_pid);
  }
  else if (pid == 0) {
    // Child process
    // Load a program
    printf("Child => Child is created with ID %d\n", getpid());
    // execlp("/bin/date", "date", NULL);
    //execlp("/bin/ls", "ls", "-la", NULL);

    execlp("/usr/bin/wget", "wget", argv[i] , NULL);
    exit(0);
  }
}
  
  return 0;
}