#include "ft_printf.h"

char			*getwidth(char *rtn, int width, char flag, int dot)
{
	char	*tmp;
	int		len;

	len = ft_strlen(rtn);
	if (width > len && !(tmp = ft_calloc(((width - len) + 1), 1)))
		return (0);
	else if (width <= len)
		return (rtn);
	if (flag == '0' && !dot && ft_memset(tmp, '0', width - len))
		tmp = ft_strjoin(tmp, rtn);
	else
	{
		tmp = ft_memset(tmp, ' ', width - len);
		if (flag == '-')
		{
			rtn = ft_strjoin(rtn, tmp);
			free(tmp);
			return (rtn);
		}
		tmp = ft_strjoin(tmp, rtn);
	}
	if (rtn[0] == '-' && flag == '0' && !dot)
		tmp = minus_zero(tmp, width, len);
	free(rtn);
	return (tmp);
}

int				useflags(t_flag flags, char *rtn, int len)
{
	int	checker;

	checker = 0;
	if (!rtn && flags.key == 's')
		rtn = ft_strdup("(null)");
	if (!rtn[0] && flags.key == 'c' && (checker = 1))
		rtn[0] = 'v';
	if (flags.precision >= 0 && flags.key != 'c')
		if (flags.precision > 0 || flags.dot)
			rtn = getprecision(rtn, flags.precision, flags.key);
	if (flags.dot && flags.precision == 0 &&
		(flags.key != 'c' || flags.key != 's'))
		ft_memset(rtn, '\0', ft_strlen(rtn));
	if (flags.width > 0)
		rtn = getwidth(rtn, flags.width, flags.flag, flags.dot);
	len = -1;
	while (rtn[++len])
	{
		if (rtn[len] == 'v' && checker)
			rtn[len] -= rtn[len];
		write(1, &rtn[len], 1);
	}
	free(rtn);
	return (len);
}

int				ft_propertext(const char *format, int j, va_list ar)
{
	char	*rtn;
	t_flag	flags;
	int		len;

	if (j == 1)
		write(1, format, 1);
	if (j == 1)
		return (1);
	if (j == 2)
	{
		flags.key = format[1];
		rtn = usekey(flags, ar);
		if (!rtn && flags.key == 's')
			rtn = ft_strdup("(null)");
		len = ft_strlen(rtn);
		if (!rtn[0] && flags.key == 'c')
			len = 1;
		write(1, rtn, len);
		free(rtn);
		return (len);
	}
	flags = giveflags((format + 1), j, ar);
	rtn = usekey(flags, ar);
	len = useflags(flags, rtn, j);
	return (len);
}

int				ft_print(const char *format, va_list ar, char *keys)
{
	int		i;
	int		j;
	int		handle;

	i = 0;
	handle = 0;
	while (format[i])
	{
		j = 1;
		if (format[i] == '%')
			while (!ft_check(keys, format[i + j++]))
				;
		handle += ft_propertext(format + i, j, ar);
		i += j;
	}
	return (handle);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	size;
	char	*keys;

	keys = assignkeys();
	va_start(ap, format);
	size = ft_print(format, ap, keys);
	free(keys);
	va_end(ap);
	return (size);
}
