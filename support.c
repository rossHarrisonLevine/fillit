/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:37:32 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/24 13:52:31 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_maplen(char *file)
{
	int		fd;
	char	*str;
	int		c;

	c = 0;
	fd = open(file, O_RDONLY);
	str = ft_strnew(1);
	while (read(fd, str, 1))
		c++;
	if ((c + 1) / 21 <= 26 && (c + 1) % 21 == 0 && c != 0)
		return (ft_prelim_dot_hash(file, 0, c));
	else
	{
		ft_mapfail();
		exit(1);
	}
}

char	**ft_makeasquare(int len)
{
	char	**matrix;
	int		j;

	matrix = ft_memalloc(sizeof(char*) * (len + 1));
	j = 0;
	while (j < len)
	{
		matrix[j] = ft_strnew((len));
		j++;
	}
	matrix[j] = NULL;
	return (matrix);
}

char	***ft_makearectangularprism(void)
{
	char	***rectpris;
	int		i;

	rectpris = ft_memalloc(sizeof(char*) * 5 * 26);
	i = 0;
	while (i <= 25)
	{
		rectpris[i] = ft_makeasquare(4);
		i++;
	}
	return (rectpris);
}

int		ft_min(char *str, int start)
{
	int	min;
	int i;

	i = 0;
	min = (str[start] - 48);
	while (i <= 3)
	{
		if (min > (str[start] - 48))
			min = (str[start] - 48);
		i++;
		start++;
	}
	return (min);
}

int		ft_max(char *str, int start)
{
	int max;
	int i;

	i = 0;
	max = ((str[start] - 48));
	while (i <= 3)
	{
		if (max < (str[start] - 48))
			max = (str[start] - 48);
		i++;
		start++;
	}
	return (max);
}
