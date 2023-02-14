#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
  printf("Hello 2250\n");
  int fd = open("output.txt",
  O_CREAT|O_WRONLY|O_TRUNC,
  S_IRUSR|S_IWUSR);
  dup2(fd, 1); // duplicate the file descriptor
  printf("%d", fd);
  close(fd); // close the unused file descriptor
  printf("Hello 2250 again\n");
}