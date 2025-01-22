/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:02:39 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 22:49:05 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"
#include "libft.h"

void insertion_sort(t_dlist **a, t_dlist **b, int *ops)
{
    while (*a)
    {
        while (*a != get_lst_min(*a, false))
            rotate(a, ops); 
        push_first(a, b, ops);
    }
    while (*b)
        push_first(b, a, ops);
}

// TODO use a function pointer as 2nd arg, to choose if lst_min or max
int	get_min_dir(t_dlist *lst)
{
	int		len;
	int		i;
	t_dlist	*min;

	len = ft_dlstsize(lst);
	i = 0;
	min = get_lst_min(lst, false);
	while (lst)
	{
		if (lst == min)
			break;
		i++;
		lst = lst->next;
	}
	return (i <= len / 2);
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
	while (lst)
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

void	dir_insertion_sort(t_dlist **a, t_dlist **b, int *ops)
{
	while (*a)
	{
		if (get_min_dir(*a))
		{
			while (*a != get_lst_min(*a, false))
				rotate(a, ops);
			push_first(a, b, ops);
		}
		else
		{
			while (*a != get_lst_min(*a, false))
				reverse(a, ops);
			push_first(a, b, ops);

		}
	}
	while (*b)
		push_first(b, a, ops);
}
