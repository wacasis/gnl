#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 108

int	main(int fd)
{
	char buffer[BUFFER_SIZE];
	size_t count;
	fd = open("file.txt", O_RDONLY);

	while (count < read(fd, buffer, BUFFER_SIZE - 1))
		buffer[count++];
	printf("Data read from file: \n\%s \n", buffer);
	printf("Elements read:%i\n", count);
	printf("jsp : %s", read(fd, buffer, BUFFER_SIZE - 1));
	return (count);
}