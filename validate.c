/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:58:58 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/21 21:31:48 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**matrixit(char *str)
{
	char	**new;
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	new = ft_makeasquare(4);
	while (str[c] != '\0')
	{
		if (str[c] == '\n')
		{
			j++;
			i = 0;
		}
		if (str[c] != '\n')
			new[j][i++] = str[c];
		c++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_compare(char *analouge)
{
	if (ft_strstr(AL, analouge) || ft_strstr(ALL, analouge) || \
		ft_strstr(ALLL, analouge) || ft_strstr(ALLLL, analouge))
		return (matrixit(analouge));
	ft_mapfail();
	return (NULL);
}

char	*ft_crosshairs(char **matrix, int x, int y)
{
	int		i;
	int		j;
	char	*where;

	i = 0;
	j = 0;
	where = ft_strnew(9);
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (matrix[j][i] == '#')
			{
				where[x] = i + 48;
				where[y] = j + 48;
				x++;
				y++;
			}
			j++;
		}
		i++;
	}
	return (where);
}

char	**ft_trim(char **matrix, int left, int right)
{
	char	*coords;
	int		up;
	int		down;
	char	*analouge;
	int		c;

	analouge = ft_strnew(100);
	coords = ft_strnew(8);
	coords = ft_crosshairs(matrix, 0, 4);
	left = ft_min(coords, 0);
	right = ft_max(coords, 0);
	up = ft_min(coords, 4);
	down = ft_max(coords, 4);
	c = 1 + (down - up);
	while (c--)
	{
		ft_strncat(analouge, &matrix[up++][left], 1 + (right - left));
		ft_strncat(analouge, (const char *)&"\n", 1);
	}
	return (ft_compare(analouge));
}

char	**ft_chk_chars(char **matrix, int dot, int hash, int i)
{
	int j;

	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (matrix[j][i] != '\0')
		{
			if (matrix[j][i] == '.')
				dot++;
			if (matrix[j][i] == '#')
				hash++;
			i++;
		}
		j++;
	}
	if (dot == 12 && hash == 4)
		return (ft_trim(matrix, 0, 0));
	else
		ft_mapfail();
	return (NULL);
}
