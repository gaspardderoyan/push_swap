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


int	chunk_sort(t_dlist **a, t_dlist **b, t_stacks_mt *mt)
{
	int	operations;

	update_mt(mt);
	operations = 0;
	// Push everything to stack b, sorted into chunks
	while (mt->chunks_i < mt->chunks_count)
	{
		// Loop for each digit in the stack
		while (*a && dir_of_first(*a, mt))
		{
			if (dir_of_first(*a, mt)	== 1)
			{
				while (*a && (*a)->index > (mt->lst_size / mt->chunks_count))
				{
					rotate(a);
					operations++;
				}
			}
			else 
			{
				while (*a && (*a)->index > (mt->chunks_i + 1) * (mt->lst_size / mt->chunks_count))
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
		mt->chunks_i++;
	}
	while (*b)
	{
		push_first(b, a);
		operations++;
	}
	return (operations);
}
