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
            ft_printf("(%d) --> ", lst->index);
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

t_dlist *get_lst_min(t_dlist *lst)
{
    t_dlist *min = NULL;
    int current_val;

    while (lst)
    {
        if (lst->index == -1) // Only consider unindexed nodes
        {
            if (min == NULL || (*(int *)lst->content < current_val))
            {
                min = lst;
                current_val = *(int *)lst->content;
            }
        }
        lst = lst->next;
    }
    return min;
}

void initialize_indexes(t_dlist *lst)
{
    while (lst)
    {
        lst->index = -1;
        lst = lst->next;
    }
}

void index_list(t_dlist **lst, int lst_len)
{
    int i;
    t_dlist *min_node;

    initialize_indexes(*lst);
    i = 0;
    min_node = NULL;
    while (i < lst_len)
    {
        min_node = get_lst_min(*lst);
        if (min_node == NULL)
        {
            ft_printf("Fewer ndoes than expected\n");
            return ;
        }
        min_node->index = i;
        i++;
    }
}

int sort(t_dlist **a, t_dlist **b)
{
    int min;
    int operations;

    operations = 0;
    while (ft_dlstsize(*a) != 0)
    {
        min = *(int *)get_lst_min(*a)->content;
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
	int	lst_size;

	a = NULL;
	/*b = NULL;*/
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
    index_list(&a, lst_size);
    pnf_list(a, 0);
	return (0);
}
