/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterative_min_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:58:22 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/29 23:14:37 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD	"\033[1m"

// Macro to calculate the size of the array and call the function
#define DLIST_FROM_ARR(arr) _dlst_from_arr(arr, sizeof(arr) / sizeof((arr)[0]))

// Modified function to create a doubly linked list from an array
static t_dlist *_dlst_from_arr(int *arr, size_t size)
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

void	is_dlist_sorted(t_dlist *lst, char *name, int ops)
{
	int	current;

	current = *(int *)lst->content;
	while (lst)
	{
		current = *(int *)lst->content;
		lst = lst->next;
		if (lst && *(int *)lst->content < current)
		{
			printf(RED "\n  Failed: " RESET);
			printf("  Current = %d, ", *(int *)lst->content);
			printf("Previous = %d\n", current);
			return ;
		}
	}
	printf("%sPASS: %s%s Ops = %d\n", GREEN, name, RESET, ops);
}

void	sort_and_check(char *name, int in[], size_t len, void (f)(t_mst*))
{
	t_mst mst;
	mst.a = _dlst_from_arr(in, len);
	mst.b = NULL;
	mst.l_ops = NULL;

	f(&mst);
	int ops = ft_dlstsize(mst.l_ops);
	is_dlist_sorted(mst.a, name, ops);
	ft_dlstfree(mst.a);
	ft_dlstfree(mst.b);
	ft_dlstfree(mst.l_ops);
}

int	main(void)
{
    printf(BOLD "\nINSERTION SORT\n" RESET);
	sort_and_check("10 elements (rand):", (int[]){7, 10, 5, 9, 1, 0, 4, 8, 3, 2}, 10, &iterative_min_sort);
	sort_and_check("5 elements (worst):", (int[]){5,4,3,2,1}, 5, &iterative_min_sort);
	sort_and_check("5 elements (best):", (int[]){1,2,3,4,5}, 5, &iterative_min_sort);
	sort_and_check("2 elements (worst):", (int[]){2, 1}, 2, &iterative_min_sort);
	sort_and_check("2 elements (best):", (int[]){1, 2}, 2, &iterative_min_sort);
	sort_and_check("1 element:", (int[]){1}, 1, &iterative_min_sort);
    printf(BOLD "\nDIR INSERTION SORT\n" RESET);
	sort_and_check("10 elements (rand):", (int[]){7, 10, 5, 9, 1, 0, 4, 8, 3, 2}, 10, &dir_iterative_min_sort);
	sort_and_check("5 elements (worst):", (int[]){5,4,3,2,1}, 5, &dir_iterative_min_sort);
	sort_and_check("5 elements (best):", (int[]){1,2,3,4,5}, 5, &dir_iterative_min_sort);
	sort_and_check("2 elements (worst):", (int[]){2, 1}, 2, &dir_iterative_min_sort);
	sort_and_check("2 elements (best):", (int[]){1, 2}, 2, &dir_iterative_min_sort);
}
