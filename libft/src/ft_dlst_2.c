/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:00:03 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 22:50:28 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_dlstfree(t_dlist *lst)
{
	t_dlist	*next;

	while (lst)
	{
		next = lst->next;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = next;
	}
}

t_dlist	*get_lst_max(t_dlist *lst)
{
	t_dlist	*max;
	int		current_val;

	max = NULL;
	while (lst)
	{
		if (max == NULL || (*(int *)lst->content > current_val))
		{
			max = lst;
			current_val = *(int *)lst->content;
		}
		lst = lst->next;
	}
	return (max);
}
