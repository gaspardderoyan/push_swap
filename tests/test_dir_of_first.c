/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dir_of_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:50:42 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/14 00:56:03 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tests/test_dir_of_first.c
#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

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
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5, 6}));
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 2, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(1, res, __func__);
	ft_dlstfree(lst);
}

void	test_dir_of_first_end(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){6, 5, 4, 3, 2, 1}));
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 2, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(-1, res, __func__);
	ft_dlstfree(lst);
}

void	test_dir_of_first_mid_up(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5, 6}));
    t_stacks_mt mt = { .chunks_i = 2, .chunks_count = 6, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(1, res, __func__);
	ft_dlstfree(lst);
}

void	test_dir_of_first_mid_down(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5, 6}));
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 6, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(-1, res, __func__);
	ft_dlstfree(lst);
}

void	test_dir_of_first_empty(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){}));
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 5, .lst_size = 0 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(0, res, __func__);
	ft_dlstfree(lst);
}

int	main(void)
{
	test_dir_of_first_start();
	test_dir_of_first_end();
	test_dir_of_first_mid_up();
	test_dir_of_first_mid_down();
	test_dir_of_first_empty();
	return (0);
}
