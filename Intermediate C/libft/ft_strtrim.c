/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:15:24 by hagalsty          #+#    #+#             */
/*   Updated: 2021/01/25 23:15:26 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_check(char const *x, char y)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(x))
	{
		if (x[i] == y)
			return (1);
		i++;
	}
	return (0);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	i = ft_strlen(s1);
	j = 0;
	while (j < i)
		if (ft_check(set, s1[j]))
			j++;
		else
			break ;
	s1 += j;
	if (*s1)
		if (!(i = ft_strlen(s1) - 1))
			return (0);
	j = 0;
	while (j <= i)
		if (ft_check(set, s1[i]))
			i--;
		else
			break ;
	s = malloc(i + 1);
	ft_strlcpy(s, s1, i + 2);
	return (s);
}
