/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:59:27 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/25 14:01:18 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_newline_separator(char *str, int i, int count, int k)
{
	int m;

	while (str[i])
	{
		if (str[i++] == '#')
			count++;
	}
	if ((count != 0) && ((count % 4) == 0))
	{
		m = ((count / 4) - 1);
		if (m == 0)
			return ;
		while ((m > 0))
		{
			if (str[(m * 21) - 1] == '\n')
			{
				k++;
				m--;
			}
			else
				ft_mapfail();
		}
	}
	else
		ft_mapfail();
}

void	ft_boundary_validator(char *str, int i, int count, int k)
{
	int n;

	while (str[i])
	{
		if (str[i++] == '#')
			count++;
	}
	if ((count != 0) && ((count % 4) == 0))
	{
		n = count / 4;
		while (n > 0)
		{
			if (str[(n * 21) - 17] == '\n' && str[(n * 21) - 12] == '\n' &&
					str[(n * 21) - 7] == '\n' && str[(n * 21) - 2] == '\n')
			{
				k++;
				n--;
			}
			else
				ft_mapfail();
		}
	}
	else
		ft_mapfail();
}

int		ft_prelim_dot_hash(char *file, int dot, int len)
{
	char	*str;
	int		i;
	int		hash;
	int		fd;

	fd = open(file, O_RDONLY);
	str = ft_strnew(len);
	read(fd, str, len);
	close(fd);
	hash = 0;
	i = 0;
	ft_boundary_validator(str, 0, 0, 0);
	ft_newline_separator(str, 0, 0, 0);
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		if (str[i] == '#')
			hash++;
		i++;
	}
	if (dot % 12 == 0 && hash % 4 == 0)
		return (len);
	ft_mapfail();
	return (0);
}

char	**ft_twod(char *str, char **twod)
{
	int		a;
	int		i;
	int		j;

	a = 0;
	j = 0;
	while (str[a] != '\0')
	{
		i = 0;
		while (str[a] != '\n')
		{
			twod[j][i] = str[a];
			a++;
			i++;
		}
		j++;
		a++;
	}
	return (ft_chk_chars(twod, 0, 0, 0));
}

char	***ft_mkmap(char *file)
{
	int		fd;
	int		ticker;
	char	*str;
	char	***threed;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_mapfail();
	len = ft_maplen(file);
	threed = ft_makearectangularprism();
	ticker = 0;
	len = (len + 1) / 21;
	while (len--)
	{
		str = ft_strnew(21);
		read(fd, str, 20);
		str[20] = '\0';
		threed[ticker] = ft_twod(str, threed[ticker]);
		read(fd, str, 1);
		ticker++;
	}
	threed[ticker++] = NULL;
	return (ft_letterize(threed, 0, 0, 0));
}
