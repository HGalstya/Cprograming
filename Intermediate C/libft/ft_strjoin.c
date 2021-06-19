/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:12:52 by hagalsty          #+#    #+#             */
/*   Updated: 2021/01/25 23:13:23 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	d = malloc(len + 1);
	ft_memmove(d, s1, ft_strlen(s1));
	ft_memmove(d + ft_strlen(s1), s2, ft_strlen(s2));
	d[len] = 0;
	return (d);
}
