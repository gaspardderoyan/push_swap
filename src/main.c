/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:30:48 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 22:46:02 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"


int	main(int ac, char **av)
{
	t_mst mst;

	mst.a = NULL;
	mst.b = NULL;
	mst.ops = 0;
	errno = 0;
	if (ac == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	lst_from_input(ac, av, &mst);
	if (errno)
		return (ft_printf("Errno: %d\n", errno), ft_dlstfree(mst.a), ft_putstr_fd("Error\n", 2), 0);
	list_indexing(&mst, 5); // 2nd argument is chunks count
	ft_printf("Before sorting:\n");
    pnf_list(mst.a, 0);
	ft_printf("\nAfer sorting:\n");
	chunk_sort(&mst.a, &mst.b, &mst.mt, &mst.ops);
    pnf_list(mst.a, 0);
	ft_printf("Operations: %d\n", mst.ops);
	ft_dlstfree(mst.a);
	// choose_algo(&mst);
	// sort_list(&mst);
	// print_instructions(&mst);
    return (0);
}
