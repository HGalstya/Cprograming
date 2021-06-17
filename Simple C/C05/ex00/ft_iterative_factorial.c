int	ft_iterative_factorial(int nb)
{
	int fal;

	fal = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	else
	{
		while (nb != 0)
		{
			fal = fal * nb;
			nb--;
		}
		return (fal);
	}
}
