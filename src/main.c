#include "../libft/inc/libft.h"
#include "../inc/double_lst.h"
#include "../inc/project.h"

/*
 * free_flag: 
 * 0 --> print
 * 1 --> print + free
 * 2 --> free
 */
void pnf_list(t_dlist *lst, int free_flag)
{
	t_dlist *current;
	while (lst != NULL)
	{
		if (free_flag != 2) // 2 means no printing
		{
            ft_printf(" (%d) --> ", lst->index);
			if (lst->content != NULL)
				ft_printf("%d", *(int *)lst->content);
			else
				ft_printf("NULL");
            ft_printf("\n");
		}
		current = lst;
		lst = lst->next;
		if (free_flag != 0) 
		{
			free(current->content);
			free(current);
		}
	}
}

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
	int	lst_size;
	int	hold_first_i;
	int	hold_second_i;

	hold_first_i = 0;
	hold_second_i = 0;
	lst_size = ft_dlstsize(a);
	cursor = a;
	while (cursor->next)
	{
		if (cursor->index <= (chunks_i + 1) * (lst_size / chunks_count))
			break ;
		hold_first_i++;
		cursor = cursor->next;
	}
	cursor = ft_dlstlast(a);
	while (cursor->prev)
	{
		if (cursor->index <= (chunks_i + 1) * (lst_size / chunks_count))
			break ;
		hold_second_i++;
		cursor = cursor->prev;
	}
	if (hold_first_i == 0 && hold_second_i == 0)
		return (0);
	else if (hold_first_i < hold_second_i)
		return (1);
	else
		return (-1);
}

int	chunk_sort(t_dlist **a, t_dlist **b, int chunks_count)
{
	int	operations;
	int	i;
	int	lst_size;

	operations = 0;
	i = 0;
	lst_size = ft_dlstsize(*a);
	// Push everything to stack b, sorted into chunks
	while (i < chunks_count)
	{
		// Loop for each digit in the stack
		while (*a && direction_of_first(*a, chunks_count, i))
		{
			if (direction_of_first(*a, chunks_count, i)	== 1)
			{
				while (*a && (*a)->index > (lst_size / chunks_count))
				{
					rotate(a);
					operations++;
				}
			}
			else 
			{
				while (*a && (*a)->index > (i + 1) * (lst_size / chunks_count))
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
		i++;
	}
	// Push everything back to stack a, making sure it's now sorted
	while (lst_size > 0)
	{
		// push_index(b, a, lst_size - 1, &operations);
		lst_size--;
	}
	return (operations);
}

int main(int argc, char **argv)
{
	t_dlist *a;
	t_dlist *b;
	int     lst_size;
	int		operations;

	a = NULL;
	b = NULL;
	operations = 0;
	errno = 0;
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		lst_from_str(argv[1], &a);
	else
		lst_from_strs(argc, argv, &a);
	// if (errno)
	// {
	// 	ft_printf("errno: %i\n", errno);
	// 	pnf_list(a, 2);
	// 	return (ft_putstr_fd("Error\n", 2), 0);
	// }
	lst_size = ft_dlstsize(a);
	ft_printf("lst_size: %i\n\n", lst_size);
    list_indexing(&a, lst_size);
	ft_printf("Before sorting: \n");
    pnf_list(a, 0);
	// operations = insertion_sort(&a, &b);
	operations = chunk_sort(&a, &b, 5);
	ft_printf("After sorting: \n");
    pnf_list(a, 0);
	ft_printf("Operations: %i\n", operations);
    return (0);
}
