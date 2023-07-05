/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:53:28 by zgulal            #+#    #+#             */
/*   Updated: 2023/01/02 13:53:30 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_len;

	lst_len = 1;
	if (!lst)
		return (0);
	while (lst -> next != NULL)
	{
		lst_len++;
		lst = lst -> next;
	}
	return (lst_len);
}
