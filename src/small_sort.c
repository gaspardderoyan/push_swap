/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:47 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/02/04 20:39:07 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"
#include "libft.h"

void	sort_three(t_mst *mst)
{
	int	f;
	int	s;
	int	t;

	f = mst->a->index;
	s = mst->a->next->index;
	t = mst->a->next->next->index;
	if (f > s && s < t && f < t)
		swap_first(&mst->a, &mst->l_ops, "sa");
	else if (f > s && s > t && f > t)
	{
		swap_first(&mst->a, &mst->l_ops, "sa");
		reverse(&mst->a, &mst->l_ops, "rra");
	}
	else if (f > s && s < t && f > t)
		rotate(&mst->a, &mst->l_ops, "ra");
	else if (f < s && s > t && f < t)
	{
		swap_first(&mst->a, &mst->l_ops, "sa");
		rotate(&mst->a, &mst->l_ops, "ra");
	}
	else if (f < s && s > t && f > t)
		reverse(&mst->a, &mst->l_ops, "rra");
}

/**
* Given a list and a node's index (ie. it's position within the whole)
* finds the node who's index is right below && next one is right above
* ie. to find the correct position within a sorted list
*/
t_dlist	*node_index_above(t_dlist *lst, int src_i)
{
	while (lst)
	{
		if (lst->index < src_i && lst->next && lst->next->index > src_i)
			return (lst->next);
		lst = lst->next;
	}
	return (lst);
}

t_dlist *smallest_index_above(t_dlist *lst, int src_i)
{
	t_dlist *smallest_lower;
	smallest_lower = NULL;
	while (lst)
	{
		if (lst->index > src_i &&
			(!smallest_lower || lst->index < smallest_lower->index))
			smallest_lower = lst;
		lst = lst->next;
	}
	return (smallest_lower);
}

// for each number in b
// if smaller than the first, just push to a
// if larger than the last, push to a then rotate
//
// else, find the index of the value that's below the value in b
// but it's next is above
void	sort_five(t_mst *mst)
{

	t_dlist *node_above;
	int	i = 0;
	// TODO if is_sorted, return ;
	while (ft_dlstsize(mst->a) != 3)
		push_first(&mst->a, &mst->b, &mst->l_ops, "pb"); // Push 2 elements from 'a' to 'b'
	sort_three(mst); // Sort the remaining 3 in 'a'

	// Instead of `while(b_cursor)`, iterate as long as stack 'b' is not empty
	while (mst->b != NULL && i < 2)
	{
		if (mst->b->index < mst->a->index && get_lst_min(mst->a, false) == mst->a)
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa"); // Push from 'b' to 'a' - 'b' head changes here!
		else if (mst->b->index > ft_dlstlast(mst->a)->index && get_lst_min(mst->a, false) == mst->a)
		{
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa"); // Push from 'b' to 'a' - 'b' head changes here!
			rotate(&mst->a, &mst->l_ops, "ra");
		}
		else
		{
			node_above = smallest_index_above(mst->a, mst->b->index);
			if (dlst_node_dir(mst->a, node_above))
			{
				while (mst->a != node_above)
				{
					rotate(&mst->a, &mst->l_ops, "ra");
				}
			}
			else
			{
				while (mst->a !=  node_above)
				{
					reverse(&mst->a, &mst->l_ops, "rra");
				}
			}
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa"); // Push from 'b' to 'a' - 'b' head changes here!

		}
		i++;
	}
	if (dlst_node_dir(mst->a, get_dlst_min_max_index(mst->a, false)))
	{
		while (mst->a != get_dlst_min_max_index(mst->a, false))
		{
			rotate(&mst->a, &mst->l_ops, "ra");
		}
	}
	else
	{
		while (mst->a !=  get_dlst_min_max_index(mst->a, false))
		{
			reverse(&mst->a, &mst->l_ops, "rra");
		}
	}
}
