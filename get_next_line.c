/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:33:46 by root              #+#    #+#             */
/*   Updated: 2024/11/27 13:33:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *str;
    int			bytes;
    char *line;
    if(!str)
        str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    bytes = read(fd, (str + ft_strlen(str)), BUFFER_SIZE);
    // return Number of bytes read on success
    // return 0 on reaching the end of file
    // return -1 on error
    // return -1 on signal interrupt
    if ()
}