/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:14:24 by hagalsty          #+#    #+#             */
/*   Updated: 2021/01/25 23:14:25 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*st;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (!(st = malloc(size + 1)))
		return (0);
	ft_strlcpy(st, s, size + 1);
	while (i < size)
	{
		st[i] = (*f)(i, st[i]);
		i++;
	}
	return (st);
}
