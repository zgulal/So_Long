/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:36:02 by zgulal            #+#    #+#             */
/*   Updated: 2022/12/30 15:36:07 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	result = malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j])
			j++;
		result[i++] = ft_substr(s, 0, j);
		s += j;
	}
	result[i] = NULL;
	return (result);
}
