/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:54:30 by zgulal            #+#    #+#             */
/*   Updated: 2022/12/30 15:34:22 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = ((char *)dst);
	s = ((char *)src);
	if (!dst && !src)
		return (0);
	if (d > s)
	{
		while (len > 0)
		{
			d[len -1] = s[len - 1];
				len--;
		}
	}
	while (len--)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dst);
}
