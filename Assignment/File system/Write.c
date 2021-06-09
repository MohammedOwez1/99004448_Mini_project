#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;

	char * msg = "/tmp/msg";
	mkfifo(msg, 0666);
	struct stat buf;

	char arr1[80]="test.txt", arr2[80];

		fd = open(msg, O_WRONLY| O_CREAT);
		write(fd, arr1, strlen(arr1)+1);
		close(fd);
		fd = open(msg, O_RDONLY|O_CREAT);
		read(fd, &buf, sizeof(buf));
		printf("file mode: %o\n", buf.st_mode);
		printf("file size: %ld\n", buf.st_size);
		printf("Uid: %o\n", buf.st_uid);

		close(fd);
	return 0;
}
