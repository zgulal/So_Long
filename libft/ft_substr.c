/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:32:47 by zgulal            #+#    #+#             */
/*   Updated: 2023/01/03 12:30:59 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen((char *)s);
		size = ft_strlen((char *)s);
	if (start > size)
		return (ft_strdup(""));
	if (size - start < len)
		str = (char *)malloc((size - start + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
