int	ft_recursive_factorial(int nb)
{
	int fal;

	fal = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	else
	{
		fal = nb * ft_recursive_factorial(nb - 1);
		return (fal);
	}
}
