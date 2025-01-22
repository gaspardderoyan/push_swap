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

/*
 * Finds the position of a node within a list
 *
 * Returns -1 if didn't find it
 * (ie. if lst has been traversed completely)
 */
int	dlst_node_i(t_dlist *lst, t_dlist *node)
{
	int	i;

	i = 0;
	while (lst && node)
	{
		if (lst == node)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

/*
 * Finds shortest path to given node in a list
 *
 * 1 -> from start
 *
 * 0 -> from end
 *
 * -1 -> node not found
 */
int	dlst_node_dir(t_dlist *lst, t_dlist *node)
{
	int	i;

	i = dlst_node_i(lst, node);
	if (i == -1)
		return (-1);
	return (i <= ft_dlstsize(lst) / 2);
}
