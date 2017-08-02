/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:59:09 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/24 15:05:09 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mapfail(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	ft_gtfo(void)
{
	ft_putstr("usage: ./fillit [file]\n");
	exit(1);
}
