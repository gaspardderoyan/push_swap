/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_chunk_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:57:47 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 22:36:04 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD	"\033[1m"

static t_dlist *dlst_from_str(char *str)
{
	t_dlist *lst = NULL;
	char **strs = ft_split(str, ' ');
	errno = 0;
	for (int i = 0; strs[i]; i++)
	{
		int cur_num = mini_strtoll(strs[i], 10);
		check_for_duplicate(lst, cur_num);
		if (errno)
			return (ft_printf("Duplicate value! (errno %d)\n"), NULL);
		add_nbr_to_lst(&lst, cur_num);
	}
	ft_free_strs(strs);
	return (lst);
}

int	main(void)
{
    printf(BOLD "\nINPUTS\n" RESET);
    printf(BOLD "lst_from_str\n" RESET);
	t_mst mst;

	mst.a = dlst_from_str("1 2 3 8 9 4 5 6 7 0");
	mst.b = NULL;
	mst.l_ops = NULL;
	list_indexing(&mst); 
	mst.mt.chunks_count = 2;
	pnf_list(mst.a, 0);
	ft_printf("\n");
	chunk_sort(&mst);	
	pnf_list(mst.b, 0);
	ft_dlstfree(mst.b);
}
