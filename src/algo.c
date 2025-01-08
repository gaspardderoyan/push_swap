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

/*
	* return 1 if should start from start
	* return -1 if should start from end
	* return 0 if should skip to next stack
*/
int direction_of_first(t_dlist *a, int chunks_count, int chunks_i)
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
		while (*a && direction_of_first(*a, chunks_count, chunks_i))
		{
			if (direction_of_first(*a, chunks_count, chunks_i)	== 1)
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
