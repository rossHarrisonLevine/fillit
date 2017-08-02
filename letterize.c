/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:25:47 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/25 14:28:53 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tetnum(char ***map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	***ft_letterize(char ***map, int i, int j, int k)
{
	int alpha;

	alpha = 65;
	while (map[k])
	{
		j = 0;
		while (map[k][j])
		{
			i = 0;
			while (i < 4)
			{
				if (map[k][j][i] == '#')
					map[k][j][i] = alpha;
				i++;
			}
			j++;
		}
		alpha++;
		k++;
	}
	return (map);
}
