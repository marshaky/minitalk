/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 04:24:23 by marshaky          #+#    #+#             */
/*   Updated: 2025/02/03 19:01:32 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*tmp;

	if (!new_lst || !lst)
		return ;
	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new_lst;
}
