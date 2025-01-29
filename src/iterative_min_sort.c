/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_min_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:02:39 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/29 22:52:20 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"
#include "libft.h"

void iterative_min_sort(t_mst *mst)
{
    while (mst->a)
    {
        while (mst->a != get_lst_min(mst->a, false))
            rotate(&mst->a, &mst->l_ops, "ra"); 
        push_first(&mst->a, &mst->b, &mst->l_ops, "pb");
    }
    while (mst->b)
        push_first(&mst->b, &mst->a, &mst->l_ops, "pa");
}

void	dir_iterative_min_sort(t_mst *mst)
{
	while (mst->a)
	{
		if (dlst_node_dir(mst->a, get_lst_min(mst->a, false)))
		{
			while (mst->a != get_lst_min(mst->a, false))
				rotate(&mst->a, &mst->l_ops, "ra");
			push_first(&mst->a, &mst->b, &mst->l_ops, "pb");
		}
		else
		{
			while (mst->a != get_lst_min(mst->a, false))
				reverse(&mst->a, &mst->l_ops, "ra");
			push_first(&mst->a, &mst->b, &mst->l_ops, "pb");

		}
	}
	while (mst->b)
		push_first(&mst->b, &mst->a, &mst->l_ops, "pa");
}
