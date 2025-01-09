// tests/test_dir_of_first.c
#include "../unity/unity.h"
#include "../inc/project.h"
#include <stdio.h>

// ANSI escape codes for colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

// Macro to calculate the size of the array and call the function
#define DLIST_FROM_ARR(arr) _dlst_from_arr(arr, sizeof(arr) / sizeof((arr)[0]))

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

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
        ft_dlstadd_back(&new, ft_dlstnew(&arr[i]));
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
		printf("%sFAIL: %s%s\n", COLOR_RED, func_name, COLOR_RESET);
		printf("  Expected = %d, Actual = %d\n", expected, actual);
		TEST_FAIL();
	}
	else
		printf("%sPASS: %s%s\n", COLOR_GREEN, func_name, COLOR_RESET);
}

void	test_dir_of_first_start(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5, 6}));
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 2, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(1, res, __func__);
}

void	test_dir_of_first_end(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){6, 5, 4, 3, 2, 1}));
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 2, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(-1, res, __func__);
}

void	test_dir_of_first_mid_up(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5, 6}));
    t_stacks_mt mt = { .chunks_i = 2, .chunks_count = 6, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(1, res, __func__);
}

void	test_dir_of_first_mid_down(void)
{
	t_dlist *lst = DLIST_FROM_ARR(((int[]){1, 2, 3, 4, 5, 6}));
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 6, .lst_size = 6 };
	update_mt(&mt);
    list_indexing(&lst, mt.lst_size);
	int	res = dir_of_first(lst, &mt);
	assert_equals_and_print(-1, res, __func__);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_dir_of_first_start);
	RUN_TEST(test_dir_of_first_end);
	RUN_TEST(test_dir_of_first_mid_up);
	RUN_TEST(test_dir_of_first_mid_down);
	return (UNITY_END());
}
