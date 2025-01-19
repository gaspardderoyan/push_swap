/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:30:48 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/19 01:30:51 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int ac, char **av)
{
	t_mst mst;

	mst.a = NULL;
	mst.b = NULL;
	errno = 0;
	if (ac == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	lst_from_input(ac, av, &mst);
	if (errno)
		return (printf("Errno: %d\n", errno), ft_dlstfree(mst.a), ft_putstr_fd("Error\n", 2), 0);
	list_indexing(&mst, 5); // 2nd argument is chunks count
    pnf_list(mst.a, 0);
	ft_dlstfree(mst.a);
	// choose_algo(&mst);
	// sort_list(&mst);
	// print_instructions(&mst);
    return (0);
}
