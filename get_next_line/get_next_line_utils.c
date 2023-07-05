/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:25:36 by zgulal            #+#    #+#             */
/*   Updated: 2023/06/21 16:25:37 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buf)
{
	int		i;
	int		j;
	char	*result;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	if (!buf)
		return (NULL);
	result = malloc(ft_strlen1(str) + ft_strlen1(buf) + 1);
	i = -1;
	j = 0;
	while (str[++i])
		result[i] = str[i];
	while (buf[j])
		result[i++] = buf[j++];
	result[i] = '\0';
	free(str);
	return (result);
}

int	ft_check_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_one_line(char *str)
{
	int		i;
	char	*line;

	if (str[0] == '\0')
		return (NULL);
	line = malloc(ft_strlen1(str) + 2);
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
		{
			line[i] = '\0';
			return (line);
		}
		line[i] = str[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_after_line(char *str)
{
	int		i;
	int		j;
	char	*new_line;

	i = -1;
	j = 0;
	while (str[++i] != '\n')
	{
		if (str[i] == '\0')
		{
			free(str);
			return (NULL);
		}
	}
	i++;
	new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (str[i])
		new_line[j++] = str[i++];
	new_line[j] = '\0';
	free(str);
	return (new_line);
}
