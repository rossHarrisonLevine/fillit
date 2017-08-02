/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 22:51:16 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/02 14:25:18 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t t)
{
	char	*ptr;

	ptr = NULL;
	if (t)
	{
		ptr = (char *)malloc(sizeof(char) * t);
		if (!ptr)
			return (NULL);
		else
			ft_bzero(ptr, t);
	}
	return ((void *)ptr);
}
