/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:32:11 by root              #+#    #+#             */
/*   Updated: 2024/11/30 11:32:35 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	if (!str)
        return (0);
	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
        return (NULL);
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = start;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[j] && j < start + len)
	{
		p[i] = s[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	p = (char *)malloc(i + j + 1);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s)
{
	char	*ss;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	 if (!s)
        return (NULL); 
	while (s[len])
		len++;
	ss = (char *)malloc(len + 1);
	if (!ss)
		return (NULL);
	while (i < len)
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
