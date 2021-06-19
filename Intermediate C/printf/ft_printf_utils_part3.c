#include "ft_printf.h"

int				getint(va_list ar, const char *format, int *i)
{
	int rtn;

	rtn = 0;
	if (format[*i] == '*')
	{
		rtn = va_arg(ar, int);
		(*i)++;
	}
	else if (ft_isdigit(format[*i]))
	{
		rtn = ft_atoi(format + *i);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	return (rtn);
}

t_flag			giveflags(const char *format, int i, va_list ar)
{
	t_flag	flags;

	i = 0;
	flags.dot = 0;
	if (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '0' && format[i + 1] == '-')
			flags.flag = '-';
		if (format[i] == '0' && format[i + 1] == '-')
			i += 2;
		else
			flags.flag = format[i++];
	}
	flags.width = getint(ar, format, &i);
	if (flags.width < 0)
		flags.flag = '-';
	if (flags.width < 0)
		flags.width *= -1;
	if (format[i] == '.')
		flags.dot = 1;
	if (format[i] == '.')
		i++;
	flags.precision = getint(ar, format, &i);
	flags.key = format[i];
	return (flags);
}

int				ft_dc(int n)
{
	int i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int				ft_dc_u(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int				ft_dc_hex(uintptr_t n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}
