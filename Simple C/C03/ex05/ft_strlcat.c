unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[k] != '\0' && k < size)
		k++;
	while (src[j] != '\0')
		j++;
	while (src[i] != '\0' && (i + k + 1 < size))
	{
		dest[i + k] = src[i];
		i++;
	}
	if (k < size)
		dest[i + k] = '\0';
	return (k + j);
}
