/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:18:22 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/03/12 18:36:02 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

/**
 * Takes in a master structure, and updates the metadata for the list.
 *
 * 1: sets the lst_size
 * 
 * 2: sets every index to -1, then iteratively sets the minimum to i++
 */
void	list_indexing(t_mst *mst)
{
	int		i;
	t_dlist	*min_node;
	t_dlist	*temp;

	mst->mt.chunks_i = 0;
	mst->mt.lst_size = ft_dlstsize(mst->a);
	temp = mst->a;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
	i = 0;
	while (i < mst->mt.lst_size)
	{
		min_node = get_lst_min(mst->a, true);
		min_node->index = i;
		i++;
	}
}

/**
 * Gets the position in the dlist of the 1st item within the current stack
 * 
 * Either from the start or the end
 *
 * @param lst pointer to the dlist
 * @param mt pointer to the stack metadata (for the chunks' lower/upper limit)
 * @param first	boolean, true if we want first (ie. from start), false if last
 *
 * @return position of the item in the dlist
 *		-1 if item not found or invalid input
 */
static int	i_of_first_last(t_dlist *lst, t_stacks_mt *mt, bool first)
{
	t_dlist	*cursor;
	int		i;

	i = 0;
	if (!lst || !mt)
		return (-1);
	if (first)
		cursor = lst;
	else
		cursor = ft_dlstlast(lst);
	while (cursor)
	{
		if (cursor->index >= mt->lower_limit
			&& cursor->index <= mt->upper_limit)
			break ;
		i++;
		if (first)
			cursor = cursor->next;
		else
			cursor = cursor->prev;
	}
	return (i);
}

/*
 * Takes in a dlist and it's metadata
 * Returns best direction to know if rotate/reverse is best
 *
 * 1 if should start from start
 *
 * -1 if should start from end
 *
 * 0 if should skip to next stack
 */
int	dir_of_first(t_dlist *lst, t_stacks_mt *mt)
{
	int	start_i;
	int	end_i;
	int	lst_size;

	start_i = i_of_first_last(lst, mt, 1);
	end_i = i_of_first_last(lst, mt, 0);
	lst_size = ft_dlstsize(lst);
	if (start_i == lst_size && end_i == lst_size)
		return (0);
	else if (start_i < end_i)
		return (1);
	else
		return (-1);
}

/**
 * Updates the lower and upper limits of a chunk based on its index.
 * 
 * This function calculates the `lower_limit` and `upper_limit` for a specific
 * chunk within a list, given the chunk's index (`chunks_i`), the total number
 * of chunks (`chunks_count`), and the total size of the list (`lst_size`).
 * 
 * It divides the list into equal-sized chunks and determines the starting and
 * ending indices for the specified chunk. The last chunk may be smaller than
 * the others if the list size is not
 * perfectly divisible by the number of chunks.
 * 
 * @param mt struct with the stacks' metadata
 */
void	update_stacks_mt(t_stacks_mt *mt)
{
	int	chunk_size;

	if (!mt->chunks_count || !mt->lst_size)
		return ;
	chunk_size = mt->lst_size / mt->chunks_count;
	mt->lower_limit = mt->chunks_i * chunk_size;
	if (mt->chunks_i + 1 < mt->chunks_count)
		mt->upper_limit = (mt->chunks_i + 1) * chunk_size - 1;
	else
		mt->upper_limit = mt->lst_size - 1;
}
