/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:16:29 by hagalsty          #+#    #+#             */
/*   Updated: 2021/02/09 17:16:34 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	overlen;

	if (!s)
		return (NULL);
	overlen = ft_strlen(s + start);
	i = 0;
	if (overlen < len)
		len = overlen;
	if (!(str = (char *)(malloc)(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && (start + i) < ft_strlen(s))
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
