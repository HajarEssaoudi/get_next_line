#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line1;
	char *line2;
	int fd, fd1;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("test.txt", O_RDONLY);
	line1 = get_next_line(fd);
	line2 = get_next_line(fd1);
	while (line1 != NULL || line2 != NULL)
	{
		if (line1)
		{
			printf("%s", line1);
			free(line1);
			line1 = get_next_line(fd);
		}
		if (line2)
		{
			printf("%s", line2);
			free(line2);
			line2 = get_next_line(fd1);
		}
	}
	close(fd);
	close(fd1);
	return (0);
}