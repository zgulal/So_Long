/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:25 by zgulal            #+#    #+#             */
/*   Updated: 2022/12/30 15:36:49 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	i;
	size_t	j;

	lensrc = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (lensrc);
	while (dst[i] && dstsize)
	{
		dstsize--;
		i++;
	}
	j = 0;
	while (src[j] && dstsize > 1)
	{
		dst[i + j] = src[j];
		j++;
		dstsize--;
	}
	if (dstsize != 0)
		dst[i + j] = '\0';
	return (lensrc + i);
}
