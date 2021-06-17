#include <unistd.h>

void	ft_putchar(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_comas(void)
{
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb(void)
{
	int x;
	int y;
	int z;

	x = -1;
	while (++x <= 7)
	{
		y = -1;
		while (++y <= 8)
		{
			z = -1;
			while (++z <= 9)
			{
				if (x < y && y < z)
				{
					ft_putchar(x + '0', y + '0', z + '0');
					if (x != 7 || y != 8 || z != 9)
						ft_comas();
				}
			}
		}
	}
}
