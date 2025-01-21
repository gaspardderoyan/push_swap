/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:18:32 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 23:41:40 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"


void	sort_in_chunks(t_dlist **a, t_dlist **b, t_stacks_mt *mt, int *ops)
{
	while (mt->chunks_i < mt->chunks_count)
	{
		update_stacks_mt(mt);
		while (*a && dir_of_first(*a, mt))
		{
			if (dir_of_first(*a, mt) == 1)
			{
				while (*a && ((*a)->index < mt->lower_limit ||
					(*a)->index > mt->upper_limit))
						rotate(a, ops);
			}
			else 
			{
				while (*a && ((*a)->index < mt->lower_limit ||
					(*a)->index > mt->upper_limit))
						reverse(a, ops);
			}
			if (*a)
				push_first(a, b, ops);
		}
		mt->chunks_i++;
	}
	// TODO func: get the i (position) of a given node within the list
	// -> use it with eg. min or max node
	// function to get the ideal direction to go in 
	while (*b)
	{
		if (get_lst_max(*b)) // TODO get the best direction to rev/rot to get to the max
		{
			while (*b != get_lst_max(*b))
				rotate(b, ops);
			push_first(b, a, ops);
		}
		else
		{
			while (*b != get_lst_min(*b, false))
				reverse(b, ops);
			push_first(b, a, ops);

		}
	}
}

	

void	chunk_sort(t_dlist **a, t_dlist **b, t_stacks_mt *mt, int *ops)
{
	while (mt->chunks_i < mt->chunks_count)
	{
		update_stacks_mt(mt);
		while (*a && dir_of_first(*a, mt))
		{
			// ft_printf("stack a loop\n");
			if (dir_of_first(*a, mt) == 1)
			{
				while (*a && (*a)->index > mt->lower_limit && (*a)->index < mt->upper_limit)
				{
					// ft_printf("rotate\n");
					rotate(a, ops);
				}
			}
			else 
			{
				while (*a && (*a)->index > mt->lower_limit && (*a)->index < mt->upper_limit)
				{
					ft_printf("reverse\n");
					ft_printf("index: %d ; lower_limit: %d ; upper_limit: %d\n", (*a)->index, mt->lower_limit, mt->upper_limit);
					ft_printf("content: %d\n", *(int *)(*a)->content);
					reverse(a, ops);
				}
			}
			if (*a)
			{
				push_first(a, b, ops);
				// ft_printf("yes *a\n");
			}
			else
				ft_printf("no *a\n");
		}
		mt->chunks_i++;
		ft_printf("end of stack a loop\n");
	}
	while (*b)
	{
		while (*b != (get_lst_max(*b)))
			rotate(b, ops);
		push_first(b, a, ops);
	}
}
