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
	t_mst mst;

	mst.a = dlst_from_str("1 2 3 8 9 4 5 6 7 0");
	mst.b = NULL;
	mst.ops = 0;
	list_indexing(&mst, 2); // 2nd argument is chunks count
	pnf_list(mst.a, 0);
	ft_printf("\n");
	sort_in_chunks(&mst.a, &mst.b, &mst.mt, &mst.ops);	
	pnf_list(mst.b, 0);
	ft_dlstfree(mst.b);
}
