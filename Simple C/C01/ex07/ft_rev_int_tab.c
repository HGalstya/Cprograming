void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = -1;
	while (++i < --size)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
	}
}
