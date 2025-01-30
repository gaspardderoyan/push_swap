/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:47 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/30 22:21:30 by gderoyqn         ###   ########.fr       */
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
t_dlist	*node_index_below(t_dlist *lst, int src_i)
{
	while (lst)
	{
		if (lst->index < src_i && lst->next && lst->next->index > src_i)
			break ;
		lst = lst->next;
	}
	return (lst);
}

// for each number in b
// if smaller than the first, just push to a
// if larger than the last, push to a then rotate
//
// else, find the index of the value that's below the value in b
// but it's next is above
void	sort_five(t_mst *mst)
{

	push_first(&mst->a, &mst->b, &mst->l_ops, "pb"); // Push 2 elements from 'a' to 'b'
	push_first(&mst->a, &mst->b, &mst->l_ops, "pb");
	sort_three(mst); // Sort the remaining 3 in 'a'

	// Instead of `while(b_cursor)`, iterate as long as stack 'b' is not empty
	while (mst->b != NULL)
	{
		t_dlist *current_b_node = mst->b; // Work with the current head of 'b'

		if (current_b_node->index < get_dlst_min_max_index(mst->a, false)->index)
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa"); // Push from 'b' to 'a' - 'b' head changes here!
		else if (current_b_node->index > get_dlst_min_max_index(mst->a, true)->index)
		{
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa"); // Push from 'b' to 'a' - 'b' head changes here!
			rotate(&mst->a, &mst->l_ops, "ra");
		}
		else
		{
			if (dlst_node_dir(mst->a, node_index_below(mst->a, current_b_node->index)))
			{
				while (mst->a != node_index_below(mst->a, current_b_node->index))
					rotate(&mst->a, &mst->l_ops, "ra");
			}
			else
			{
				while (mst->a != node_index_below(mst->a, current_b_node->index))
					reverse(&mst->a, &mst->l_ops, "rra");
			}
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa"); // Push from 'b' to 'a' - 'b' head changes here!
		}
		// b_cursor = b_cursor->next; // PROBLEM! Don't advance using b_cursor->next!
		                               // List 'b' head was modified by push_first

		// After push_first(&mst->b, ...), the head of 'mst->b' has changed.
		// The loop condition `while (mst->b)` will check if 'b' is still not empty
		// For the next iteration, we again check the new head of 'mst->b'
	}
}

