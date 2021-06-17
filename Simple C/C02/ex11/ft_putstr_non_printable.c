#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_hex(char c)
{
	if (c < 10)
		return (c + '0');
	return ('a' + (c - 10));
}

void	ft_print_hex(unsigned char c)
{
	unsigned char digit;

	digit = (unsigned)c;
	ft_putchar('\\');
	ft_putchar(ft_hex(digit / 16));
	ft_putchar(ft_hex(digit % 16));
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			ft_print_hex(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
