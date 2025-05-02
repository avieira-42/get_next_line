#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
	ssize_t	bytes_read;
	char	buf[10];

	fd = open(argv[1], O_RDONLY);
	bytes_read = read(fd, buf, 10);
	len = strlen(buf);
	printf("%s %i\n", buf, len);
}
