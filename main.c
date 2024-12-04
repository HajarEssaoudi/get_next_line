#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd;
	int line_count = 0;
	int i = 1;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	line_count++;
	// 	printf("Line %d: %s", line_count, line);
	// 	free(line);
	// }
	while (i > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		
		line_count++;
		printf("Line %d: %s", line_count, line);
		free(line);
		i--;
	}

	close(fd);
	printf("Total lines read: %d\n", line_count);
	return (0);
}