#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

int				ft_base_checks(char *base)
{
	unsigned short index;
	unsigned short s_index;

	index = -1;
	if (base[0] == '\0' || ft_strlen(base) == 1)
		return (0);
	while (base[++index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		s_index = index + 1;
		while (base[s_index++] != '\0')
			if (base[index] == base[s_index])
				return (0);
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	long			number;
	unsigned int	size;

	if (!ft_base_checks(base))
		return ;
	number = nbr;
	size = ft_strlen(base);
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number >= size)
	{
		ft_putnbr_base(number / size, base);
		ft_putnbr_base(number % size, base);
	}
	else
		ft_putchar(base[number]);
}
