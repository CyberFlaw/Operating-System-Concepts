#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{	
	int fd1, fd2;
	char buff[50];
	
	fd1 = open("readfile.txt", O_RDONLY);
	if(fd1 != -1){
	  printf("\nreadfile.txt opened with read only access\n");
	  lseek(fd1, 0, SEEK_SET);
	  read(fd1, buff, sizeof("readfile.txt"));
	  printf("\n%s was readed from the file\n", buff);
	  close(fd1);
	}
	
	fd2 = open("writefile.txt", O_WRONLY);
	if(fd1 != -1){
	  printf("\nwritefile.txt opened with write only access\n");
	  write(fd2, buff , sizeof(buff));
	  printf("\n%s was written to the file\n", buff);
	  close(fd2);
	}

}
