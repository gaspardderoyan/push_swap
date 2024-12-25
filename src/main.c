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

int iterative_min_sort(t_dlist **a, t_dlist **b)
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

int main(int argc, char **argv)
{
	t_dlist *a;
	/*t_dlist *b;*/
	int     lst_size;

	a = NULL;
	/*b = NULL;*/
	errno = 0;
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		lst_from_str(argv[1], &a);
	else
		lst_from_strs(argc, argv, &a);
	if (errno)
	{
		ft_printf("errno: %i\n", errno);
		pnf_list(a, 2);
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	lst_size = ft_dlstsize(a);
	ft_printf("lst_size: %i\n\n", lst_size);
    list_indexing(&a, lst_size);
	ft_printf("Before sorting: \n");
    pnf_list(a, 0);
    return (0);
}
