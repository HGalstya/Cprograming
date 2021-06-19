/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:10:07 by hagalsty          #+#    #+#             */
/*   Updated: 2021/01/25 23:10:09 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			length;
	unsigned char	*str;

	str = b;
	length = 0;
	while (length < len)
	{
		*str = c;
		length++;
		str++;
	}
	return (b);
}
