/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:30:48 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/29 22:52:39 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"


int	main(int ac, char **av)
{
	t_mst mst;

	mst.a = NULL;
	mst.b = NULL;
	mst.l_ops = NULL;
	errno = 0;
	if (ac == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	lst_from_input(ac, av, &mst);
	if (errno)
		return (ft_dlstfree(mst.a), ft_putstr_fd("Error\n", 2), 0);
	list_indexing(&mst);
	mst.mt.chunks_count = 5;
	// ft_printf("Before sorting:\n");
	//    pnf_list(mst.a, 0);
	// ft_printf("\nAfer sorting:\n");
	chunk_sort(&mst);
    // pnf_list(mst.a, 0);
	print_instructions(mst.l_ops);
	ft_dlstfree(mst.a);
	ft_dlstfree(mst.b);
	ft_dlstfree(mst.l_ops);
	// choose_algo(&mst);
	// sort_list(&mst);
	// print_instructions(&mst);
    return (0);
}
