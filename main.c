/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:14:31 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/25 15:14:17 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	***tetra;
	char	**map;

	if (ac == 2)
	{
		tetra = ft_mkmap(av[1]);
		map = dotary(ft_tetnum(tetra), 0);
		ft_printit(solve(map, tetra, sidelen(ft_tetnum(tetra))));
	}
	else
		ft_gtfo();
	return (0);
}
