#include "../inc/project.h"

void    list_indexing(t_mst *mst, int chunks_count)
{
    int i;
    t_dlist *min_node;
    t_dlist *temp;

	mst->mt.chunks_i = 0;
	mst->mt.chunks_count = chunks_count;
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


int	i_of_first_last(t_dlist *lst, t_stacks_mt *mt, int first)
{
	t_dlist *cursor;
	int	i;

	i = 0;
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
	* return 1 if should start from start
	* return -1 if should start from end
	* return 0 if should skip to next stack
*/
int dir_of_first(t_dlist *lst, t_stacks_mt *mt)
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
 * @brief Updates the lower and upper limits of a chunk based on its index.
 * 
 * This function calculates the `lower_limit` and `upper_limit` for a specific
 * chunk within a list, given the chunk's index (`chunks_i`), the total number
 * of chunks (`chunks_count`), and the total size of the list (`lst_size`).
 * 
 * It divides the list into equal-sized chunks and determines the starting and
 * ending indices for the specified chunk. The last chunk may be smaller than
 * the others if the list size is not perfectly divisible by the number of chunks.
 * 
 * @param mt A pointer to a `t_stacks_mt` structure representing the chunk to be updated.
 */
void	update_mt(t_stacks_mt *mt)
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
