/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 19:22:46 by hagalsty          #+#    #+#             */
/*   Updated: 2021/05/02 19:22:49 by hagalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*error(char *stock)
{
	free(stock);
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		n;
	char	c;
	char	*str;

	i = 0;
	if (fd < 0)
		return (-1);
	if (!(str = (char *)malloc(10000 + 1)))
		return (-1);
	while ((n = read(fd, &c, 1)) && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			str[i] = c;
		i++;
	}
	str[i] = '\0';
	*line = str;
	return (n);
}
