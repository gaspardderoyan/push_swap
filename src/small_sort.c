/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:47 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/03/12 18:22:31 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

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

static t_dlist	*smallest_index_above(t_dlist *lst, int src_i)
{
	t_dlist	*smallest_lower;

	smallest_lower = NULL;
	while (lst)
	{
		if (lst->index > src_i
			&& (!smallest_lower || lst->index < smallest_lower->index))
			smallest_lower = lst;
		lst = lst->next;
	}
	return (smallest_lower);
}

static void	push_back_small(t_mst *mst)
{
	if (dlst_node_dir(mst->a, get_dlst_min_max_index(mst->a, false)))
	{
		while (mst->a != get_dlst_min_max_index(mst->a, false))
		{
			rotate(&mst->a, &mst->l_ops, "ra");
		}
	}
	else
	{
		while (mst->a != get_dlst_min_max_index(mst->a, false))
		{
			reverse(&mst->a, &mst->l_ops, "rra");
		}
	}
}

static void	place_within_five(t_mst *mst)
{
	t_dlist	*node_above;

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
		while (mst->a != node_above)
		{
			reverse(&mst->a, &mst->l_ops, "rra");
		}
	}
	push_first(&mst->b, &mst->a, &mst->l_ops, "pa");
}

void	sort_five(t_mst *mst)
{
	int		i;

	i = 0;
	while (ft_dlstsize(mst->a) != 3)
		push_first(&mst->a, &mst->b, &mst->l_ops, "pb");
	sort_three(mst);
	while (mst->b != NULL && i < 2)
	{
		if (mst->b->index < mst->a->index
			&& get_lst_min(mst->a, false) == mst->a)
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa");
		else if (mst->b->index > ft_dlstlast(mst->a)->index
			&& get_lst_min(mst->a, false) == mst->a)
		{
			push_first(&mst->b, &mst->a, &mst->l_ops, "pa");
			rotate(&mst->a, &mst->l_ops, "ra");
		}
		else
		{
			place_within_five(mst);
		}
		i++;
	}
	push_back_small(mst);
}
