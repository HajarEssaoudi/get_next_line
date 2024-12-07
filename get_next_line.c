/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:33:46 by root              #+#    #+#             */
/*   Updated: 2024/12/07 14:17:35 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_remainder(int fd, char *remainder)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		if (!temp)
			return (NULL);
		free(remainder);
		remainder = temp;
	}
	free(buffer);
	return (remainder);
}

void	free_remainder(char **remainder)
{
	free(*remainder);
	*remainder = NULL;
}

char	*extract_line(char **remainder)
{
	char	*line;
	char	*newline;
	char	*temp;

	if (!remainder || !*remainder)
		return (NULL);
	newline = ft_strchr(*remainder, '\n');
	if (newline)
	{
		line = ft_substr(*remainder, 0, newline - *remainder + 1);
		temp = ft_strdup(newline + 1);
		if (!line || !temp)
		{
			free_remainder(remainder);
			return (NULL);
		}
		free_remainder(remainder);
		*remainder = temp;
	}
	else
	{
		line = ft_strdup(*remainder);
		free_remainder(remainder);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_to_remainder(fd, remainder);
	if (!remainder || !*remainder)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = extract_line(&remainder);
	return (line);
}
