/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:04:18 by hagalsty          #+#    #+#             */
/*   Updated: 2021/01/25 23:04:21 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t len)
{
	size_t			length;
	unsigned char	*str;

	str = s;
	length = 0;
	while (length < len)
	{
		str[0] = 0;
		length++;
		str++;
	}
}
