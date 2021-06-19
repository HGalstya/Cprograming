#include "ft_printf.h"

char			*ft_getchar(char c)
{
	char *tool;

	if ((tool = malloc(2 * sizeof(char))) == 0)
		return (0);
	tool[0] = c;
	tool[1] = '\0';
	return (tool);
}

char			*usekey(t_flag flags, va_list ar)
{
	char *tool;

	if (flags.key == '%')
	{
		tool = malloc(2 * sizeof(char));
		tool[0] = '%';
		tool[1] = '\0';
		return (tool);
	}
	if (flags.key == 'd' || flags.key == 'i')
		return (ft_itoa(va_arg(ar, int)));
	if (flags.key == 'u')
		return (ft_itoa_u(va_arg(ar, unsigned int)));
	if (flags.key == 's')
		return (ft_strdup(va_arg(ar, char*)));
	if (flags.key == 'c')
		return (ft_getchar(va_arg(ar, int)));
	if (flags.key == 'x' || flags.key == 'X')
		return (ft_itoa_hex(va_arg(ar, unsigned int), flags.key));
	if (flags.key == 'p')
		return (ft_itoa_ptr(va_arg(ar, void*)));
	return (0);
}

char			*minus_zero(char *tmp, int precision, int len)
{
	tmp[0] = '-';
	tmp[precision - len] = '0';
	return (tmp);
}

char			*getprecision(char *rtn, int precision, char key)
{
	char	*tmp;
	int		len;

	len = ft_strlen(rtn);
	len = (rtn[0] == '-') ? len - 1 : len;
	if (key == 's')
		tmp = ft_substr(rtn, 0, precision);
	else if (key != 'c' && key != 'p')
	{
		if (precision > len)
		{
			if (!(tmp = malloc(precision + 1 + ft_strlen(rtn) - len)))
				return (0);
			ft_memset(tmp, '0', precision - len);
			ft_strcpy(&tmp[precision - len], rtn);
			if (rtn[0] == '-')
				tmp = minus_zero(tmp, precision, len);
		}
		else
			return (rtn);
	}
	else
		return (rtn);
	free(rtn);
	return (tmp);
}

void			*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = malloc(count * size);
	while (i < count * size)
		p[i++] = 0;
	return (p);
}
