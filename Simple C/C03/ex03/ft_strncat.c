char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	int d_size;

	i = 0;
	d_size = 0;
	while (dest[d_size])
		d_size++;
	while (nb > 0 && src[i])
	{
		dest[d_size] = src[i];
		d_size++;
		i++;
		nb--;
	}
	dest[d_size] = '\0';
	return (dest);
}
