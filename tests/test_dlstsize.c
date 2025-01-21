#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD	"\033[1m"

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

void	test_ft_dlstsize_empty(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){}));
	int	res = ft_dlstsize(lst);
	assert_equals_and_print(0, res, __func__);
	ft_dlstfree(lst);
}

void	test_ft_dlstsize_one(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1}));
	int	res = ft_dlstsize(lst);
	assert_equals_and_print(1, res, __func__);
	ft_dlstfree(lst);
}

void	test_ft_dlstsize_two(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2}));
	int	res = ft_dlstsize(lst);
	assert_equals_and_print(2, res, __func__);
	ft_dlstfree(lst);
}

void	test_ft_dlstsize_three(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3}));
	int	res = ft_dlstsize(lst);
	assert_equals_and_print(3, res, __func__);
	ft_dlstfree(lst);
}

void	test_ft_dlstsize_four(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4}));
	int	res = ft_dlstsize(lst);
	assert_equals_and_print(4, res, __func__);
	ft_dlstfree(lst);
}

void	test_ft_dlstsize_five(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5}));
	int	res = ft_dlstsize(lst);
	assert_equals_and_print(5, res, __func__);
	ft_dlstfree(lst);
}

int	main(void)
{
    printf(BOLD "\nFT_DLSTSIZE\n" RESET);
	test_ft_dlstsize_empty();
	test_ft_dlstsize_one();
	test_ft_dlstsize_two();
	test_ft_dlstsize_three();
	test_ft_dlstsize_four();
	test_ft_dlstsize_five();
	return (0);
}
