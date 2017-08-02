/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 17:11:06 by wwong             #+#    #+#             */
/*   Updated: 2017/07/28 19:26:20 by wwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		tetra_in_map(char **map, int size, int i)
{
	int			x;
	int			y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			if (map[y][x] == ('A' + i))
				return (1);
	}
	return (0);
}

char	**clean_map(char **map, int size)
{
	int			x;
	int			y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (map[y][x] == '#')
				map[y][x] = '.';
			else if (map[y][x] > 90)
				map[y][x] = ft_toupper(map[y][x]);
		}
	}
	return (map);
}

int		sidelen(int tetnum)
{
	int			size;

	size = 2;
	while (size * size < tetnum)
		size++;
	return (size);
}

char	**dotary(int tetnum, int size)
{
	int		len;
	char	**ary;
	int		i;
	int		j;

	if (size != 0 && tetnum == 0)
		len = size;
	else
		len = sidelen(tetnum);
	ary = ft_makeasquare(len);
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			ary[j][i] = '.';
			i++;
		}
		j++;
	}
	return (ary);
}

char	**solve(char **map, char ***tetra, int s)
{
	int			i;

	i = 0;
	while (tetra[i])
	{
		map = clean_map(map, s);
		if (tetra_in_map(map, s, i) == 0 && tryfit_tetra(map, tetra[i], s))
			map = put_tetra(map, tetra[i++], s);
		else
		{
			map = remove_tetra(map, i, s);
			if (tryshift_tetra(map, tetra[i], s))
				map = shift_tetra(map, tetra[i++], s);
			else if (tryshift_tetra(map, tetra[i], s) == 0 && i == 0)
				map = enlarge_map(map, ++s);
			else
				i--;
		}
	}
	return (map);
}
