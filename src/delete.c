#include "../inc/project.h"

/*
 * free_flag: 
 * 0 --> print
 * 1 --> print + free
 * 2 --> free
 */
void	pnf_list(t_dlist *lst, int free_flag)
{
	t_dlist	*current;

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
