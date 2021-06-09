#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{
	int fd;

	char * msg = "/tmp/msg";
	mkfifo(msg, 0666);

	char arr1[80], arr2[80];
	while (1)
	{
		fd = open(msg, O_WRONLY| O_CREAT);
		fgets(arr2, 80, stdin);
		write(fd, arr2, strlen(arr2)+1);
		close(fd);
		fd = open(msg, O_RDONLY|O_CREAT);
		read(fd, arr1, sizeof(arr1));
		printf("message received: %s\n", arr1);
		close(fd);
	}
	return 0;
}
