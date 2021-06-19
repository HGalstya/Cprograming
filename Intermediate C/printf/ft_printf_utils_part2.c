#include "ft_printf.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			length;
	unsigned char	*str;

	str = b;
	length = 0;
	while (length < len)
	{
		*str = c;
		length++;
		str++;
	}
	str[0] = '\0';
	return (b);
}

char			*ft_itoa(int n)
{
	int				n1;
	unsigned int	n2;
	int				i;
	char			*d;

	i = ft_dc(n);
	n1 = 0;
	n2 = n;
	d = malloc(i);
	d[--i] = '\0';
	if (n < 0)
	{
		n2 = n * -1;
		d[n1] = '-';
		n1++;
	}
	while (n1 < i--)
	{
		d[i] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (d);
}

char			*ft_itoa_u(unsigned int n)
{
	unsigned int	n1;
	unsigned int	n2;
	unsigned int	i;
	char			*d;

	i = ft_dc_u(n);
	n1 = 0;
	n2 = n;
	d = malloc(i);
	d[--i] = '\0';
	while (n1 < i--)
	{
		d[i] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (d);
}

char			*ft_itoa_hex(unsigned int n, char c)
{
	unsigned int	n1;
	unsigned int	n2;
	unsigned int	i;
	char			*d;
	char			*hexdigits;

	if (c == 'x')
		hexdigits = ft_strdup("0123456789abcdef");
	else
		hexdigits = ft_strdup("0123456789ABCDEF");
	hexdigits[16] = '\0';
	i = ft_dc_hex(n);
	n1 = 0;
	n2 = n;
	d = malloc(i);
	d[--i] = '\0';
	while (n1 < i--)
	{
		d[i] = hexdigits[n2 % 16];
		n2 /= 16;
	}
	free(hexdigits);
	return (d);
}

char			*ft_itoa_ptr(void *p)
{
	uintptr_t		n2;
	int				i;
	char			*d;
	char			*hexdigits;

	n2 = (uintptr_t)p;
	hexdigits = ft_strdup("0123456789abcdef");
	i = ft_dc_hex(n2);
	i += 2;
	d = malloc(sizeof(char) * i);
	d[--i] = '\0';
	d[0] = '0';
	d[1] = 'x';
	while (i-- > 2)
	{
		d[i] = hexdigits[n2 % 16];
		n2 /= 16;
	}
	free(hexdigits);
	return (d);
}
