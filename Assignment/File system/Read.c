#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd1;
	char * msg = "/tmp/msg";
	struct stat buf;
	mkfifo(msg, 0666);

	char str1[80], str2[80];
		fd1 = open(msg,O_RDONLY | O_CREAT);
		read(fd1, str1, 80);
        int l =  lstat(str1, &buf); 
		close(fd1);
		fd1 = open(msg,O_WRONLY | O_CREAT);
		write(fd1, str2, strlen(str2)+1);
		close(fd1);

	return 0;
}
