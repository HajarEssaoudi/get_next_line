#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = start;
	// if (!s || start > ft_strlen(s))
	// 	return (ft_strdup(""));
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

int	main(void)
{
	char *p;
	int fd;
	// fd = open("text.txt", O_RDONLY);
	p = ft_substr("hello", 0 , 2);
	printf("%s",p);
	return (0);
}