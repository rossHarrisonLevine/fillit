/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 06:20:15 by wwong             #+#    #+#             */
/*   Updated: 2017/07/28 19:20:01 by wwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char		**enlarge_map(char **map, int size)
{
	free(map);
	map = dotary(0, size);
	return (map);
}

char		**place(char **tetra, char **map, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < getdim(tetra, 1))
	{
		while (j < getdim(tetra, 0))
		{
			if (ft_isalpha(tetra[i][j]))
			{
				map[y + i][x + j] = tetra[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

char		**put_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;

	if (tetra == NULL || tetra == '\0')
		return (map);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (try_place(tetra, map, x, y))
			{
				map = place(tetra, map, x, y);
				return (map);
			}
			x++;
		}
		y++;
	}
	return (map);
}

char		**shift_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;
	int			flag;

	flag = 0;
	y = 0;
	while (y <= size - getdim(tetra, 1))
	{
		x = 0;
		while (x <= size - getdim(tetra, 0))
		{
			if (map[y][x] > 90 && flag == 0)
				flag = 1;
			else if (map[y][x] == '#' && flag == 0)
				flag = 1;
			else if (flag && try_place(tetra, map, x, y))
				return (place(tetra, map, x, y));
			x++;
		}
		y++;
	}
	return (map);
}

int			tryshift_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;
	int			flag;

	y = 0;
	flag = 0;
	while (y <= size - getdim(tetra, 1))
	{
		x = 0;
		while (x <= size - getdim(tetra, 0))
		{
			if (map[y][x] > 90 && flag == 0)
				flag = 1;
			else if (map[y][x] == '#' && flag == 0)
				flag = 1;
			else if (flag && try_place(tetra, map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
