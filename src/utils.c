/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:17:59 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/03/12 18:33:10 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"
#include "libft.h"

/**
* Takes dlist as input, finds the min of the content nodes, returns the node
*
* If index_mode is set to true, it finds the minimum ONLY OUT OF the
* values which index's are not already set (ie. is currently -1)
*
* ie. if the index_mode is false OR the current index is -1, it processes the
* current node.
*
* However, if the index is already set (not -1) AND index_mode is true,
* it skips the value, ie. it will find the next min value to index.
*/
t_dlist	*get_lst_min(t_dlist *lst, int index_mode)
{
	t_dlist	*min;
	int		current_val;

	min = NULL;
	while (lst)
	{
		if (lst->index == -1 || index_mode == false)
		{
			if (min == NULL || (*(int *)lst->content < current_val))
			{
				min = lst;
				current_val = *(int *)lst->content;
			}
		}
		lst = lst->next;
	}
	return (min);
}

t_dlist	*get_dlst_min_max_index(t_dlist *lst, bool max)
{
	t_dlist	*res;

	res = lst;
	while (lst)
	{
		if (lst->index < res->index && !max)
			res = lst;
		else if (lst->index > res->index && max)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

void	print_instructions(t_dlist *l_ops)
{
	while (l_ops)
	{
		ft_printf("%s\n", (char *)l_ops->content);
		l_ops = l_ops->next;
	}
}

static bool	is_sorted(t_mst *mst)
{
	int		current;
	t_dlist	*iter;

	iter = mst->a;
	while (iter)
	{
		current = *(int *)iter->content;
		iter = iter->next;
		if (iter && *(int *)iter->content < current)
			return (false);
	}
	return (true);
}

void	choose_algo(t_mst *mst)
{
	if (is_sorted(mst))
		return ;
	if (ft_dlstsize(mst->a) == 2)
	{
		rotate(&mst->a, &mst->l_ops, "ra");
		return ;
	}
	if (ft_dlstsize(mst->a) <= 3)
		sort_three(mst);
	else if (ft_dlstsize(mst->a) <= 5)
		sort_five(mst);
	else
	{
		mst->mt.chunks_count = 5;
		if (mst->mt.lst_size > 100)
			mst->mt.chunks_count = 11;
		chunk_sort(mst);
	}
}
