/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 04:24:19 by marshaky          #+#    #+#             */
/*   Updated: 2025/02/03 19:01:12 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (!new_lst)
		return ;
	if (!lst)
	{
		*lst = new_lst;
		return ;
	}
	new_lst->next = *lst;
	*lst = new_lst;
}
