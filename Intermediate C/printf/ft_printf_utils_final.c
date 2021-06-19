#include "ft_printf.h"

int				ft_check(char const *x, char y)
{
	int i;
	int len;

	len = (int)ft_strlen(x);
	i = 0;
	while (i < len)
	{
		if (x[i] == y)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		length;
	char		*d;

	i = 0;
	length = ft_strlen(s + start);
	if (len < length)
		length = len;
	d = malloc(length + 1);
	while (i < length)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}

char			*assignkeys(void)
{
	char *keys;

	if (!(keys = malloc(10 * sizeof(char))))
		return (0);
	ft_memmove(keys, "cspduixX%", 9);
	keys[9] = '\0';
	return (keys);
}

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char			*ft_strdup(const char *s1)
{
	char	*start;
	int		i;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	if (!(start = malloc(len + 1)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		start[i] = s1[i];
		i++;
	}
	start[i] = 0;
	return (start);
}
