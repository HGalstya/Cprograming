#include "ft_printf.h"

unsigned long	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strcpy(char *dest, char *src)
{
	char	*start;
	int		i;
	int		len;

	len = ft_strlen(dest);
	i = 0;
	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	start[i] = '\0';
	return (start);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

int				ft_atoi(const char *str)
{
	int sign;
	int result;
	int i;

	i = -1;
	sign = 1;
	result = 0;
	while (str[++i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		;
	if (str[i] == '-' && ++i)
		sign *= -1;
	if (str[i] == '+' && str[i - 1] != '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i++] - '0');
		else
			return (result * sign);
	}
	return (result * sign);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (0);
	if (s1)
		s1_len = ft_strlen((char *)s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_strlen((char *)s2);
	else
		s2_len = 0;
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	free((char *)s1);
	return (rtn);
}
