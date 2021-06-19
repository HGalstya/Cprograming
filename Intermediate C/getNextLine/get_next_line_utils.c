#include "get_next_line.h"

unsigned long		ft_strlen_second(const char *s)
{
	unsigned long i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char				*ft_strjoin_second(char *memory, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	if (!(join = malloc(sizeof(char) *
					(ft_strlen_second(memory) + ft_strlen_second(buffer) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (memory)
		while (memory[i] != '\0')
			join[j++] = memory[i++];
	i = 0;
	if (buffer)
		while (buffer[i] != '\0')
			join[j++] = buffer[i++];
	join[j] = '\0';
	free(memory);
	return (join);
}

int					ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
