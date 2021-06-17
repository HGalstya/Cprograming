int		is_num(char c)
{
	return ((c >= '0') && (c <= '9'));
}

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(is_num(str[i])))
			return (0);
		i++;
	}
	return (1);
}
