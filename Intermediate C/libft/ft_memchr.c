/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:09:05 by hagalsty          #+#    #+#             */
/*   Updated: 2021/01/25 23:09:07 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned		int		i;
	unsigned		char	c1;
	const unsigned	char	*src;

	c1 = (unsigned char)c;
	src = s;
	i = 0;
	while (i < n)
	{
		if (src[i] == c1)
		{
			return (void*)(src + i);
		}
		i++;
	}
	return (0);
}
