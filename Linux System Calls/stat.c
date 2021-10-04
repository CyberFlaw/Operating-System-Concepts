#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
  struct stat buf;
  stat("myfile.txt", &buf);
  printf("st_mode = %o\n", buf.st_mode);
}
