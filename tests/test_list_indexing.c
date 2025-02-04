/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:07:36 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/02/04 17:09:00 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD	"\033[1m"

// Modified function to create a doubly linked list from an array
static t_dlist *dlst_from_arr(int *arr, size_t size)
{
    t_dlist *new = NULL;
    if (arr == NULL)
	{
        return NULL; // Handle null array input
    }
    for (size_t i = 0; i < size; i++)
	{
        add_nbr_to_lst(&new, arr[i]);
    }
    return new;
}

int	main(void)
{
	t_mst mst;
	mst.a = dlst_from_arr((int[]){4, 5, 3, 1}, 4);
	list_indexing(&mst);
	pnf_list(mst.a, 0);
}
