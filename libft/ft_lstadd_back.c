/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:52:14 by zgulal            #+#    #+#             */
/*   Updated: 2023/01/02 13:58:55 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst && !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ft_lstlast(*lst)-> next = new;
		ft_lstlast(*lst)-> next = NULL;
	}
}
