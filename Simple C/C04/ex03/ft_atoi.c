int	ft_atoi(char *str)
{
	int i;
	int count;
	int total;

	i = 0;
	count = 0;
	total = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count = count + 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if (count % 2 == 0)
		return (total);
	else
		return (-total);
}
