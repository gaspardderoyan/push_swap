/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:18:32 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/03/12 17:43:17 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

static void	sort_in_chunks(t_mst *mst)
{
	while (mst->mt.chunks_i < mst->mt.chunks_count)
	{
		update_stacks_mt(&mst->mt);
		while (mst->a && dir_of_first(mst->a, &mst->mt))
		{
			if (dir_of_first(mst->a, &mst->mt) == 1)
			{
				while (mst->a && ((mst->a)->index < mst->mt.lower_limit
						|| (mst->a)->index > mst->mt.upper_limit))
					rotate(&mst->a, &mst->l_ops, "ra");
			}
			else
			{
				while (mst->a && ((mst->a)->index < mst->mt.lower_limit
						|| (mst->a)->index > mst->mt.upper_limit))
					reverse(&mst->a, &mst->l_ops, "rra");
			}
			if (mst->a)
				push_first(&mst->a, &mst->b, &mst->l_ops, "pb");
		}
		mst->mt.chunks_i++;
	}
}

static void	push_max(t_mst *mst)
{
	while (mst->b)
	{
		if (dlst_node_dir(mst->b, get_lst_max(mst->b)))
		{
			while (mst->b != get_lst_max(mst->b))
				rotate(&mst->b, &mst->l_ops, "rb");
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa");
		}
		else
		{
			while (mst->b != get_lst_max(mst->b))
				reverse(&mst->b, &mst->l_ops, "rrb");
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa");
		}
	}
}

void	chunk_sort(t_mst *mst)
{
	sort_in_chunks(mst);
	push_max(mst);
}
