#include "../libft/inc/libft.h"
#include "../inc/double_lst.h"
#include "../inc/project.h"

void pnf_list(t_dlist *lst, int free_flag)
{
	t_dlist *current;

	while (lst != NULL)
	{
		if (free_flag != 2)
		{
			if (lst->content != NULL)
				ft_printf("%d ", *(int *)lst->content);
			else
				ft_printf("content is NULL\n");
		}
		current = lst;
		lst = lst->next;
		if (free_flag)
		{
			free(current->content);
			free(current);
		}
	}
	ft_printf("\n");
}

/*void	sort_3(t_dlist **a);*/

// TODO find_smallest
// return number, set index 
int find_smallest(t_dlist *lst)
{
    int min;
    min = *(int *)lst->content;
    while (lst)
    {
        if (min > *(int *)lst->content)
            min = *(int *)lst->content;
        lst = lst->next;
    }

    return (min);
}

int find_index(t_dlist *lst, int n)
{
    int i;
    i = 0;
    while (lst)
    {
        if (*(int *)lst->content == n)
            return (i);
        i++;
        lst = lst->next;
    }
    return (i);
}

/* TODO n_to_top
 * if smallest_index < len / 2
     * rotate until *a == smallest
 * else
     * reverse until *a == smallest

*/

int sort(t_dlist **a, t_dlist **b)
{
    int min;
    int operations;

    operations = 0;
    while (ft_dlstsize(*a) != 0)
    {
        min = find_smallest(*a);
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
	t_dlist *b;
	int	lst_size;
    int operations;
    /*int min;*/
    /*int min_index;*/

	a = NULL;
	b = NULL;
	errno = 0;
	ft_printf("argc: %i\n", argc);
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
	/*if (lst_size <= 3)*/
	/*	sort_3(&a);*/
	/*ft_putstr_fd("\nlist a:\n", 1);*/
	/*pnf_list(a, 0);*/
    /*min = find_smallest(a);*/
    /*min_index = find_index(a, min);*/
    /*ft_printf("\nmin: %i\n", min);*/
    /*ft_printf("\nmin index: %i\n", min_index);*/
    operations = sort(&a, &b);
	ft_putstr_fd("\nlist a:\n", 1);
	pnf_list(a, 0);
    ft_printf("\nOperations: %i\n", operations);
	return (0);
}
