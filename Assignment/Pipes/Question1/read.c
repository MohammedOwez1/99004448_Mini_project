
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *strrev(char *str);

int main()
{
	int fd1;
	char * msg = "/tmp/msg";
	mkfifo(msg, 0666);

	char str1[80];
	while (1)
	{
		fd1 = open(msg,O_RDONLY | O_CREAT);
		read(fd1, str1, 80);
		strrev(str1);
		printf("msg reversed and send\n");
		close(fd1);
		fd1 = open(msg,O_WRONLY | O_CREAT);
		write(fd1, str1, strlen(str1)+1);
		close(fd1);
	}
	return 0;
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
