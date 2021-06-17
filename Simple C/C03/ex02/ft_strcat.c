char	*ft_strcat(char *dest, char *src)
{
	int i;
	int d_size;

	i = 0;
	d_size = 0;
	while (dest[d_size])
		d_size++;
	while (src[i])
	{
		dest[d_size] = src[i];
		d_size++;
		i++;
	}
	dest[d_size] = '\0';
	return (dest);
}
