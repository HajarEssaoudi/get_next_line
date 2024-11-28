// C program to illustrate
// read system Call
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	char *p;
	int fd;
	fd = open("text.txt", O_RDONLY);
	p = get_next_line(fd);
	printf("%s",p);
	return (0);
}
