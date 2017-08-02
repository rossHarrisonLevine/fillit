/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 18:43:17 by wwong             #+#    #+#             */
/*   Updated: 2017/07/28 16:44:19 by wwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		ft_printit(char **twod)
{
	int y;

	y = 0;
	while (twod[y])
	{
		ft_putstr(twod[y++]);
		ft_putchar('\n');
	}
}

char		**remove_tetra(char **map, int i, int size)
{
	int			d[4];

	d[1] = -1;
	d[2] = 50;
	d[3] = 50;
	while (++(d[1]) < size)
	{
		d[0] = -1;
		while (++(d[0]) < size)
		{
			if (map[d[1]][d[0]] == ('A' + i))
			{
				if (d[1] < d[3])
					d[3] = d[1];
				if (d[0] < d[2])
					d[2] = d[0];
				map[d[1]][d[0]] = '.';
			}
		}
	}
	if (d[2] < 50 && map[d[3]][d[2]] >= 'A' && map[d[3]][d[2]] <= 'Z')
		map[d[3]][d[2]] = ft_tolower(map[d[3]][d[2]]);
	else if (d[2] < 50)
		map[d[3]][d[2]] = '#';
	return (map);
}

int			getdim(char **tetra, int flag)
{
	int			x;
	int			y;

	y = 0;
	while (tetra[y])
	{
		x = 0;
		while (tetra[y][x])
			x++;
		y++;
	}
	if (flag == 0)
		return (x);
	else
		return (y);
}

int			try_place(char **tetra, char **map, int x, int y)
{
	int			i;
	int			j;

	i = -1;
	while (++i < getdim(tetra, 1))
	{
		j = -1;
		while (++j < getdim(tetra, 0))
			if (ft_isalpha(tetra[i][j]) && (map[y + i][x + j] != '.'))
				return (0);
	}
	return (1);
}

int			tryfit_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;

	y = 0;
	while (y <= size - getdim(tetra, 1))
	{
		x = 0;
		while (x <= size - getdim(tetra, 0))
		{
			if (try_place(tetra, map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
