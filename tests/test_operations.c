/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:33:11 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 23:15:36 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"
#include "libft.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD "\033[1m"

// Macro to calculate the size of the array and call the function

// Modified function to create a doubly linked list from an array
static t_dlist *dlst_from_arr(int *arr, size_t size)
{
    t_dlist *new = NULL;
    if (arr == NULL)
        return NULL; // Handle null array input
    for (size_t i = 0; i < size; i++)
        add_nbr_to_lst(&new, arr[i]);
    return new;
}

int	*arr_from_dlist(t_dlist *lst)
{
	int *arr = malloc(sizeof(int) * ft_dlstsize(lst));
	int	i = 0;
	while (lst)
	{
		arr[i++] = *(int *)lst->content;
		lst = lst->next;
	}
	return (arr);	
}

void	compare_arrs(char *name, int in[], int out[], int len, void (f)(t_dlist**, int*))
{
	int	i = 0;

	t_dlist *lst = dlst_from_arr(in, len);
	f(&lst, NULL);
	int	*res = arr_from_dlist(lst);
	while (i < len)
	{
		if (out[i] != res[i])
		{
			printf("%sFAIL: %s%s\n", RED, name, RESET);
			printf("At i=%d, expected %d, got %d\n", i, out[i], res[i]);
			free(res);
			ft_dlstfree(lst);
			return ;
		}
		i++;
	}
	printf("%sPASS: %s%s\n", GREEN, name, RESET);
	ft_dlstfree(lst);
	free(res);
}

int	main(void)
{
    printf(BOLD "\nOPERATIONS\n" RESET);
	compare_arrs("rotate once", ((int[]){1, 2, 3, 4, 5}), ((int[]){2, 3, 4, 5, 1}), 5, &rotate);
	compare_arrs("rotate 2 elements", ((int[]){1, 2}), ((int[]){2, 1}), 2, &rotate);
	compare_arrs("rotate only 1 element", ((int[]){1}), ((int[]){1}), 1, &rotate);
	compare_arrs("reverse once", ((int[]){1, 2, 3, 4, 5}), ((int[]){5, 1, 2, 3, 4}), 5, &reverse);
	compare_arrs("reverse 2 elements", ((int[]){1, 2}), ((int[]){2, 1}), 2, &reverse);
	compare_arrs("reverse only 1 element", ((int[]){1}), ((int[]){1}), 1, &reverse);
	compare_arrs("swap once", ((int[]){1, 2, 3, 4, 5}), ((int[]){2, 1, 3, 4, 5}), 5, &swap_first);
	compare_arrs("swap 2 elements", ((int[]){1, 2}), ((int[]){2, 1}), 2, &swap_first);
	compare_arrs("swap only 1 element", ((int[]){1}), ((int[]){1}), 1, &swap_first);
	return (0);
}
