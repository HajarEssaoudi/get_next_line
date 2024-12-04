/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:33:46 by root              #+#    #+#             */
/*   Updated: 2024/12/04 20:46:28 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_line(int fd)
{
	static char	*remainder = NULL;
	char		*buffer;
	ssize_t		bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!remainder || !ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		if (!temp)
		{
			free(buffer);
			free(remainder);
			remainder = NULL;
			return (NULL);
		}
		free(remainder);
		remainder = NULL;
		remainder = temp;
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;
	char		*newline;
	char		*temp;

	remainder = get_line(fd);
	if (!remainder || !*remainder)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	newline = ft_strchr(remainder, '\n');
	if (newline)
	{
		line = ft_substr(remainder, 0, newline - remainder + 1);
		temp = ft_strdup(newline + 1);
		if (!line || !temp)
		{
			free(line);
			free(temp);
			free(remainder);
			remainder = NULL;
			return (NULL);
		}
		free(remainder);
		remainder = NULL;
		remainder = temp;
	}
	else
	{
		line = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
	}
	return (line);
}

// return Number of bytes read on success
// return 0 on reaching the end of file
// return -1 on error
// return -1 on signal interrupt
// ft_strdup(line)