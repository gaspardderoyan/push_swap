#include "../inc/double_lst.h"
#include "../inc/project.h"

int insertion_sort(t_dlist **a, t_dlist **b)
{
    int min;
    int operations;

    operations = 0;
    while (ft_dlstsize(*a) != 0)
    {
        min = *(int *)(get_lst_min(*a, false)->content);
        while (*(int *)(*a)->content != min)
        {
            rotate(a); 
            operations++;
        }
        push_first(a, b);
        operations++;
    }
    while (ft_dlstsize(*b) != 0)
    {
        push_first(b, a);
        operations++;
    }
    return (operations);
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

/*
	* return 1 if should start from start
	* return -1 if should start from end
	* return 0 if should skip to next stack
*/
int dir_of_first(t_dlist *a, int chunks_count, int chunks_i)
{
	t_dlist *cursor;
	int	start_i;
	int	end_i;
	int	chunk_limit;

	if (!a || !chunks_count || chunks_i + 1 >= chunks_count)
		return (0);
	start_i = 0;
	end_i = 0;
	chunk_limit = (chunks_i + 1) * (ft_dlstsize(a) / chunks_count);
	cursor = a;
	while (cursor)
	{
		if (cursor->index < chunk_limit)
			break ;
		start_i++;
		cursor = cursor->next;
	}
	if (!cursor)
		return (0);
	cursor = ft_dlstlast(a);
	while (cursor)
	{
		if (cursor->index < chunk_limit)
			break ;
		end_i++;
		cursor = cursor->prev;
	}
	if (start_i <= end_i)
		return (1);
	else
		return (-1);
}

int	chunk_sort(t_dlist **a, t_dlist **b, int chunks_count)
{
	int	operations;
	int	chunks_i;
	int	lst_size;

	operations = 0;
	chunks_i = 0;
	lst_size = ft_dlstsize(*a);
	// Push everything to stack b, sorted into chunks
	while (chunks_i < chunks_count)
	{
		// Loop for each digit in the stack
		while (*a && dir_of_first(*a, chunks_count, chunks_i))
		{
			if (dir_of_first(*a, chunks_count, chunks_i)	== 1)
			{
				while (*a && (*a)->index > (lst_size / chunks_count))
				{
					rotate(a);
					operations++;
				}
			}
			else 
			{
				while (*a && (*a)->index > (chunks_i + 1) * (lst_size / chunks_count))
				{
					reverse(a);
					operations++;
				}
			}
			if (*a)
			{
				push_first(a, b);
				operations++;
			}
		}
		chunks_i++;
	}
	while (*b)
	{
		push_first(b, a);
		operations++;
	}
	return (operations);
}
