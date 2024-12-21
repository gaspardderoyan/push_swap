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
				ft_printf("contents: %d\n", *(int *)lst->content);
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

void	sort_3(t_dlist **a);

int main(int argc, char **argv)
{
	t_dlist *a;
	t_dlist *b;
	int	lst_size;

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
	ft_printf("lst_size: %i\n", lst_size);
	if (lst_size <= 3)
		sort_3(&a);
	ft_putstr_fd("\nlist a:\n", 1);
	pnf_list(a, 1);
	return (0);
}
