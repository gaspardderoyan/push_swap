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
#include "libft.h"


static void	sort_in_chunks(t_dlist **a, t_dlist **b, t_stacks_mt *mt, int *ops)
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
}

static void	push_max(t_dlist **a, t_dlist **b, int *ops)
{
	while (*b)
	{
		if (dlst_node_dir(*b, get_lst_max(*b)))
		{
			while (*b != get_lst_max(*b))
				rotate(b, ops);
			push_first(b, a, ops);
		}
		else
		{
			while (*b != get_lst_max(*b))
				reverse(b, ops);
			push_first(b, a, ops);

		}
	}
}

	

void	chunk_sort(t_dlist **a, t_dlist **b, t_stacks_mt *mt, int *ops)
{
	sort_in_chunks(a, b, mt, ops);
	push_max(a, b, ops);
}
