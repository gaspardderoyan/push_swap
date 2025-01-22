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

void iterative_min_sort(t_dlist **a, t_dlist **b, int *ops)
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

void	dir_iterative_min_sort(t_dlist **a, t_dlist **b, int *ops)
{
	while (*a)
	{
		if (dlst_node_dir(*a, get_lst_min(*a, false)))
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
