/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dir_of_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:50:42 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/20 19:47:58 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tests/test_dir_of_first.c
#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD "\033[1m"

// Macro to calculate the size of the array and call the function
#define DLIST_FROM_ARR(arr) _dlst_from_arr(arr, sizeof(arr) / sizeof((arr)[0]))

// Modified function to create a doubly linked list from an array
t_dlist *_dlst_from_arr(int *arr, size_t size)
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

// Function to print the list (for testing)
void print_list(t_dlist *lst)
{
    while (lst != NULL)
	{
        printf("%d ", *(int *)(lst->content));
        lst = lst->next;
    }
    printf("\n");
}

void	assert_equals_and_print(int expected, int actual, const char *func_name)
{
	if (expected != actual)
	{
		printf("%sFAIL: %s%s\n", RED, func_name, RESET);
		printf("  Expected = %d, Actual = %d\n", expected, actual);
		return ;
	}
	else
		printf("%sPASS: %s%s\n", GREEN, func_name, RESET);
}

void	test_dir_of_first_start(void)
{
	t_mst mst;
	mst.a = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5, 6}));
	mst.b = NULL;
    list_indexing(&mst, 5);
	update_stacks_mt(&mst.mt);
	int	res = dir_of_first(mst.a, &mst.mt);
	assert_equals_and_print(1, res, __func__);
	ft_dlstfree(mst.a);
}

void	test_dir_of_first_end(void)
{
	t_mst mst;
	mst.a = DLIST_FROM_ARR(((int[]){6, 5, 4, 3, 2, 1}));	mst.b = NULL;
	mst.b = NULL;
    list_indexing(&mst, 5);
	update_stacks_mt(&mst.mt);
	int	res = dir_of_first(mst.a, &mst.mt);
	assert_equals_and_print(-1, res, __func__);
	ft_dlstfree(mst.a);
}

void	test_dir_of_first_mid_up(void)
{
	t_mst mst;
	mst.a = DLIST_FROM_ARR(((int[]){6, 2, 1, 3, 5, 4}));;
	mst.b = NULL;
    list_indexing(&mst, 5);
	update_stacks_mt(&mst.mt);
	int	res = dir_of_first(mst.a, &mst.mt);
	assert_equals_and_print(1, res, __func__);
	ft_dlstfree(mst.a);
}

void	test_dir_of_first_mid_down(void)
{
	t_mst mst;
	mst.a = DLIST_FROM_ARR(((int[]){6, 2, 3, 1, 5, 4}));;
	mst.b = NULL;
    list_indexing(&mst, 6);
	update_stacks_mt(&mst.mt);
	int	res = dir_of_first(mst.a, &mst.mt);
	assert_equals_and_print(-1, res, __func__);
	ft_dlstfree(mst.a);
}

void	test_dir_of_first_empty(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){}));
	t_mst mst;
	mst.a = lst;
	mst.b = NULL;
    list_indexing(&mst, 5);
	update_stacks_mt(&mst.mt);
	int	res = dir_of_first(lst, &mst.mt);
	assert_equals_and_print(-1, res, __func__);
	ft_dlstfree(lst);
}

int	main(void)
{
    printf(BOLD "\nDIR_OF_FIRST\n" RESET);
	test_dir_of_first_start();
	test_dir_of_first_end();
	test_dir_of_first_mid_up();
	test_dir_of_first_mid_down();
	test_dir_of_first_empty();
	return (0);
}
